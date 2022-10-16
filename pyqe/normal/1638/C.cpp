#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mx=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			mx=max(mx,k);
			z+=mx==i;
		}
		printf("%lld\n",z);
	}
}