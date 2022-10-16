#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[100069],zs=0;

int main()
{
	long long i,j,k,sz;
	bool bad;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&sz);
		bad=1;
		for(j=0;j<sz;j++)
		{
			scanf("%lld",&k);
			bad&=d<=k;
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