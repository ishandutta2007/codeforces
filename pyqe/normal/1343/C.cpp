#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long t,rr,i,k,l,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		mx=-inf;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(i&&k/abs(k)!=l/abs(l))
			{
				z+=mx;
				mx=-inf;
			}
			mx=max(mx,k);
			l=k;
		}
		z+=mx;
		printf("%lld\n",z);
	}
}