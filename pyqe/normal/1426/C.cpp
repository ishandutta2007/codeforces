#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=inf;
		for(i=1;i*i<=n;i++)
		{
			z=min(z,i-1+(n+i-1)/i-1);
		}
		printf("%lld\n",z);
	}
}