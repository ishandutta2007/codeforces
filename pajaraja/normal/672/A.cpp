#include <iostream>
#include <stdio.h>
int main(int argc, char** argv) 
{
	int n,m=0,k;
	scanf("%d",&n);
	if(n<10)
	{
		printf("%d",n);
	}
	else
	{
		if(n<=189)
		{
			m=(n-10)/2+10;
			if(n%2==0)
			{
				k=m/10;
				printf("%d",k);
			}
			else
			{
				k=m%10;
			printf("%d",k);	
			}
		}
		else
		{
			m=(n-190)/3+100;
			if(n%3==2)
			{
				k=(m%100)/10;
				printf("%d",k);
			}
			if(n%3==1)
			{
				k=m/100;
			printf("%d",k);	
			}
			if(n%3==0)
			{
				k=m%10;
				printf("%d",k);
			}
		}
	}
	return 0;
}