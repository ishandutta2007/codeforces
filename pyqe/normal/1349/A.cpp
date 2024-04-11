#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],ps[2][100069];

int main()
{
	long long i,ii,u,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			ps[ii][i]=__gcd(ps[ii][i-u],a[i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		k=__gcd(ps[0][i-1],ps[1][i+1]);
		z=__gcd(z,a[i]/__gcd(a[i],k)*k);
	}
	printf("%lld\n",z);
}