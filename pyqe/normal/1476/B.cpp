#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=0;
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(i-1)
			{
				z=max(z,(k*100-1)/d+1-sm);
			}
			sm+=k;
		}
		printf("%lld\n",z);
	}
}