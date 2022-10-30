#include <iostream>
#include <stdio.h>
bool isleap(int n)
{
	return (n%400==0||(n%4==0&&n%100!=0));
}
int main(int argc, char** argv) 
{
	int n,d=0;
	scanf("%d",&n);
	bool found=false,p,l;
	l=isleap(n);
	while(!found)
	{
		p=isleap(n);
		n++;
		if(p) d=(d+2)%7;
		else d=(d+1)%7;
		if(l==isleap(n)&&d==0)
		{
			found=true;
			printf("%d",n);
		} 
	}
	return 0;
}