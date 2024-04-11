#include <bits/stdc++.h>

using namespace std;

long long n,sq[100069],zs=0;
bitset<100069> spc;

int main()
{
	long long i,ml=1;
	
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		if(__gcd(i,n)==1)
		{
			ml=ml*i%n;
			spc[i]=1;
		}
	}
	if(ml-1)
	{
		spc[ml]=0;
	}
	for(i=1;i<n;i++)
	{
		if(spc[i])
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}