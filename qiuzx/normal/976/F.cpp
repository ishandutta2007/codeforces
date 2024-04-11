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
#define N 4010
using namespace std;
struct Edge{
	ll v,bkid,cap,orid;
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
	void addedge(ll x,ll y,ll w,ll orid)
	{
		Edge cr;
		cr.v=y,cr.bkid=vt[y].size(),cr.cap=w,cr.orid=orid;
		vt[x].push_back(cr);
		cr.v=x,cr.bkid=vt[x].size()-1,cr.cap=0,cr.orid=orid;
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
ll n1,n2,m,deg[N],mndeg=INF,edid[N][N];
vector<ll> ans[N];
int main(){
	ll i,j,k,x,y;
	scanf("%lld%lld%lld",&n1,&n2,&m);
	fl.init(n1+n2+2);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		deg[x]++,deg[y+n1]++;
		fl.addedge(x,y+n1,1,i);
	}
	for(i=0;i<n1+n2;i++)
	{
		mndeg=min(mndeg,deg[i]);
	}
	for(i=0;i<n1;i++)
	{
		deg[i]-=mndeg;
		fl.addedge(fl.s,i,deg[i],-1);
	}
	for(i=n1;i<n1+n2;i++)
	{
		deg[i]-=mndeg;
		fl.addedge(i,fl.t,deg[i],-1);
	}
	for(i=0;i<=mndeg;i++)
	{
		fl.maxflow();
		for(j=0;j<n1;j++)
		{
			vector<Edge> cur=fl.vt[j];
			for(k=0;k<cur.size();k++)
			{
				if(cur[k].cap>0&&cur[k].orid>=0)
				{
					ans[i].push_back(cur[k].orid);
				}
			}
		}
		for(j=0;j<n1;j++)
		{
			fl.addedge(fl.s,j,1,-1);
		}
		for(j=n1;j<n1+n2;j++)
		{
			fl.addedge(j,fl.t,1,-1);
		}
	}
	for(i=mndeg;i>=0;i--)
	{
		printf("%d ",ans[i].size());
		sort(ans[i].begin(),ans[i].end());
		for(j=0;j<ans[i].size();j++)
		{
			printf("%lld ",ans[i][j]+1);
		}
		puts("");
	}
	return 0;
}