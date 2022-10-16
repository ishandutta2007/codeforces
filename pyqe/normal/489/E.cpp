#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,ub=1e3,a[1069],wg[1069],sq[1069],zs=0,inf=1e18;
double ep=1e-9;
pair<double,long long> dp[1069];

int main()
{
	long long i,j,e;
	double lh,rh,md,zz;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",a+i,wg+i);
	}
	for(lh=0,rh=ub;rh-lh>ep;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=n;i++)
		{
			dp[i].fr=inf;
			for(j=0;j<i;j++)
			{
				dp[i]=min(dp[i],{dp[j].fr+sqrt(abs(a[i]-a[j]-d)),j});
			}
			dp[i].fr-=md*wg[i];
		}
		if(dp[n].fr<=0)
		{
			zz=md;
			rh=md;
		}
		else
		{
			lh=md;
		}
	}
	for(i=1;i<=n;i++)
	{
		dp[i].fr=inf;
		for(j=0;j<i;j++)
		{
			dp[i]=min(dp[i],{dp[j].fr+sqrt(abs(a[i]-a[j]-d)),j});
		}
		dp[i].fr-=zz*wg[i];
	}
	for(e=n;e;e=dp[e].sc)
	{
		zs++;
		sq[zs]=e;
	}
	for(i=zs;i;i--)
	{
		printf("%lld%c",sq[i]," \n"[i==1]);
	}
}