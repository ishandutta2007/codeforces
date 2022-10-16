#include <bits/stdc++.h>

using namespace std;

long long n,sq[1069],zs=0;

int main()
{
	long long i,j,k;
	bool bad;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		bad=0;
		for(j=0;j<n;j++)
		{
			scanf("%lld",&k);
			bad|=(k+1)&&(k&1);
		}
		if(!bad)
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