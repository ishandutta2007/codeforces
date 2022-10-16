#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dp[2][2],inf=1e18;
pair<long long,long long> a[200069];

bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	return mp(max(x.fr,x.sc),x.fr-x.sc)<mp(max(y.fr,y.sc),y.fr-y.sc);
}

long long ds(long long x,long long y)
{
	return abs(a[x].fr-a[y].fr)+abs(a[x].sc-a[y].sc);
}

int main()
{
	long long i,ii,jj,y,x,p[2][2]={{0,0},{0,0}};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&y,&x);
		a[i]={y,x};
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		y=a[i].fr;
		x=a[i].sc;
		if(i==n||max(y,x)!=max(a[i+1].fr,a[i+1].sc))
		{
			p[1][0]=p[0][1]+1;
			p[1][1]=i;
			for(ii=0;ii<2;ii++)
			{
				dp[1][ii]=inf;
				for(jj=0;jj<2;jj++)
				{
					dp[1][ii]=min(dp[1][ii],dp[0][jj]+ds(p[0][jj],p[1][!ii])+ds(p[1][!ii],p[1][ii]));
				}
			}
			for(ii=0;ii<2;ii++)
			{
				p[0][ii]=p[1][ii];
				dp[0][ii]=dp[1][ii];
			}
		}
	}
	printf("%lld\n",min(dp[0][0],dp[0][1]));
}