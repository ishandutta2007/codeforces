#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200007],p[200007];
int main(int argc, char** argv) 
{
	int t,n,k,sum=0,sum1=0,zs;
	scanf("%d%d%d",&n,&t,&k);
	for(int i=0;i<t;i++) 
	{
	    scanf("%d",&a[i]);
	    sum1+=a[i]-1;
	}
	sum1++;
	p[0]=0;
	for(int i=1;i<=t;i++) p[i]=p[i-1]+a[i-1];
	for(int i=1;i<t+1;i++) sum+=max(a[i-1]-a[i],0);
	if(sum>k||sum1<k)
	{
		printf("-1");
		return 0;
	}
	printf("%d\n",n);
	zs=k-sum;
	for(int i=2;i<p[1]+2;i++) printf("1 %d\n",i);
	for(int i=1;i<t;i++)
	{
		if(a[i]<a[i-1])
		{
		if(a[i]-1<=zs) 
		{
		    for(int j=p[i]+2;j<p[i+1]+2;j++) printf("%d %d\n",p[i-1]+2,j);
		    zs-=(a[i]-1);
		}
		else
		{
			for(int j=p[i]+2;j<p[i]+2+zs;j++) printf("%d %d\n",p[i-1]+2,j);
			for(int j=p[i]+2+zs;j<p[i+1]+2;j++) printf("%d %d\n",p[i-1]+j-p[i]-zs,j);
			zs=0;
		}
	    }
	    else
	    {
	    	if(a[i-1]-1<=zs) 
		{
		    for(int j=p[i]+2;j<p[i+1]+2;j++) printf("%d %d\n",p[i-1]+2,j);
		    zs-=(a[i-1]-1);
		}
		else
		{
			if(zs==0)
			{
				for(int j=p[i]+2;j<p[i]+2+a[i]-a[i-1];j++) printf("%d %d\n",p[i-1]+2,j);
			    for(int j=p[i]+2+a[i]-a[i-1];j<p[i+1]+2;j++) printf("%d %d\n",p[i-1]+j-p[i]-a[i]+a[i-1],j);
			}
			else
			{
				for(int j=p[i]+2;j<p[i]+2+a[i-1]-zs;j++) printf("%d %d\n",p[i-1]+j-p[i],j);
				for(int j=p[i]+2+a[i-1]-zs;j<p[i+1]+2;j++) printf("%d %d\n",p[i-1]+2,j);
			    zs=0;
			}
		}
		}
	}
	return 0;
}