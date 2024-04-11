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
#define N 100010
using namespace std;
ll n,sex[N],ced,hs;
pair<ll,ll> dp[N][2],ans;
bool vis[N];
vector<pair<ll,ll> > vt[N],ans_path,pat;
vector<ll> cyc,pas;
stack<ll> path,ped;
void dfs(ll x,ll lst)
{
	vis[x]=true;
	pas.push_back(x);
	path.push(x);
	ped.push(lst);
	ll i,j;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].S!=lst&&vt[x][i].S!=ced)
		{
			if(vis[vt[x][i].F])
			{
				ced=vt[x][i].S;
				cyc.push_back(ced);
				hs=vt[x][i].F;
				while(!path.empty()&&(path.top()!=vt[x][i].F))
				{
					path.pop();
					cyc.push_back(ped.top());
					ped.pop();
				}
			}
			else
			{
				dfs(vt[x][i].F,vt[x][i].S);
				if(x==hs)
				{
					hs=-1;
				}
			}
		}
	}
	if(hs==-1)
	{
		path.pop();
		ped.pop();
	}
	return;
}
void dfs2(ll x,ll lst)
{
	ll i;
	pair<ll,ll> sum=make_pair(0,0),upd;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].S==lst||vt[x][i].S==ced)
		{
			continue;
		}
		dfs2(vt[x][i].F,vt[x][i].S);
		upd=max(dp[vt[x][i].F][0],dp[vt[x][i].F][1]);
		sum.F+=upd.F;
		sum.S+=upd.S;
	}
	dp[x][0]=sum;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].S==lst||vt[x][i].S==ced)
		{
			continue;
		}
		upd=max(dp[vt[x][i].F][0],dp[vt[x][i].F][1]);
		sum.F-=upd.F;
		sum.S-=upd.S;
		sum.F+=dp[vt[x][i].F][0].F;
		sum.S+=dp[vt[x][i].F][0].S;
		sum.F++;
		if(sex[x]!=sex[vt[x][i].F])
		{
			sum.S++;
		}
		dp[x][1]=max(dp[x][1],sum);
		sum.F+=upd.F;
		sum.S+=upd.S;
		sum.F-=dp[vt[x][i].F][0].F;
		sum.S-=dp[vt[x][i].F][0].S;
		sum.F--;
		if(sex[x]!=sex[vt[x][i].F])
		{
			sum.S--;
		}
	}
	return;
}
void getdp(ll rt)
{
	ll i;
	for(i=0;i<pas.size();i++)
	{
		dp[pas[i]][0]=dp[pas[i]][1]=make_pair(0,0);
	}
	dfs2(rt,-1);
	return;
}
void get_path(ll x,ll tp,ll lst)
{
	ll i,j;
	pair<ll,ll> sum=make_pair(0,0),upd;
	if(tp==0)
	{
		for(i=0;i<vt[x].size();i++)
		{
			if(vt[x][i].S==lst||vt[x][i].S==ced)
			{
				continue;
			}
			if(dp[vt[x][i].F][0]>dp[vt[x][i].F][1])
			{
				get_path(vt[x][i].F,0,vt[x][i].S);
			}
			else
			{
				get_path(vt[x][i].F,1,vt[x][i].S);
			}
		}
		return;
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].S==lst||vt[x][i].S==ced)
		{
			continue;
		}
		upd=max(dp[vt[x][i].F][0],dp[vt[x][i].F][1]);
		sum.F+=upd.F;
		sum.S+=upd.S;
	}
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].S==lst||vt[x][i].S==ced)
		{
			continue;
		}
		upd=max(dp[vt[x][i].F][0],dp[vt[x][i].F][1]);
		sum.F-=upd.F;
		sum.S-=upd.S;
		sum.F+=dp[vt[x][i].F][0].F;
		sum.S+=dp[vt[x][i].F][0].S;
		sum.F++;
		if(sex[x]!=sex[vt[x][i].F])
		{
			sum.S++;
		}
		if(dp[x][1]==sum)
		{
			pat.push_back(make_pair(x,vt[x][i].F));
			get_path(vt[x][i].F,0,vt[x][i].S);
			for(j=0;j<vt[x].size();j++)
			{
				if(vt[x][j].S==lst||vt[x][j].S==ced||j==i)
				{
					continue;
				}
				if(dp[vt[x][j].F][0]>dp[vt[x][j].F][1])
				{
					get_path(vt[x][j].F,0,vt[x][j].S);
				}
				else
				{
					get_path(vt[x][j].F,1,vt[x][j].S);
				}
			}
			break;
		}
		dp[x][1]=max(dp[x][1],sum);
		sum.F+=upd.F;
		sum.S+=upd.S;
		sum.F-=dp[vt[x][i].F][0].F;
		sum.S-=dp[vt[x][i].F][0].S;
		sum.F--;
		if(sex[x]!=sex[vt[x][i].F])
		{
			sum.S--;
		}
	}
	return;
}
void solve(ll rt)
{
	ll i;
	hs=-1;
	pair<ll,ll> ret=make_pair(0,0);
	cyc.clear();
	pas.clear();
	ced=-1;
	dfs(rt,-1);
	getdp(rt);
	if(dp[rt][0]>dp[rt][1]&&ret<dp[rt][0])
	{
		ret=dp[rt][0];
		pat.clear();
		get_path(rt,0,-1);
	}
	else if(ret<dp[rt][1])
	{
		ret=dp[rt][1];
		pat.clear();
		get_path(rt,1,-1);
	}
	ced=cyc[1];
	getdp(rt);
	if(dp[rt][0]>dp[rt][1]&&ret<dp[rt][0])
	{
		ret=dp[rt][0];
		pat.clear();
		get_path(rt,0,-1);
	}
	else if(ret<dp[rt][1])
	{
		ret=dp[rt][1];
		pat.clear();
		get_path(rt,1,-1);
	}
	ans.F+=ret.F;
	ans.S+=ret.S;
	for(i=0;i<pat.size();i++)
	{
		ans_path.push_back(pat[i]);
	}
	return;
}
int main(){
	ll i,x;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&x,&sex[i]);
		x--;
		sex[i]--;
		vt[i].push_back(make_pair(x,i));
		vt[x].push_back(make_pair(i,i));
	}
	ans=make_pair(0,0);
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			solve(i);
		}
	}
	printf("%lld %lld\n",ans.F,ans.S);
	for(i=0;i<ans_path.size();i++)
	{
		printf("%lld %lld\n",ans_path[i].F+1,ans_path[i].S+1);
	}
	return 0;
}