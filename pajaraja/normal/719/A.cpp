#include <iostream>
#include <stdio.h>
int main(int argc, char** argv) 
{
	int n;
	scanf("%d",&n);
	int a[100];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	if(n==1) 
	{
		if(a[0]==0) printf("UP");
		if(a[0]==15) printf("DOWN");
		if(a[0]>0&&a[0]<15) printf("-1");
		return 0;
	}
	if((a[n-1]-a[n-2]==1&&a[n-1]!=15)||a[n-1]==0)
	{
		printf("UP");
		return 0;
	}
	printf("DOWN");
	return 0;
}