#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],ps[100069];

int main()
{
	long long i,sm=0,mx=0,z=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ps[i]=ps[i-1]+a[i];
	}
	for(i=n;i+1;i--)
	{
		z=max(z,mx-2*ps[i]);
		sm+=-2*a[i];
		mx=max(mx,sm);
	}
	z+=ps[n];
	printf("%lld\n",z);
}