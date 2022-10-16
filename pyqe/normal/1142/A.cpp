#include <bits/stdc++.h>

using namespace std;

long long n,m,st,d;

int main()
{
	long long i,ii,k,gd,z,mn=1e18,mx=-1e18;
	
	scanf("%lld%lld%lld%lld",&n,&m,&st,&d);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			k=i*m+d*(ii*2-1)-st;
			gd=__gcd(k,n*m);
			z=n*m/gd;
			mn=min(mn,z);
			mx=max(mx,z);
		}
	}
	printf("%lld %lld\n",mn,mx);
}