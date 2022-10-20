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
#define N 100010
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
//		cout<<x<<" -> "<<y<<": "<<w<<endl;
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
ll n,b,q;
pair<ll,ll> qry[N];
int main(){
	ll i;
	scanf("%lld%lld%lld",&n,&b,&q);
	for(i=0;i<q;i++)
	{
		scanf("%lld%lld",&qry[i].F,&qry[i].S);
		if(qry[i].S>qry[i].F)
		{
			puts("unfair");
			return 0;
		}
	}
	sort(qry,qry+q);
	fl.init(q+1+b+5+2);
	for(i=0;i<5;i++)
	{
		fl.addedge(fl.s,i,n/5);
	}
	for(i=1;i<=b;i++)
	{
		fl.addedge(i%5,i+5-1,1);
	}
	ll lst=1,lstnum=0;
	for(i=0;i<q;i++)
	{
		if(qry[i].S<lstnum||(lst>qry[i].F&&qry[i].S!=lstnum))
		{
			puts("unfair");
			return 0;
		}
		while(lst<=qry[i].F)
		{
			fl.addedge(lst+5-1,i+b+5,1);
			lst++;
		}
		fl.addedge(i+b+5,fl.t,qry[i].S-lstnum);
		lstnum=qry[i].S;
	}
	while(lst<=b)
	{
		fl.addedge(lst+5-1,q+b+5,1);
		lst++;
	}
	fl.addedge(q+b+5,fl.t,n-lstnum);
	puts(fl.maxflow()==n?"fair":"unfair");
	return 0;
}