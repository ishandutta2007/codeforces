#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		z=1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			c+=k==1;
			z*=1+!k;
		}
		printf("%lld\n",z*c);
	}
}