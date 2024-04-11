#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],ps[100069],inf=1e9;

int main()
{
	long long i,k,sm,lh,rh,md,zz;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i];
	}
	for(lh=a[n],rh=inf;lh<=rh;)
	{
		md=(lh+rh)/2;
		k=upper_bound(a+1,a+n+1,md)-a-1;
		sm=md*k-ps[k];
		if(sm>=m)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld %lld\n",zz,a[n]+m);
}