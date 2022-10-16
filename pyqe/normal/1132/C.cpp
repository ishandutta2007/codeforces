#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long ln,n,nn=0,dp[100069][3][3];
pair<long long,long long> a[100069],as[100069];

int main()
{
	long long i,j,r,k,l,z=-1e18;
	
	scanf("%lld%lld",&ln,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[i]={k,l};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		if(l>as[nn].sc)
		{
			if(k>as[nn].fr)
			{
				nn++;
			}
			as[nn]=a[i];
		}
	}
	for(i=0;i<=nn;i++)
	{
		for(j=0;j<=2;j++)
		{
			for(r=0;r<=2;r++)
			{
				dp[i][j][r]=-1e18;
			}
		}
	}
	dp[0][0][0]=0;
	for(i=1;i<=nn;i++)
	{
		k=as[i].fr;
		l=as[i].sc;
		for(j=0;j<=2;j++)
		{
			for(r=0;r<=min(i-1,2ll);r++)
			{
				dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][r]+l-max(as[i-1-r].sc,k-1));
			}
		}
		for(j=1;j<=2;j++)
		{
			for(r=1;r<=2;r++)
			{
				dp[i][j][r]=dp[i-1][j-1][r-1];
			}
		}
	}
	for(i=0;i<=2;i++)
	{
		z=max(z,dp[nn][max(2-n+nn,0ll)][i]);
	}
	printf("%lld\n",z);
}