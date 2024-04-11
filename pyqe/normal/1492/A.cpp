#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=inf;
		for(i=0;i<3;i++)
		{
			scanf("%lld",&k);
			z=min(z,((n-1)/k+1)*k-n);
		}
		printf("%lld\n",z);
	}
}