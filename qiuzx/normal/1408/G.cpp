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
#define N 3010 
using namespace std;
ll n,a[N][N],fa[N],szp[N],sze[N],din[N],dout[N],cnt=0,cnt2=0,dp[N][N];
vector<ll> vt[N],upd[N];
vector<pair<ll,pair<ll,ll> > > ed;
ll getf(ll x)
{
	if(x==fa[x])
	{
		return x;
	}
	return fa[x]=getf(fa[x]);
}
void dfs(ll x,ll lst)
{
	ll i;
	din[x]=cnt2+1;//from
	if(vt[x].size()<=1)
	{
		cnt2++;
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i]!=lst)
		{
			dfs(vt[x][i],x);
		}
	}
	dout[x]=cnt2;//to
	if(szp[x]*(szp[x]-1)==2*sze[x])//can be used alone
	{
		upd[din[x]-1].push_back(dout[x]);
	}
	return;
}
int main(){
	ll i,j,k,x,y,z;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(i<j)
			{
				ed.push_back(make_pair(a[i][j],make_pair(i,j)));
			}
		}
	}
	sort(ed.begin(),ed.end());
	for(i=0;i<=2*n;i++)
	{
		fa[i]=i;
		szp[i]=1;
		sze[i]=0;
	}
	for(i=0;i<ed.size();i++)
	{
		x=ed[i].S.F;
		y=ed[i].S.S;
		x=getf(x);
		y=getf(y);
		if(x==y)
		{
			sze[x]++;//connect in x
			continue;
		}
		fa[x]=fa[y]=cnt+n;
		szp[cnt+n]=szp[x]+szp[y];
		sze[cnt+n]=sze[x]+sze[y]+1;//connect x and y to cnt+n
		vt[cnt+n].push_back(x);
		vt[cnt+n].push_back(y);
		vt[x].push_back(cnt+n);
		vt[y].push_back(cnt+n);
		cnt++;
	}
	dfs(cnt+n-1,-1);
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(dp[i][j]!=0)
			{
				for(k=0;k<upd[i].size();k++)
				{
					dp[upd[i][k]][j+1]=(dp[upd[i][k]][j+1]+dp[i][j])%mod;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld ",dp[n][i]);
	}
	puts("");
	return 0;
}