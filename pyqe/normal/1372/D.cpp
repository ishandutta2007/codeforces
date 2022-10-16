#include <bits/stdc++.h>

using namespace std;

long long n,ttl=0,a[400069],ps[400069],inf=1e18;

int main()
{
	long long i,mn=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
	}
	for(i=n+1;i<=n*2;i++)
	{
		a[i]=a[i-n];
	}
	for(i=1;i<=n*2;i++)
	{
		ps[i]=a[i];
		if(i>=2)
		{
			ps[i]+=ps[i-2];
		}
	}
	for(i=n;i<=n*2;i++)
	{
		mn=min(mn,ps[i]-ps[i-n+1]);
	}
	printf("%lld\n",ttl-mn);
}