#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[4069],co[4069],vo[4069],d[4069],sq[4069],zs=0;
bitset<4069> vtd;

int main()
{
	long long i,sm;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",vo+i,d+i,co+i);
		a[i]=i;
	}
	for(nn=n;nn;)
	{
		zs++;
		sq[zs]=a[1];
		vtd[a[1]]=1;
		sm=0;
		for(i=2;i<=nn;i++)
		{
			co[a[i]]-=max(vo[a[1]]-i+2,0ll)+sm;
			if(co[a[i]]<0)
			{
				vtd[a[i]]=1;
				sm+=d[a[i]];
			}
		}
		nn=0;
		for(i=1;i<=n;i++)
		{
			if(!vtd[i])
			{
				nn++;
				a[nn]=i;
			}
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}