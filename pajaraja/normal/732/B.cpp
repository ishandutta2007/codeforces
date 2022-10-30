#include <iostream>
#include <stdio.h>
#include <math.h>
int a[1000];
int main(int argc, char** argv) 
{
	int n,k,r=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=a[n+1]=k;
	for(int i=1;i<=n;i++)
	{
		r-=fmin(a[i]+a[i-1]-k,0);
		a[i]-=fmin(a[i]+a[i-1]-k,0);
	}
	printf("%d\n",r);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}