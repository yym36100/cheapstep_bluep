#pragma once

#include "stm32f1xx_hal.h"
#include <stdint.h>
#include <stdio.h>
//#include "spi.h"
extern SPI_HandleTypeDef hspi1;
//#include "tim.h"
extern TIM_HandleTypeDef htim3;
#include "Debug.h"
#include "main.h"

#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t

/* GPIO config */
#define DEV_RST_PIN     RST_GPIO_Port,RST_Pin
#define DEV_DC_PIN      DC_GPIO_Port,DC_Pin
#define DEV_CS_PIN		CS_GPIO_Port,CS_Pin
#define DEV_BL_PIN		TIM3->CCR2

/* GPIO read and write */
#define DEV_Digital_Write(_pin, _value) HAL_GPIO_WritePin(_pin, _value == 0? GPIO_PIN_RESET:GPIO_PIN_SET)
#define DEV_Digital_Read(_pin) 	HAL_GPIO_ReadPin(_pin)

#define DEV_SPI_WRITE(_dat)  	DEV_SPI_WRite(_dat);
#define DEV_Delay_ms(__xms) 	HAL_Delay(__xms)
#define DEV_Set_PWM(_Value)     DEV_BL_PIN= _Value

void DEV_SPI_WRite(UBYTE _dat);
int DEV_Module_Init(void);
void DEV_Module_Exit(void);
