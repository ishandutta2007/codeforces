#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[100069],ps[100069];

int main()
{
	long long t,rr,i,c,c2,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ps[i]=ps[i-1]+a[i];
		}
		z=inf;
		for(i=0;i<=n;i++)
		{
			c=ps[i];
			c2=n-i-(ps[n]-ps[i]);
			z=min(z,max(c,c2));
		}
		printf("%lld\n",z);
	}
}