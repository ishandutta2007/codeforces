#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dp[1069][1069],zs=0;
pair<pair<long long,long long>,long long> a[1069];
pair<long long,long long> d[1069];
vector<pair<long long,long long>> sq;

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].fr.fr,&a[i].fr.sc);
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&d[i].fr);
		d[i].sc=i;
	}
	sort(d+1,d+m+1);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]=dp[i][j-1];
			if(a[j].fr.fr<=d[i].fr)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[j].fr.sc);
			}
		}
	}
	i=m;
	for(j=n;j>0;j--)
	{
		if(i>0&&a[j].fr.fr<=d[i].fr&&dp[i-1][j-1]+a[j].fr.sc==dp[i][j])
		{
			sq.push_back({a[j].sc,d[i].sc});
			zs++;
			i--;
		}
	}
	printf("%lld %lld\n",zs,dp[m][n]);
	for(i=0;i<zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}