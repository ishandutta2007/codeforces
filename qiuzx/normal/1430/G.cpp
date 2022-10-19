//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 100000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 410
using namespace std;
struct Edge{
	ll v,bkid,cap;
};
struct Flow{
	bool mrk[N];
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
	void getpath(ll x)
	{
		mrk[x]=true;
		ll i;
		for(i=0;i<vt[x].size();i++)
		{
			if(vt[x][i].cap>0&&(!mrk[vt[x][i].v]))
			{
				getpath(vt[x][i].v);
			}
		}
		return;
	}
}fl;
ll n,m,val[N];
int main(){
	ll i,j,x,y,z;
	scanf("%lld%lld",&n,&m);
	fl.init(n*(n+2)+2);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		x--,y--;
		for(j=0;j<n+1;j++)
		{
			fl.addedge(y+j*n,x+(j+1)*n,INF);
		}
		val[x]+=z;
		val[y]-=z;
	}
	for(i=0;i<n;i++)
	{
		fl.addedge(fl.s,i,INF);
		for(j=0;j<n+1;j++)
		{
			fl.addedge(i+j*n,i+(j+1)*n,val[i]*j+50000000);
		}
		fl.addedge(i+(n+1)*n,fl.t,INF);
	}
	fl.maxflow();
	fl.getpath(fl.s);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			if(fl.mrk[i+j*n]&&(!fl.mrk[i+(j+1)*n]))
			{
				printf("%lld ",j);
				break;
			}
		}
	}
	return 0;
}