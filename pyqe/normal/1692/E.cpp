#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,ps[200069];

int main()
{
	long long t,rr,i,j,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=inf;
		for(j=0,i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			ps[i]=ps[i-1]+k;
			for(;ps[j]<ps[i]-d;j++);
			if(ps[i]-ps[j]==d)
			{
				z=min(z,n-(i-j));
			}
		}
		if(z==inf)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}