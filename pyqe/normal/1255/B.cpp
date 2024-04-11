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
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			z+=k*2;
		}
		if(d<n||n==2)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",z);
			for(i=1;i<=n;i++)
			{
				printf("%lld %lld\n",i,i%n+1);
			}
		}
	}
}