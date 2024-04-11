#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,c,mn,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		mn=n+1;
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(!!k)
			{
				c++;
				mn=min(mn,i);
				mx=i;
			}
		}
		if(!c)
		{
			z=0;
		}
		else if(mx-mn+1==c)
		{
			z=1;
		}
		else
		{
			z=2;
		}
		printf("%lld\n",z);
	}
}