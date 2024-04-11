#include <bits/stdc++.h>

using namespace std;

long long n,ttl=0,a[2][5069];

int main()
{
	long long i,j,ii,sm,p,z;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		ttl+=a[0][i]*a[1][i];
	}
	z=ttl;
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			sm=ttl;
			for(j=i-1;j&&i+i-j-ii<=n;j--)
			{
				p=i+i-j-ii;
				sm+=a[0][j]*a[1][p]+a[0][p]*a[1][j]-a[0][j]*a[1][j]-a[0][p]*a[1][p];
				z=max(z,sm);
			}
		}
	}
	printf("%lld\n",z);
}