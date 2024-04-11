#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,dp[2][200069],inf=1e18;
pair<long long,long long> as[200069];

int main()
{
	long long i,ii,k,mx[2],lh,rh,md,zz;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		as[i]={k,i};
	}
	sort(as+1,as+n+1);
	for(lh=1,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				dp[ii][i]=0;
			}
			mx[ii]=-inf;
		}
		for(i=md;i<=n;i++)
		{
			k=as[i].sc;
			for(ii=0;ii<2;ii++)
			{
				dp[ii][k]++;
			}
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				dp[ii][i]=dp[ii][i-1]+dp[ii][i]-(i%2==ii);
			}
		}
		for(i=n-d+1;i;i--)
		{
			for(ii=0;ii<2;ii++)
			{
				mx[ii]=max(mx[ii],dp[ii][i+d-1]);
			}
			if(mx[(i-1)%2]>=dp[(i-1)%2][i-1]+1)
			{
				break;
			}
		}
		if(i)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",as[zz].fr);
}