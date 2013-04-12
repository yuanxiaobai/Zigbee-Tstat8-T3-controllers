/**************************************************************************************************
  Filename:       sb_exec.h
  Revised:        $Date: 2010-03-10 20:36:55 -0800 (Wed, 10 Mar 2010) $
  Revision:       $Revision: 21890 $

  Description:    Serial Bootloader Executive.

  Copyright 2009-2010 Texas Instruments Incorporated. All rights reserved.

  IMPORTANT: Your use of this Software is limited to those specific rights
  granted under the terms of a software license agreement between the user
  who downloaded the software, his/her employer (which must be your employer)
  and Texas Instruments Incorporated (the "License").  You may not use this
  Software unless you agree to abide by the terms of the License. The License
  limits your use, and you acknowledge, that the Software may not be modified,
  copied or distributed unless embedded on a Texas Instruments microcontroller
  or used solely and exclusively in conjunction with a Texas Instruments radio
  frequency transceiver, which is integrated into your product.  Other than for
  the foregoing purpose, you may not use, reproduce, copy, prepare derivative
  works of, modify, distribute, perform, display or sell this Software and/or
  its documentation for any purpose.

  YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
  PROVIDED 揂S IS?WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, 
  INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, 
  NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
  TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
  NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
  LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
  INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
  OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
  OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
  (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

  Should you have any questions regarding your right to use this Software,
  contact Texas Instruments Incorporated at www.TI.com. 
**************************************************************************************************/
#ifndef SB_EXEC_H
#define SB_EXEC_H

/* ------------------------------------------------------------------------------------------------
 *                                          Includes 
 * ------------------------------------------------------------------------------------------------
 */

#include "hal_types.h"

/* ------------------------------------------------------------------------------------------------
 *                                          Constants
 * ------------------------------------------------------------------------------------------------
 */

#define SB_IMG_OSET                 (HAL_SB_IMG_ADDR / HAL_FLASH_WORD_SIZE)
// The write-page boundary since the write-address is passed as "actual address / flash word size".
#define SB_WPG_SIZE                 (HAL_FLASH_PAGE_SIZE / HAL_FLASH_WORD_SIZE)

// 改为ISP所需长度
#define SB_BUF_SIZE                 144
#define SB_SOF                      0xFE
#define SB_HANDSHAKE                0xFE

#define SB_FORCE_BOOT               0xF8
#define SB_FORCE_RUN               (SB_FORCE_BOOT ^ 0xFF)

// 改为符合ISP的128个字节
#define SB_RW_BUF_LEN               128

// Bootloader Serial Interface Subsystem
#define SB_RPC_SYS_BOOT             0x4D

// Commands to Bootloader
#define SB_WRITE_CMD                0x10
#define SB_READ_CMD                 0x03
#define SB_ENABLE_CMD               0x06
#define SB_HANDSHAKE_CMD            0x04

// Status codes
#define SB_SUCCESS                  0
#define SB_FAILURE                  1
#define SB_INVALID_FCS              2
#define SB_INVALID_FILE             3
#define SB_FILESYSTEM_ERROR         4
#define SB_ALREADY_STARTED          5
#define SB_NO_RESPOSNE              6
#define SB_VALIDATE_FAILED          7
#define SB_CANCELED                 8

// Serial RX States
#define SB_SOF_STATE                0
#define SB_LEN_STATE                1
#define SB_CMD1_STATE               2
#define SB_CMD2_STATE               3
#define SB_MODBUS_LEN_1             4
#define SB_MODBUS_LEN_2             5
#define SB_UNKNOWN_BYTE             6
#define SB_DATA_STATE               7
#define SB_FCS_STATE_1              8
#define SB_FCS_STATE_2              9

/* ------------------------------------------------------------------------------------------------
 *                                          Functions
 * ------------------------------------------------------------------------------------------------
 */

/**************************************************************************************************
 * @fn          sbExec
 *
 * @brief       Boot Loader main executive processing.
 *
 * input parameters
 *
 * None.
 *
 * output parameters
 *
 * None.
 *
 * @return      TRUE if sbCmnd() returns TRUE, indicating that an SB_ENABLE_CMD succeeded;
 *              FALSE otherwise.
 **************************************************************************************************
 */
uint8 sbExec(void);

/**************************************************************************************************
 * @fn          sbImgValid
 *
 * @brief       Check validity of the run-code image.
 *
 * input parameters
 *
 * None.
 *
 * output parameters
 *
 * None.
 *
 * @return      TRUE or FALSE for image valid.
 **************************************************************************************************
 */
uint8 sbImgValid(void);

#endif
