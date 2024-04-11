#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],inf=1e18;

int main()
{
	long long t,rr,i,mn,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		mn=inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			mn=min(mn,a[i]);
		}
		z=-(d-mn)/mn;
		for(i=1;i<=n;i++)
		{
			z+=(d-a[i])/mn;
		}
		printf("%lld\n",z);
	}
}