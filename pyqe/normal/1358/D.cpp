#include <bits/stdc++.h>

using namespace std;

long long n,d,a[400069],ps[400069],ps2[400069],inf=1e18;

long long cal(long long x)
{
	long long k=lower_bound(ps+1,ps+n*2+1,x)-ps-1;
	
	return ps2[k]+(x-ps[k])*(x-ps[k]+1)/2;
}

int main()
{
	long long i,z=-inf;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n*2;i++)
	{
		if(i<=n)
		{
			scanf("%lld",a+i);
		}
		else
		{
			a[i]=a[i-n];
		}
		ps[i]=ps[i-1]+a[i];
		ps2[i]=ps2[i-1]+a[i]*(a[i]+1)/2;
	}
	for(i=1;i<=n;i++)
	{
		z=max(z,max(cal(ps[n+i])-cal(ps[n+i]-d),cal(ps[i]+d-1)-cal(ps[i]-1)));
	}
	printf("%lld\n",z);
}