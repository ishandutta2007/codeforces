#include <bits/stdc++.h>

using namespace std;

const long long ma=2e6;
long long n,d,a[100069];

int main()
{
	long long i,k,lh,rh,md,zz,sm,zm,z=0;
	
	scanf("%lld%lld%lld",&n,&d,&k);
	d+=k;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=abs(a[i]-k);
	}
	sort(a+1,a+n+1,greater<long long>());
	for(lh=0,rh=ma;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		for(i=1;i<=n;i++)
		{
			sm+=max(a[i]-md,0ll);
		}
		if(sm<=d)
		{
			zz=md;
			zm=sm;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	for(i=1;i<=n;i++)
	{
		a[i]=min(a[i],zz);
	}
	if(zz)
	{
		for(i=1;i<=d-zm;i++)
		{
			a[i]--;
		}
	}
	else
	{
		a[1]+=(d-zm)%2;
	}
	for(i=1;i<=n;i++)
	{
		z+=a[i]*a[i];
	}
	printf("%lld\n",z);
}