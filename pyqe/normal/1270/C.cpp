#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l,sm,xr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		xr=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			xr^=k*2;
		}
		printf("3\n");
		k=(1ll<<58)+sm%2;
		sm+=k;
		xr^=k*2;
		l=(xr-sm)/2;
		printf("%lld %lld %lld\n",k,l,l);
	}
}