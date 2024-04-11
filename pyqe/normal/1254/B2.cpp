#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],ttl=0,zs=0;
vector<long long> fz;

int main()
{
	long long i,j,k,mn=1e18,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
	}
	for(i=2;i*i<=ttl;i++)
	{
		if(ttl%i==0)
		{
			for(;ttl%i==0;ttl/=i);
			fz.push_back(i);
			zs++;
		}
	}
	if(ttl>1)
	{
		fz.push_back(ttl);
		zs++;
	}
	for(i=0;i<zs;i++)
	{
		z=0;
		k=0;
		for(j=1;j<=n;j++)
		{
			z+=min(k,fz[i]-k);
			k=(k+a[j])%fz[i];
		}
		mn=min(mn,z);
	}
	if(mn==1000000000000000000)
	{
		mn=-1;
	}
	printf("%lld\n",mn);
}