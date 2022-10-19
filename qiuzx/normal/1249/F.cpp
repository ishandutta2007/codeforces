//ANMHLIJKTJIY!
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
#define N 210
using namespace std;
ll n,k,dp[N][N],tp[N],sufx[N],sufy[N],val[N],sonsz[N];
vector<ll> vt[N];
void merg(ll x,ll y)
{
	ll i,j,a;
	for(j=sonsz[y];j>0;j--)
	{
		dp[y][j]=dp[y][j-1];
	}
	dp[y][0]=0;
	memset(sufx,0,sizeof(sufx));
	memset(sufy,0,sizeof(sufy));
	for(i=sonsz[x];i>=0;i--)
	{
		sufx[i]=max(sufx[i+1],dp[x][i]);
	}
	for(i=sonsz[y];i>=0;i--)
	{
		sufy[i]=max(sufy[i+1],dp[y][i]);
	}
	for(j=0;j<=sonsz[x]+sonsz[y];j++)
	{
		tp[j]=max(dp[x][j],dp[y][j]);
	}
	for(a=0;a<=sonsz[x]+sonsz[y];a++)
	{
		tp[a]=max(tp[a],dp[x][a]+sufy[max(k-a,a)]);
		tp[a]=max(tp[a],dp[y][a]+sufx[max(k-a,a)]);
	}
	for(j=0;j<=sonsz[x]+sonsz[y];j++)
	{
		dp[x][j]=tp[j];
	}
	return;
}
void dfs(ll x,ll lst)
{
	ll i,j;
	sonsz[x]=1;
	dp[x][0]=val[x];
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x);
			merg(x,vt[x][i]);
			sonsz[x]+=sonsz[vt[x][i]];
		}
	}
	return;
}
int main(){
	ll i,j,x,y,ans=0;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&val[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--;
		y--;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	k++;
	dfs(0,-1);
	for(j=0;j<n;j++)
	{
		ans=max(ans,dp[0][j]);
	}
	printf("%lld\n",ans);
	return 0;
}