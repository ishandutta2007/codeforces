#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) 
{
	int a[3],x,cur=0;
	scanf("%d%d",&x,&a[0]);
	a[2]=a[1]=a[0];
	while(true)
	{
		sort(a,a+3);
		if(a[1]+a[2]>x)
		{
			printf("%d",cur+3);
			return 0;
		}
		a[0]=a[2]+a[1]-1;
		cur++;
	}
}