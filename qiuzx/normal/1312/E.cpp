//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 510
using namespace std;
ll n,a[N],dp[N][N],f[N];
ll dfs(ll l,ll r)
{
	if(l>r)
	{
		return -INF;
	}
	if(dp[l][r]!=-1)
	{
		return dp[l][r];
	}
	if(l==r)
	{
		return dp[l][r]=a[l];
	}
	ll i,lft,rht;
	dp[l][r]=-INF;
	for(i=l;i<r;i++)
	{
		lft=dfs(l,i);
		rht=dfs(i+1,r);
		if(lft>=0&&rht>=0&&lft==rht)
		{
			dp[l][r]=lft+1;
		}
	}
	return dp[l][r];
}
int main(){
	ll i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	memset(dp,-1,sizeof(dp));
	dfs(0,n-1);
	memset(f,63,sizeof(f));
	f[0]=0;
	for(i=0;i<n;i++)
	{
		if(f[0]>INF)
		{
			continue;
		}
		for(j=i+1;j<=n;j++)
		{
			if(dp[i][j-1]!=-INF)
			{
				f[j]=min(f[j],f[i]+1);
			}
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}