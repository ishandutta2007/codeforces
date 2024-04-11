#include <bits/stdc++.h>

using namespace std;

long long n,m,inf=1e18;

int main()
{
	long long i,k,l,sm=0,z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sm+=k;
	}
	scanf("%lld",&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(sm<=l)
		{
			z=min(z,max(k,sm));
		}
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}