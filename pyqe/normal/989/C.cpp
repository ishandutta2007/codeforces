#include <bits/stdc++.h>

using namespace std;

long long n=50,a[4],sq[50][50];

int main()
{
	long long i,j,c[2]={0,0},y,x;
	
	for(i=0;i<4;i++)
	{
		scanf("%lld",a+i);
		a[i]-=i<2;
	}
	for(i=n/2;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sq[i][j]=1;
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<a[i];j++)
		{
			y=c[!i]/(n/2)*2+1+n/2*!i;
			x=c[!i]%(n/2)*2+1;
			sq[y][x]=i;
			c[!i]++;
		}
	}
	printf("%lld %lld\n",n,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c",(char)sq[i][j]+'A');
		}
		printf("\n");
	}
}