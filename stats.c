/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief  A statistical analysis application
 *
 * This is an applcation to analyze an array of integers and report the minimum, maximum, mean, median of the data.
 *
 * @author Salim Abdullahi Usman
 * @date 8th January, 2024
 *
 */



 #include <stdio.h>
 #include "stats.h"

 /* Size of the Data Set */
 #define SIZE (40)
 int mean,median,mode,maximum,minimum;

 int main() {
   int test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
   /* Other Variable Declarations Go Here */

   /* Statistics and Printing Functions Go Here */
   print_array(test,SIZE);
   find_median(test,&median);
   find_mean(test,&mean);
   find_maximum(test,&maximum);
   find_minimum(test,&minimum);
   sort_array(test);
   print_statistics(test);
   return 0;
 }

 void print_statistics(int test[]){
   printf("\nMean : %d\n",mean);
   printf("Median : %d\n",median);
   printf("Max : %d\n",maximum);
   printf("Min : %d\n",minimum);
 }

 void print_array(int test[],int n){
   int i;
   printf("Array : ");
   for(i=0;i<SIZE;i++){
     printf("%d ", test[i]);
   }
 }

 void find_median(int test[],int *median){
   *median = test[SIZE/2];
 }
 void find_mean(int test[],int *mean){
   int i,sum = 0;
   for(i=0;i<SIZE;i++){
     sum +=test[i];
   }
   *mean = sum/SIZE;
 }

 void find_maximum(int test[],int *maximum){
   int i;
   *maximum = test[0];
   for(i=1;i<SIZE;i++){
     if(test[i]>*maximum){
       *maximum = test[i];
     }
   }
 }

 void find_minimum(int test[],int *minimum){
   int i;
   *minimum = test[0];
   for(i=1;i<SIZE;i++){
     if(test[i]<*minimum){
       *minimum = test[i];
     }
   }
 }

 void sort_array(int test[]){
   int i,j,a;
   for(i=0;i<SIZE;i++){
     for(j=i+1;j<SIZE;j++){
       if(test[i]>test[j]){
         a = test[i];
         test[i]=test[j];
         test[j]=a;
       }
     }
   }
   printf("\nSorted array : ");
  for(i=0;i<SIZE;i++){
    printf("%d ",test[i]);
  }
 }

/* Add other Implementation File Code Here */
