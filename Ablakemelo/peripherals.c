/******************************************************************************
* Include files
******************************************************************************/
#include "peripherals.h"
#include <avr/io.h>
/******************************************************************************
* Macros
******************************************************************************/


/******************************************************************************
* Constants
******************************************************************************/


/******************************************************************************
* Global Variables
******************************************************************************/


/******************************************************************************
* External Variables
******************************************************************************/


/******************************************************************************
* Local Function Declarations
******************************************************************************/


/******************************************************************************
* Local Function Definitions
******************************************************************************/


/******************************************************************************
* Global Function Definitions
******************************************************************************/
/******************************************************************************
* Function:         void timer_init(void)
* Description:      timer inicializ�l�sa
* Input:
* Output:
* Notes:			10 ms, CTC
******************************************************************************/
void timer0_init(void)
{
	TCCR0A = (0<<WGM00) | (1<<WGM01) | (1<<CS02) | (0<<CS01) | (1<<CS00);
	OCR0A = 77; //vagy 30?
	TIMSK0 = (1<<OCIE0A);
}

void timer2_init(void)
{
	TCCR2A = (1<<WGM20) | (0<<WGM21) | (0<<CS22) | (1<<CS21) | (1<<CS20) | (0<<COM2A0) | (1<<COM2A1);
	OCR2A = 0;
}

/******************************************************************************
* Function:         void external_int_init(void)
* Description:      k�ls? megszak�t�s inicializ�l�sa
* Input:
* Output:
* Notes:
******************************************************************************/
void external_int_init(void)
{
	EICRA = (1<<ISC01) | (0<<ISC00);
	EIMSK = (1<<INT0);
}

/******************************************************************************
* Function:         void adc_init(void)
* Description:      ADC konfigur�l�sa
* Input:
* Output:
* Notes:
******************************************************************************/

void adc_init (void)
{
	ADMUX = 0;
	ADCSRA =(1<<ADEN) | (1<<ADSC) | (1<<ADIE) | (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
}