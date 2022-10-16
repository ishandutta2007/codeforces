#include <bits/stdc++.h>

using namespace std;

long long n,a[150069];

int main()
{
	long long t,rr,i,mn,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		mn=1e18;
		z=0;
		for(i=n;i;i--)
		{
			z+=a[i]>mn;
			mn=min(mn,a[i]);
		}
		printf("%lld\n",z);
	}
}