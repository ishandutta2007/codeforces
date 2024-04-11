#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[100069],zs=0;
bitset<100069> spc;

int main()
{
	long long i,k,gd=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		gd=__gcd(gd,k%d);
	}
	for(k=0;!spc[k];k=(k+gd)%d)
	{
		spc[k]=1;
	}
	for(i=0;i<d;i++)
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