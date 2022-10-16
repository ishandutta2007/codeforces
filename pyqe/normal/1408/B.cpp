#include <bits/stdc++.h>

using namespace std;

long long n,d,inf=1e18;

int main()
{
	long long t,rr,i,k,l,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		d--;
		l=inf;
		c=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(k>l)
			{
				c++;
			}
			l=k;
		}
		if(!d&&c)
		{
			z=-1;
		}
		else
		{
			d+=!d;
			z=max((c+d-1)/d,1ll);
		}
		printf("%lld\n",z);
	}
}