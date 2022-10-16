#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,a[200069];

int main()
{
	long long t,rr,i,k,w,sm,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=inf;
		sm=0;
		c=0;
		for(i=1;i<=n;i++)
		{
			if(i<n)
			{
				scanf("%lld",&k);
			}
			z=min(z,c+(max(d-sm,0ll)+a[i]-1)/a[i]);
			w=(max(k-sm,0ll)+a[i]-1)/a[i];
			sm+=a[i]*w-k;
			c+=w+1;
		}
		printf("%lld\n",z);
	}
}