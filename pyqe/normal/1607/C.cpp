#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[200069];

int main()
{
	long long t,rr,i,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		z=-inf;
		sm=0;
		for(i=1;i<=n;i++)
		{
			z=max(z,a[i]+sm);
			sm-=a[i]+sm;
		}
		printf("%lld\n",z);
	}
}