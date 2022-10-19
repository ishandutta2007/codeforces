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
#define N 120010
using namespace std;
struct Edge{
	ll v,bkid,cap;
};
struct Flow{
	vector<Edge> vt[N];
	ll n,m,s,t,dep[N],cur[N];
	void addedge(ll x,ll y,ll w)
	{
		Edge cur;
		++m;
		cur.v=y,cur.bkid=vt[y].size(),cur.cap=w;
		vt[x].push_back(cur);
		cur.v=x,cur.bkid=vt[x].size()-1,cur.cap=0;
		vt[y].push_back(cur);
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
ll n,m,val[N],g,v[N],st[N],w[N],ans=0;
vector<ll> vt[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,k,x,tp;
	cin>>n>>m>>g;
	for(i=0;i<n;i++)
	{
		cin>>st[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>v[i];
		if(st[i])
		{
			ans-=v[i];
		}
		val[i]=(st[i]?v[i]:-v[i]);
	}
	for(i=0;i<m;i++)
	{
		cin>>tp>>val[i+n]>>k;
		while(k--)
		{
			cin>>x;
			x--;
			if(tp)
			{
				vt[i+n].push_back(x);
			}
			else
			{
				vt[x].push_back(i+n);
			}
		}
		cin>>k;
		if(k)
		{
			val[i+n]+=g;
			ans-=g;
		}
		if(!tp)
		{
			ans+=val[i+n];
			val[i+n]=-val[i+n];
		}
	}
	fl.n=n+m+2,fl.m=0;
	fl.s=n+m;fl.t=n+m+1;
	for(i=0;i<n+m;i++)
	{
		if(val[i]>0)
		{
			ans+=val[i];
		}
		if(val[i]>0)
		{
			fl.addedge(fl.s,i,val[i]);
		}
		else
		{
			fl.addedge(i,fl.t,-val[i]);
		}
		for(j=0;j<vt[i].size();j++)
		{
			fl.addedge(i,vt[i][j],INF);
		}
	}
	cout<<ans-fl.maxflow()<<endl;
	return 0;
}