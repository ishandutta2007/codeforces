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
#define N 3510
using namespace std;
struct Edge{
	ll v,bkid,cap;
};
struct Flow{
	vector<Edge> vt[N];
	ll n,m,s,t,dep[N],cur[N];
	void init(ll _n)
	{
		n=_n,m=0,s=_n-2,t=_n-1;
		ll i;
		for(i=0;i<n;i++)
		{
			vt[i].clear();
		}
		return;
	}
	void addedge(ll x,ll y,ll w)
	{
		Edge cr;
		cr.v=y,cr.bkid=vt[y].size(),cr.cap=w;
		vt[x].push_back(cr);
		cr.v=x,cr.bkid=vt[x].size()-1,cr.cap=0;
		vt[y].push_back(cr);
		return;
	}
	bool bfs()
	{
		ll i,x;
		for(i=0;i<n;i++)
		{
			dep[i]=LINF;
		}
		queue<ll> q;
		q.push(s);
		dep[s]=0;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			for(i=0;i<vt[x].size();i++)
			{
				if(vt[x][i].cap!=0)
				{
					if(dep[vt[x][i].v]>dep[x]+1)
					{
						dep[vt[x][i].v]=dep[x]+1;
						q.push(vt[x][i].v);
					}
				}
			}
		}
		return (dep[t]<INF);
	}
	ll dfs(ll x,ll lft)
	{
		if(x==t||lft<=0)
		{
			return lft;
		}
		ll i,v,ret=0;
		for(i=cur[x];i<vt[x].size();i++,cur[x]++)
		{
			if(vt[x][i].cap>0&&dep[vt[x][i].v]==dep[x]+1)
			{
				v=dfs(vt[x][i].v,min(lft,vt[x][i].cap));
				ret+=v;
				vt[x][i].cap-=v;
				vt[vt[x][i].v][vt[x][i].bkid].cap+=v;
				lft-=v;
				if(lft<=0)
				{
					break;
				}
			}
		}
		return ret;
	}
	ll maxflow()
	{
		ll ret=0,i;
		while(bfs())
		{
			for(i=0;i<n;i++)
			{
				cur[i]=0;
			}
			ret+=dfs(s,LINF);
		}
		return ret;
	}
}fl;
ll n,a[N],b[N],ans=0;
bool vis[N];
vector<ll> vt[N];
void dfs(ll x)
{
	ll i;
	vis[x]=true;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i]])
		{
			dfs(vt[x][i]);
		}
	}
	return;
}
int main(){
	ll i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	fl.init(n+2);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
		if(b[i]<0)
		{
			fl.addedge(i,fl.t,-b[i]);
		}
		else
		{
			fl.addedge(fl.s,i,b[i]);
			ans+=b[i];
		}
	}
	for(i=1;i<n;i++)
	{
		memset(vis,false,sizeof(vis));
		for(j=i-1;j>=0;j--)
		{
			if(a[i]%a[j]==0&&(!vis[j]))
			{
				fl.addedge(i,j,INF);
				vt[i].push_back(j);
				dfs(j);
			}
		}
	}
	printf("%lld\n",ans-fl.maxflow());
	return 0;
}