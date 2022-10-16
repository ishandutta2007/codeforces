#include <bits/stdc++.h>

using namespace std;

long long n,d,lb[2],rb[2],inf=1e18;

int main()
{
	long long t,rr,ii,i,ds,df,sm,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld%lld",lb+ii,rb+ii);
		}
		if(lb[0]>lb[1])
		{
			swap(lb[0],lb[1]);
		}
		if(rb[0]>rb[1])
		{
			swap(rb[0],rb[1]);
		}
		ds=max(lb[1]-rb[0],0ll);
		sm=max(rb[0]-lb[1],0ll);
		df=rb[1]-lb[0]-sm;
		sm*=n;
		if(sm>=d)
		{
			z=0;
		}
		else
		{
			c=0;
			z=inf;
			for(i=1;i<=n&&sm<d;i++)
			{
				z=min(z,c+min(d-sm,df)+ds+max(d-sm-df,0ll)*2);
				sm+=df;
				c+=ds+df;
			}
		}
		printf("%lld\n",z);
	}
}