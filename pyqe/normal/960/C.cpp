#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[10069],zs=0;

int main()
{
	long long i,j,p=1;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;(1ll<<i+1)-1<=n;i++);
	for(;n;i--)
	{
		for(;n>=(1ll<<i)-1;n-=(1ll<<i)-1)
		{
			for(j=0;j<i;j++)
			{
				zs++;
				sq[zs]=p;
			}
			p+=d;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}