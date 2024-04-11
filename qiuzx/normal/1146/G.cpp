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
#define N 3010
using namespace std;
struct Edge{
	ll v,bkid,cap;
};
struct Flow{
	ll n,m,s,t,dep[N],curid[N];
	vector<Edge> vt[N];
	void init(ll _n,ll _s=-1,ll _t=-1)
	{
		ll i;
		n=_n;
		s=(_s==-1)?n-2:_s;
		t=(_t==-1)?n-1:_t;
		for(i=0;i<n;i++)
		{
			vt[i].clear();
		}
		return;
	}
	void addedge(ll x,ll y,ll w)
	{
		Edge cur;
//		cout<<x<<" -> "<<y<<": "<<w<<endl;
		cur.v=y,cur.bkid=vt[y].size(),cur.cap=w;
		vt[x].push_back(cur);
		cur.v=x,cur.bkid=vt[x].size()-1,cur.cap=0;
		vt[y].push_back(cur);
		return;
	}
	bool bfs()
	{
		ll i;
		for(i=0;i<n;i++)
		{
			dep[i]=INF;
		}
		queue<ll> q;
		q.push(s);
		dep[s]=0;
		while(!q.empty())
		{
			ll x=q.front();
			q.pop();
			for(i=0;i<vt[x].size();i++)
			{
				if(vt[x][i].cap>0)
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
		ll i,ret=0;
		for(i=curid[x];i<vt[x].size();i++,curid[x]++)
		{
			if(vt[x][i].cap>0&&dep[vt[x][i].v]==dep[x]+1)
			{
				ll v=dfs(vt[x][i].v,min(lft,vt[x][i].cap));
				lft-=v;
				vt[x][i].cap-=v;
				vt[vt[x][i].v][vt[x][i].bkid].cap+=v;
				ret+=v;
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
				curid[i]=0;
			}
			ret+=dfs(s,LINF);
		}
		return ret;
	}
}fl;
ll n,h,m,lo[N],hi[N],lim[N],cost[N];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ll i,j,k;
	cin>>n>>h>>m;
	fl.init(n*(h+1)+m+2);
	for(i=0;i<m;i++)
	{
		cin>>lo[i]>>hi[i]>>lim[i]>>cost[i];
		lo[i]--,hi[i]--;
		for(j=lo[i];j<=hi[i];j++)
		{
			fl.addedge(j*(h+1)+lim[i],n*(h+1)+i,INF);
		}
		fl.addedge(n*(h+1)+i,fl.t,cost[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<=h;j++)
		{
			fl.addedge(i*(h+1)+j-1,i*(h+1)+j,h*h-j*j);
		}
		fl.addedge(fl.s,i*(h+1),h*h);
	}
	cout<<n*h*h-fl.maxflow()<<endl;
	return 0;
}