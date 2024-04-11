#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200069],ps[200069];

int main()
{
	long long i,z=1e18;
	
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
	for(i=1;i<=n;i++)
	{
		z=min(z,ps[n]-ps[i]-a[i]*(n-i)+a[i]*i-ps[i]-(n-m));
		if(i>=m)
		{
			z=min(z,a[i]*i-ps[i]-(i-m));
		}
		if(i<=n-m+1)
		{
			z=min(z,ps[n]-ps[i-1]-a[i]*(n-i+1)-(n-i+1-m));
		}
		if(i>=m&&a[i]==a[i-m+1])
		{
			z=min(z,0ll);
		}
	}
	z=max(z,0ll);
	printf("%lld\n",z);
}