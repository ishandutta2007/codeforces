#pragma GCC optimize(2)
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
using namespace std;
ll ksm(ll x,ll y)
{
	if(y==0)
	{
		return 1;
	}
	ll ret=ksm(x,y>>1);
	ret*=ret;
	if(y&1)
	{
		ret*=x;
	}
	return ret;
}
map<pair<ll,ll>,ll> dp;
ll a,b,n;
ll dfs(ll x,ll y)
{
	if(dp.count(make_pair(x,y)))
	{
		return dp[make_pair(x,y)];
	}
	dp[make_pair(x,y)]=-1;//If A starts operating at the stat (x,y), can he win?
	if(ksm(x,y)>=n)
	{
		return dp[make_pair(x,y)]=1;
	}
	if(x==1&&ksm(2,y)>=n)
	{
		return dp[make_pair(x,y)]=0;
	}
	if(y==1&&ksm(x,2)>=n)
	{
		if(x%2==n%2)
		{
			return dp[make_pair(x,y)]=1;
		}
		return dp[make_pair(x,y)]=-1;
	}
	if(dfs(x+1,y)<0||dfs(x,y+1)<0)
	{
		dp[make_pair(x,y)]=1;
	}
	return dp[make_pair(x,y)];
}
int main(){
	cin>>a>>b>>n;
	ll x=dfs(a,b);
	if(x==1)
	{
		puts("Masha");
	}
	else if(x==0)
	{
		puts("Missing");
	}
	else
	{
		puts("Stas");
	}
	return 0;
}