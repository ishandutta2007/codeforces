#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			z=max(z,k|d);
		}
		printf("%lld\n",z);
	}
}