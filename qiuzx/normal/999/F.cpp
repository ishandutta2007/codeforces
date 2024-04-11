//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 510
using namespace std;
ll n,k,dp[N*10][N],cnt_card[100010],cnt_pp[100010],h[15],ans=0;
ll getdp(ll tot,ll num)
{
	ll i,j,l,ret=0;
	for(i=0;i<=tot;i++)
	{
		for(j=0;j<=num;j++)
		{
			dp[i][j]=-LINF;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=tot;i++)
	{
		for(j=max((ll)0,i-k);j<i;j++)
		{
			for(l=1;l<=num;l++)
			{
				dp[i][l]=max(dp[i][l],dp[j][l-1]+h[i-j]);
			}
		}
	}
	for(i=0;i<=num;i++)
	{
		ret=max(ret,dp[tot][i]);
	}
	return ret;
}
int main(){
	ll i,x;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n*k;i++)
	{
		scanf("%lld",&x);
		cnt_card[x]++;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		cnt_pp[x]++;
	}
	for(i=1;i<=k;i++)
	{
		scanf("%lld",&h[i]);
	}
	for(i=0;i<=100000;i++)
	{
		if(cnt_pp[i]>0)
		{
			if(cnt_card[i]>=cnt_pp[i]*k)
			{
				ans+=cnt_pp[i]*h[k];
				continue;
			}
			ans+=getdp(cnt_card[i],cnt_pp[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}