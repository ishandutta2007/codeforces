#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		k=abs(n-m);
		if(max({n,m,d})>k*2)
		{
			z=-1;
		}
		else
		{
			z=(d+k-1)%(k*2)+1;
		}
		printf("%lld\n",z);
	}
}