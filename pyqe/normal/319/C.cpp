#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,va[100069],co[100069],dp[100069],cx[100069];

bool cmp(long long x,long long y,long long x2,long long y2)
{
	if(x/y==x2/y2)
	{
		return x%y<=x2%y2;
	}
	else
	{
		return x/y<=x2/y2;
	}
}

int main()
{
	long long i,j,lh,rh,md,zz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",va+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",co+i);
	}
	for(i=1;i<=n;i++)
	{
		if(i-1)
		{
			zz=1;
			for(lh=2,rh=nn;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(dp[cx[md]]+co[cx[md]]*va[i]<=dp[cx[md-1]]+co[cx[md-1]]*va[i])
				{
					zz=cx[md];
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			dp[i]=dp[zz]+co[zz]*va[i];
		}
		for(;nn>1&&cmp(dp[i]-dp[cx[nn]],co[cx[nn]]-co[i],dp[i]-dp[cx[nn-1]],co[cx[nn-1]]-co[i]);nn--);
		nn++;
		cx[nn]=i;
	}
	printf("%lld\n",dp[n]);
}