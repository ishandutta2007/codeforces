#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 30
using namespace std;
ll n,m,cost[N][N],mxcost[N][N],sumcost[N][N],change[N][N],dp[1200010];
string s[N];
ll dfs(ll mask)
{
	if(dp[mask]!=-1)
	{
		return dp[mask];
	}
	dp[mask]=LINF;
	ll lbit,i;
	for(lbit=0;(mask&(1<<lbit))==0&&lbit<23;lbit++);
	for(i=0;i<m;i++)
	{
		dp[mask]=min(dp[mask],dfs(mask^(mask&change[i][s[lbit][i]-'a']))+sumcost[i][s[lbit][i]-'a']-mxcost[i][s[lbit][i]-'a']);
		dp[mask]=min(dp[mask],dfs(mask^(1<<lbit))+cost[lbit][i]);
	}
	return dp[mask];
}
int main(){
	ll i,j;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>cost[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			change[j][s[i][j]-'a']|=(1<<i);
			sumcost[j][s[i][j]-'a']+=cost[i][j];
			mxcost[j][s[i][j]-'a']=max(mxcost[j][s[i][j]-'a'],cost[i][j]);
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	printf("%lld\n",dfs((1<<n)-1));
	return 0;
}