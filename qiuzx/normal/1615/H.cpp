//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 2010
using namespace std;
struct Edge{
	ll v,bkid,cap;
};
struct Flow{
	vector<Edge> vt[N];
	ll n,m,s,t,dep[N],cur[N];
	bool vis[N];
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
	void dfs(ll x)
	{
		vis[x]=true;
		ll i;
		for(i=0;i<vt[x].size();i++)
		{
			if(vt[x][i].cap>0&&(!vis[vt[x][i].v]))
			{
				dfs(vt[x][i].v);
			}
		}
		return;
	}
	vector<pair<ll,ll> > getpath()
	{
		ll i;
		for(i=0;i<n;i++)
		{
			vis[i]=false;
		}
		dfs(s);
		vector<pair<ll,ll> > ret;
		for(i=0;i<n-2;i++)
		{
			ret.push_back(make_pair(i,vis[i]));
		}
		return ret;
	}
}fl;
ll n,m,a[N],ans[N],col[N],cnt=0,id[N];
vector<ll> vt[N];
void solve(ll l,ll r,vector<ll> v)
{
	ll i,j,mid=(l+r)>>1;
	if(l==r)
	{
		for(i=0;i<v.size();i++)
		{
			ans[v[i]]=l;
		}
		return;
	}
	++cnt;
	for(i=0;i<v.size();i++)
	{
		col[v[i]]=cnt;
		id[v[i]]=i;
	}
	fl.init(v.size()+2);
	for(i=0;i<v.size();i++)
	{
		ll cost=-abs(a[v[i]]-(mid+1))+abs(a[v[i]]-mid);
		if(cost>=0)
		{
			fl.addedge(fl.s,i,cost);
		}
		else
		{
			fl.addedge(i,fl.t,-cost);
		}
		for(j=0;j<vt[v[i]].size();j++)
		{
			if(col[vt[v[i]][j]]==col[v[i]])
			{
				fl.addedge(i,id[vt[v[i]][j]],INF);
			}
		}
	}
	fl.maxflow();
	vector<ll> v1,v2;
	vector<pair<ll,ll> > pt=fl.getpath();
	for(i=0;i<pt.size();i++)
	{
		if(pt[i].S==0)
		{
			v1.push_back(v[pt[i].F]);
		}
		else
		{
			v2.push_back(v[pt[i].F]);
		}
	}
	if(!v1.empty())
	{
		solve(l,mid,v1);
	}
	if(!v2.empty())
	{
		solve(mid+1,r,v2);
	}
	return;
}
int main(){
	ll i,x,y;
	scanf("%lld%lld",&n,&m);
	vector<ll> v;
	for(i=0;i<n;i++)
	{
		v.push_back(i);
		scanf("%lld",&a[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		vt[x].push_back(y);
	}
	solve(-LINF,LINF,v);
	for(i=0;i<n;i++)
	{
		printf("%lld ",ans[i]);
	}
	puts("");
	return 0;
}