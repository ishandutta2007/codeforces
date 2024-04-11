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
#define N 10010
using namespace std;
struct Edge{
	ll v,bkid,cap,cost;
};
struct Flow{
	vector<Edge> vt[N];
	ll n,m,s,t,dep[N],cur[N],h[N],totcost;
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
	void addedge(ll x,ll y,ll w,ll c)
	{
		Edge cur;
		++m;
		cur.v=y,cur.bkid=vt[y].size(),cur.cap=w,cur.cost=c;
		vt[x].push_back(cur);
		cur.v=x,cur.bkid=vt[x].size()-1,cur.cap=0,cur.cost=-c;
		vt[y].push_back(cur);
		return;
	}
	bool dijkstra()
	{
		priority_queue<pair<ll,ll> > pq;
		ll i,x,w;
		for(i=0;i<n;i++)
		{
			dep[i]=INF;
		}
		pq.push(make_pair(0,s));
		dep[s]=0;
		while(!pq.empty())
		{
			x=pq.top().S;
			w=-pq.top().F;
			pq.pop();
			if(w!=dep[x])
			{
				continue;
			}
			for(i=0;i<vt[x].size();i++)
			{
				if(vt[x][i].cap>0&&dep[vt[x][i].v]>w+vt[x][i].cost+h[x]-h[vt[x][i].v])
				{
					dep[vt[x][i].v]=w+vt[x][i].cost+h[x]-h[vt[x][i].v];
					pq.push(make_pair(-dep[vt[x][i].v],vt[x][i].v));
				}
			}
		}
		return (dep[t]<INF);
	}
	ll dfs(ll x,ll lft)
	{
		vis[x]=true;
		if(x==t||lft<=0)
		{
			return lft;
		}
		ll i,v,ret=0;
		for(i=cur[x];i<vt[x].size();i++,cur[x]++)
		{
			if((!vis[vt[x][i].v])&&vt[x][i].cap>0&&dep[vt[x][i].v]==dep[x]+vt[x][i].cost+h[x]-h[vt[x][i].v])
			{
				v=dfs(vt[x][i].v,min(lft,vt[x][i].cap));
				totcost+=v*vt[x][i].cost;
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
	ll min_cost_max_flow()
	{
		ll ret=0,i;
		totcost=0;
		while(dijkstra())
		{
			for(i=0;i<n;i++)
			{
				vis[i]=0;
				cur[i]=0;
			}
			ret+=dfs(s,LINF);
			for(i=0;i<n;i++)
			{
				h[i]+=dep[i];
			}
		}
		return totcost;
	}
}fl;
ll n,m,k,c,d;
void update(ll x,ll y)
{
	ll i,j;
	for(i=0;i<100;i++)
	{
		for(j=1;j<=k;j++)
		{
			fl.addedge(i*n+x,(i+1)*n+y,1,d*(2*j-1));
		}
	}
	return;
}
int main(){
	ll i,j,x,y;
	scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&c,&d);
	fl.init(101*n+2);
	for(i=0;i<k;i++)
	{
		scanf("%lld",&x);
		x--;
		fl.addedge(fl.s,x,1,0);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		update(x,y);
		update(y,x);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<100;j++)
		{
			fl.addedge(j*n+i,(j+1)*n+i,INF,0);
		}
	}
	for(i=0;i<=100;i++)
	{
		fl.addedge(i*n,fl.t,INF,i*c);
	}
	printf("%lld\n",fl.min_cost_max_flow());
	return 0;
}