#include<stdio.h>

int main(void){
	int n,r;
	scanf("%d",&n);
	if(n == 0){r = 1;}
	else if(n%4 == 1){r = 8;}
	else if(n%4 == 2){r = 4;}
	else if(n%4 == 3){r = 2;}
	else{r = 6;}
	printf("%d\n",r);
	return 0;
}