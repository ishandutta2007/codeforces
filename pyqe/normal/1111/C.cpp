#include <bits/stdc++.h>

using namespace std;

long long dn,n,m,d1,d2,a[100069];

long long bf(long long lh,long long rh)
{
	long long k,md=(lh+rh)/2,z;
	
	k=upper_bound(a+1,a+m+1,rh)-lower_bound(a+1,a+m+1,lh);
	if(!k)
	{
		z=d1;
	}
	else
	{
		z=d2*k*(rh-lh+1);
		if(lh<rh)
		{
			z=min(z,bf(lh,md)+bf(md+1,rh));
		}
	}
	return z;
}

int main()
{
	long long i;
	
	scanf("%lld%lld%lld%lld",&dn,&m,&d1,&d2);
	n=1<<dn;
	for(i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+m+1);
	printf("%lld\n",bf(1,n));
}