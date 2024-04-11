#include <bits/stdc++.h>

using namespace std;

long long n,nn,aa[2],a[2],d[2],inf=1e18;

int main()
{
	long long t,rr,ii,iii,w,e,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld%lld",aa,aa+1,d,d+1,&n);
		z=inf;
		for(ii=0;ii<2;ii++)
		{
			nn=n;
			for(iii=0;iii<2;iii++)
			{
				e=ii^iii;
				a[e]=aa[e];
				w=min(a[e]-d[e],nn);
				nn-=w;
				a[e]-=w;
			}
			z=min(z,a[0]*a[1]);
		}
		printf("%lld\n",z);
	}
}