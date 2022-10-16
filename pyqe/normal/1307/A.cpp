#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(i-1)
			{
				w=d/(i-1);
			}
			else
			{
				w=1e18;
			}
			w=min(w,k);
			z+=w;
			d-=w*(i-1);
		}
		printf("%lld\n",z);
	}
}