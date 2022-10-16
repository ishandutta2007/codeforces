#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],inf=1e18;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		z=inf;
		for(i=2;i<=n;i++)
		{
			z=min(z,a[i]-a[i-1]);
		}
		printf("%lld\n",z);
	}
}