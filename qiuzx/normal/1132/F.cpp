#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 510
using namespace std;
ll n,dp[N][N];
string s;
ll dfs(ll l,ll r)
{
	if(l>r)
	{
		return 0;
	}
	if(dp[l][r]<INF)
	{
		return dp[l][r];
	}
	ll i;
	dp[l][r]=dfs(l+1,r)+1;
	for(i=l+1;i<=r;i++)
	{
		if(s[l]==s[i])
		{
			dp[l][r]=min(dp[l][r],dfs(l+1,i-1)+dfs(i,r));
		}
	}
	return dp[l][r];
}
int main(){
	cin>>n>>s;
	memset(dp,63,sizeof(dp));
	cout<<dfs(0,n-1)<<endl;
	return 0;
}