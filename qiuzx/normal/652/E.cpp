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
#define N 300010
using namespace std;
ll n,m,din[N],lw[N],cnt=0,par[N],sz[N],sum[N],dp[N],f[N][32];
bool vis[N],bri[N],hv[N];
vector<pair<ll,ll> > vt[N],ed,nv[N];
void dfs(ll x,ll lst)
{
	par[x]=lst;
	vis[x]=true;
	lw[x]=din[x]=++cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst)
		{
			if(vis[vt[x][i].F])
			{
				lw[x]=min(lw[x],din[vt[x][i].F]);
			}
			else
			{
				dfs(vt[x][i].F,x);
				lw[x]=min(lw[x],lw[vt[x][i].F]);
			}
		}
	}
	if(lw[x]==din[x]&&x!=0)
	{
		bri[x]=true;
	}
	return;
}
void dfs2(ll x)
{
	vis[x]=true;
	sz[x]=cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i].F])
		{
			if(bri[x]&&par[x]==vt[x][i].F)
			{
				continue;
			}
			if(bri[vt[x][i].F]&&par[vt[x][i].F]==x)
			{
				continue;
			}
			dfs2(vt[x][i].F);
		}
	}
	return;
}
void dfs3(ll x,ll lst,ll d,ll st)
{
	ll i;
	dp[x]=d;
	if(x==0)
	{
		sum[x]=hv[0];
	}
	else
	{
		sum[x]=sum[lst]+hv[x]+st;
	}
	for(i=0;i<26;i++)
	{
		f[x][i+1]=f[f[x][i]][i];
	}
	for(i=0;i<nv[x].size();i++)
	{
		if(nv[x][i].F!=lst)
		{
			f[nv[x][i].F][0]=x;
			dfs3(nv[x][i].F,x,d+1,nv[x][i].S);
		}
	}
	return;
}
ll glca(ll x,ll y)
{
	ll i;
	if(dp[x]<dp[y])
	{
		swap(x,y);
	}
	for(i=26;i>=0;i--)
	{
		if(dp[f[x][i]]>=dp[y])
		{
			x=f[x][i];
		}
		if(x==y)
		{
			return x;
		}
	}
    for(i=26;i>=0;i--)
    {
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int main(){
	ll i,j,x,y,z;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--;
		y--;
		vt[x].push_back(make_pair(y,z));
		vt[y].push_back(make_pair(x,z));
		if(z)
		{
			ed.push_back(make_pair(x,y));
		}
	}
	dfs(0,-1);
	cnt=0;
	memset(vis,false,sizeof(vis));
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs2(i);
			cnt++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<vt[i].size();j++)
		{
			x=vt[i][j].F;
			if(sz[i]!=sz[x])
			{
				nv[sz[i]].push_back(make_pair(sz[x],vt[i][j].S));
			}
		}
	}
	for(i=0;i<ed.size();i++)
	{
		x=ed[i].F;
		y=ed[i].S;
		if(sz[x]==sz[y])
		{
			hv[sz[x]]=true;
		}
	}
	scanf("%lld%lld",&x,&y);
	x--;
	y--;
	if(sz[x]==sz[y])
	{
		if(hv[sz[x]])
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
		return 0;
	}
	dfs3(0,-1,0,0);
	z=glca(sz[x],sz[y]);
	if(sum[sz[x]]+sum[sz[y]]-2*sum[z]+hv[z])
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}