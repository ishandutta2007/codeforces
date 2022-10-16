#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],ps[100069];

int main()
{
	long long i,ttl=0,lh,rh,md,z,mn,k,p;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i];
	}
	a[0]=-4e9;
	a[n+1]=4e9;
	lh=0;
	rh=2e9;
	for(;lh<=rh;)
	{
		md=(lh+rh)/2;
		mn=1e18;
		for(i=1;i<=n;i++)
		{
			p=upper_bound(a,a+n+2,a[i]+md)-a;
			k=a[i]*i-ps[i]+ttl-ps[p-1]-(a[i]+md)*(n+1-p);
			mn=min(mn,k);
		}
		for(i=1;i<=n;i++)
		{
			p=lower_bound(a,a+n+2,a[i]-md)-a-1;
			k=(a[i]-md)*p-ps[p]+ttl-ps[i-1]-a[i]*(n+1-i);
			mn=min(mn,k);
		}
		if(mn<=d)
		{
			z=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",z);
}