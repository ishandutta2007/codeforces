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
#define N 500010
using namespace std;
ll n,m,dep[N],mxd;
bool vis[N],ok;
vector<ll> vt[N],ans,dif[N];
vector<pair<ll,ll> > ans2;
void dfs(ll x,ll d)
{
	mxd=max(mxd,d);
	dep[x]=d;
	vis[x]=true;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i]])
		{
			dfs(vt[x][i],d+1);
		}
	}
	return;
}
void dfs2(ll x)
{
	vis[x]=true;
	if(dep[x]==mxd)
	{
		ok=true;
		ans.push_back(x);
		return;
	}
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i]])
		{
			dfs2(vt[x][i]);
			if(ok)
			{
				ans.push_back(x);
				return;
			}
		}
	}
	return;
}
void solve1()
{
	ans.clear();
	ok=false;
	ll i;
	for(i=0;i<n;i++)
	{
		vis[i]=false;
	}
	dfs2(0);
	printf("%lld\n",(ll)ans.size());
	for(i=0;i<ans.size();i++)
	{
		printf("%lld ",ans[i]+1);
	}
	puts("");
	return;
}
void solve2()
{
	ll i,j;
	for(i=0;i<=mxd;i++)
	{
		dif[i].clear();
	}
	for(i=0;i<n;i++)
	{
		dif[dep[i]].push_back(i);
	}
	ans2.clear();
	for(i=0;i<=mxd;i++)
	{
		for(j=0;j+1<dif[i].size();j+=2)
		{
			ans2.push_back(make_pair(dif[i][j],dif[i][j+1]));
		}
	}
	printf("%lld\n",(ll)ans2.size());
	for(i=0;i<ans2.size();i++)
	{
		printf("%lld %lld\n",ans2[i].F+1,ans2[i].S+1);
	}
	return;
}
int main(){
	ll T,i,x,y;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			vis[i]=false;
			vt[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&x,&y);
			x--;
			y--;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		mxd=0;
		dfs(0,0);
		if(mxd>=(n+1)/2)
		{
			puts("PATH");
			solve1();
		}
		else
		{
			puts("PAIRING");
			solve2();
		}
	}
	return 0;
}