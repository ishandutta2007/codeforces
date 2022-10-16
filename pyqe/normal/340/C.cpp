#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,sm=0,z=0,dn,gd;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		z+=a[i]+(a[i]*(i-1)-sm)*2;
		sm+=a[i];
	}
	dn=n;
	gd=__gcd(z,dn);
	z/=gd;
	dn/=gd;
	printf("%lld %lld\n",z,dn);
}