#include <bits/stdc++.h>

using namespace std;

long long n,d,a[500069],ps[500069],inf=1e18;

int main()
{
	long long i,sm=0,sm2=0,z=-inf;
	
	scanf("%lld%lld",&n,&d);
	d++;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+a[i]*((i-1)/d);
	}
	for(i=n;i;i--)
	{
		z=max(z,sm2+sm*((i-1)/d)+ps[i]);
		sm+=a[i];
		sm2+=sm;
	}
	printf("%lld\n",z);
}