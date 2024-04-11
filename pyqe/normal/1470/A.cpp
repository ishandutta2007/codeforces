#include <bits/stdc++.h>

using namespace std;

long long n,m,a[300069],wg[300069];

int main()
{
	long long t,rr,i,z=0;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1,greater<long long>());
		for(i=1;i<=m;i++)
		{
			scanf("%lld",wg+i);
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=wg[min(i,a[i])];
		}
		printf("%lld\n",z);
	}
}