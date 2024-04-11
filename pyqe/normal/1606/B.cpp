#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,c,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		c=1;
		sm=1;
		z=0;
		for(;c<n&&sm<d;)
		{
			z++;
			c=min(c+sm,n);
			sm=min(c,d);
		}
		z+=(n-c+d-1)/d;
		printf("%lld\n",z);
	}
}