#include <bits/stdc++.h>

using namespace std;

long long n,mx[2],mn[2];

int main()
{
	long long i,ii,k,l,z=0;
	
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",&n);
		mx[ii]=-1e18;
		mn[ii]=1e18;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",&k,&l);
			mx[ii]=max(mx[ii],k);
			mn[ii]=min(mn[ii],l);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		z=max(z,mx[ii]-mn[!ii]);
	}
	printf("%lld\n",z);
}