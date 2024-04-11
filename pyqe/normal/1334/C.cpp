#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],wg[300069],inf=1e18;

int main()
{
	long long t,rr,i,k,mn,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld",a+i,wg+i);
		}
		mn=inf;
		z=0;
		for(i=0;i<n;i++)
		{
			k=max(a[i]-wg[(i+n-1)%n],0ll);
			mn=min(mn,a[i]-k);
			z+=k;
		}
		z+=mn;
		printf("%lld\n",z);
	}
}