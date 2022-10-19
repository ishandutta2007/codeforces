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
#define N 25
using namespace std;
ll n,m,k,a[N][N],sum[N][N],ans=0;
map<ll,ll> mp1[N][N],mp2[N][N];
void dfs1(ll x,ll y,ll pre)
{
	if(x+y>=(n+m)/2-1)
	{
		mp1[x][y][pre]++;
		return;
	}
	pre^=a[x][y];
	if(x+1<n)
	{
		dfs1(x+1,y,pre);
	}
	if(y+1<m)
	{
		dfs1(x,y+1,pre);
	}
	return;
}
void dfs2(ll x,ll y,ll pre)
{
	pre^=a[x][y];
	if(n-x-1+m-y-1>=(n+m-1)/2)
	{
		mp2[x][y][pre]++;
		return;
	}
	if(x-1>=0)
	{
		dfs2(x-1,y,pre);
	}
	if(y-1>=0)
	{
		dfs2(x,y-1,pre);
	}
	return;
}
int main(){
	ll i,j;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			sum[i][j+1]=(sum[i][j]^a[i][j]);
		}
	}
	dfs1(0,0,0);
	dfs2(n-1,m-1,0);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			for(map<ll,ll>::iterator it=mp1[i][j].begin();it!=mp1[i][j].end();it++)
			{
				ans+=(it->S)*(mp2[i][j][k^(it->F)]);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}