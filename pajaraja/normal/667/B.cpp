#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int a,t;
	scanf("%d",&a);
	int b[a];
	int s=0,max=0;
	for(int i=0;i<a;i++)
	{
		scanf("%d",&b[i]);
		max=max>b[i]?max:b[i];
		s+=b[i];
	}
	t=max-(s-max)+1;
	printf("%d",t);
	return 0;
}