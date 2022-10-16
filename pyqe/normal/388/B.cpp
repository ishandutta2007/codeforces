#include <bits/stdc++.h>

using namespace std;

long long n,zs=2;
bitset<1069> sq[1069];

int main()
{
	long long i,j,r,ti,tj;
	
	scanf("%lld",&n);
	for(i=0;i<30;i++)
	{
		for(j=1;j<=1+!!i;j++)
		{
			for(r=1;r<=2;r++)
			{
				sq[zs-2+j][zs+r]=1;
			}
		}
		zs+=2;
	}
	for(i=0;i<30;i++)
	{
		if(n>>i&1)
		{
			sq[3+i*2][zs+1]=1;
		}
		if(i)
		{
			sq[zs][zs+1]=1;
		}
		zs++;
	}
	sq[2][zs]=1;
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		for(j=1;j<=zs;j++)
		{
			ti=i;
			tj=j;
			if(ti>tj)
			{
				swap(ti,tj);
			}
			printf("%c","NY"[sq[ti][tj]]);
		}
		printf("\n");
	}
}