#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=1,x[1000069],y[1000069],d[1000069],dp[1000069],cx[1000069];
pair<pair<long long,long long>,long long> a[1000069];

bool cmp(long long x1,long long y1,long long x2,long long y2)
{
	if(x1/y1==x2/y2)
	{
		return x1%y1<x2%y2;
	}
	else
	{
		return x1/y1<x2/y2;
	}
}

int main()
{
	long long i,j,ii,lh,rh,md,zz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].fr.fr,&a[i].fr.sc,&a[i].sc);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		x[i]=a[i].fr.fr;
		y[i]=a[i].fr.sc;
		d[i]=a[i].sc;
		zz=cx[1];
		for(lh=2,rh=nn;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(dp[cx[md]]-x[cx[md]]*y[i]>=dp[cx[md-1]]-x[cx[md-1]]*y[i])
			{
				zz=cx[md];
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		dp[i]=dp[zz]-x[zz]*y[i]+x[i]*y[i]-d[i];
		if(dp[i]>dp[cx[nn]])
		{
			for(;nn>1;nn--)
			{
				if(cmp(dp[i]-dp[cx[nn]],x[i]-x[cx[nn]],dp[i]-dp[cx[nn-1]],x[i]-x[cx[nn-1]]))
				{
					break;
				}
			}
			nn++;
			cx[nn]=i;
		}
	}
	printf("%lld\n",dp[cx[nn]]);
}