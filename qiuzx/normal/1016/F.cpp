//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 300010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll n,m,dist[N],f[N][20],sz[N],dep[N],lmx[N],lmx2[N],par[N],pared[N],mxd=-INF;
bool vis[N];
vector<pair<ll,ll> > vt[N];
void dfs(ll x,ll lst,ll d,ll v)
{
	dep[x]=d;
	sz[x]=1;
	dist[x]=v;
	ll i;
	for(i=1;i<20;++i)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(i=0;i<vt[x].size();++i)
	{
		if(vt[x][i].F!=lst)
		{
			f[vt[x][i].F][0]=x;
			par[vt[x][i].F]=x;
			pared[vt[x][i].F]=vt[x][i].S;
			dfs(vt[x][i].F,x,d+1,v+vt[x][i].S);
			sz[x]+=sz[vt[x][i].F];
		}
	}
	return;
}
ll glca(ll x,ll y)
{
	if(dep[x]<dep[y])
	{
		swap(x,y);
	}
	ll i;
	for(i=19;i>=0;--i)
	{
		if(dep[f[x][i]]>=dep[y])
		{
			x=f[x][i];
		}
	}
	if(x==y)
	{
		return x;
	}
	for(i=19;i>=0;--i)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
void solve()
{
	ll i,j,mxdep=0;
	for(i=0;i<n;++i)
	{
		lmx[i]=lmx2[i]=-LINF;
	}
	for(i=0;i<n;++i)
	{
		ll xx=glca(i,n-1);
		lmx[xx]=max(lmx[xx],dist[i]);
		if(xx!=i)
		{
			lmx2[xx]=max(lmx2[xx],dist[i]);
		}
	}
	par[0]=-1;
	for(i=n-1;i>=0;i=par[i])
	{
		vis[i]=true;
	}
	for(i=0;i<n;)
	{
		for(j=0;j<vt[i].size();++j)
		{
			if((vt[i][j].F!=par[i])&&vis[vt[i][j].F])
			{
				lmx[vt[i][j].F]=max(lmx[vt[i][j].F],lmx[i]);
				lmx2[vt[i][j].F]=max(lmx2[vt[i][j].F],lmx[i]);
				i=vt[i][j].F;
				j=-1;
				break;
			}
		}
		if(j>-1)
		{
			break;
		}
	}
	mxd=-dist[n-1];
	for(i=n-1;i>=0;i=par[i])
	{
		ll tot=0;
		for(j=0;j<vt[i].size();++j)
		{
			if(!vis[vt[i][j].F])
			{
				tot+=sz[vt[i][j].F];
			}
		}
		if(tot>1)
		{
			mxd=dist[n-1];
			return;
		}
		if(par[i]==-1)
		{
			break;
		}
		mxd=max(mxd,dist[i]+lmx2[par[i]]-2*dist[i]);
		for(j=0;j<vt[i].size();++j)
		{
			if(!vis[vt[i][j].F])
			{
				mxd=max(mxd,dist[vt[i][j].F]+lmx[par[i]]-2*dist[i]);
			}
		}
	}
	mxd+=dist[n-1];
	return;
}
int main(){
	ll i,x,y,w;
	n=rint(),m=rint();
	for(i=1;i<n;++i)
	{
		x=rint()-1,y=rint()-1,w=rint();
		vt[x].push_back(make_pair(y,w));
		vt[y].push_back(make_pair(x,w));
	}
	dfs(0,-1,0,0);
	if(vt[i].size()>2)
	{
		mxd=dist[n-1];
	}
	else
	{
		solve();
	}
	while(m--)
	{
		rout(min(dist[n-1],mxd+rint())),putchar('\n');
	}
	return 0;
}