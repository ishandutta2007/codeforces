#include <bits/stdc++.h>

using namespace std;

long long ln,n,inf=1e18;

int main()
{
	long long t,rr,i,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ln,&n);
		z=-inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(i==1)
			{
				z=max(z,k);
			}
			else
			{
				z=max(z,(k-l)/2+1);
			}
			if(i==n)
			{
				z=max(z,ln+1-k);
			}
			l=k;
		}
		printf("%lld\n",z);
	}
}