#include <bits/stdc++.h>
 
using namespace std;
 
long long n,d,nn[2],a[69],as[2][8000069],inf=1e18;
 
void bf(long long xx,long long x,long long w)
{
	if(x>n/(1+!xx))
	{
		nn[xx]++;
		as[xx][nn[xx]]=w;
	}
	else
	{
		for(;1;w*=a[x])
		{
			bf(xx,x+1,w);
			if(w>inf/a[x])
			{
				break;
			}
		}
	}
}
 
int main()
{
	long long i,ii,lh,rh,md,zz,sm;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	scanf("%lld",&d);
	sort(a+1,a+n+1);
	for(ii=0;ii<2;ii++)
	{
		bf(ii,1+n/2*ii,1);
		sort(as[ii]+1,as[ii]+nn[ii]+1);
	}
	for(lh=1,rh=1e18;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		for(i=1;i<=nn[1];i++)
		{
			sm+=upper_bound(as[0]+1,as[0]+nn[0]+1,md/as[1][i])-as[0]-1;
		}
		if(sm>=d)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}