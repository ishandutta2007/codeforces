#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,nn,fc[100069];

int main()
{
	long long t,rr,i,mk,sm,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		nn=0;
		fc[0]=1;
		for(;fc[nn]*(nn+1)<=n;)
		{
			nn++;
			fc[nn]=fc[nn-1]*nn;
		}
		d=max(nn-2,0ll);
		z=inf;
		for(mk=0;mk<1ll<<d;mk++)
		{
			sm=n;
			c=0;
			for(i=0;i<d;i++)
			{
				if(mk>>i&1)
				{
					sm-=fc[i+3];
					c++;
				}
			}
			c+=__builtin_popcountll(sm);
			z=min(z,c);
		}
		printf("%lld\n",z);
	}
}