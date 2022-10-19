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
#define N 1000010
using namespace std;
struct Edge{
	ll v,bkid,cap,id;
};
struct Flow{
	vector<Edge> vt[N];
	ll n,m,s,t,dep[N],cur[N],ans[N];
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
	void addedge(ll x,ll y,ll w,ll id)
	{
		Edge cr;
		cr.v=y,cr.bkid=vt[y].size(),cr.cap=w,cr.id=id;
		vt[x].push_back(cr);
		cr.v=x,cr.bkid=vt[x].size()-1,cr.cap=0,cr.id=id+INF;
		vt[y].push_back(cr);
		return;
	}
	bool bfs()
	{
		ll i,x;
		for(i=0;i<n;i++)
		{
			dep[i]=INF;
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
			ret+=dfs(s,INF);
		}
		return ret;
	}
	ll calc(ll cc,ll _s,ll _t)
	{
		ll i,j,ret;
		for(i=0;i<n;i++)
		{
			for(j=0;j<vt[i].size();j++)
			{
				if(i==_t&&vt[i][j].v==_s)
				{
					ret=vt[vt[i][j].v][vt[i][j].bkid].cap;
					vt[vt[i][j].v][vt[i][j].bkid].cap=vt[i][j].cap=0;
				}
			}
		}
		return ret;
	}
	void print(ll bd)
	{
		ll i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<vt[i].size();j++)
			{
				if(vt[i][j].id<bd)
				{
					ans[vt[i][j].id]=(vt[i][j].cap==0);
				}
			}
		}
		return;
	}
}fl;
ll n,m,s,t,R,B,totf[N],cst[N],dx[N],dy[N],cnt[N];
vector<ll> allx,ally;
int main(){
	ll i,x,y,l,r,d,tp;
	scanf("%lld%lld%lld%lld",&n,&m,&R,&B);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&dx[i],&dy[i]);
		allx.push_back(dx[i]);
		ally.push_back(dy[i]);
	}
	sort(allx.begin(),allx.end());
	allx.erase(unique(allx.begin(),allx.end()),allx.end());
	sort(ally.begin(),ally.end());
	ally.erase(unique(ally.begin(),ally.end()),ally.end());
	s=allx.size()+ally.size();t=s+1;
	fl.init(allx.size()+ally.size()+4);
	for(i=0;i<n;i++)
	{
		dx[i]=lower_bound(allx.begin(),allx.end(),dx[i])-allx.begin();
		dy[i]=lower_bound(ally.begin(),ally.end(),dy[i])-ally.begin();
		fl.addedge(dx[i],dy[i]+allx.size(),1,i);
		cnt[dx[i]]++,cnt[dy[i]+allx.size()]++;
	}
	memset(cst,63,sizeof(cst));
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&tp,&x,&d);
		if(tp==1)
		{
			y=lower_bound(allx.begin(),allx.end(),x)-allx.begin();
			if(y>=allx.size()||allx[y]!=x)
			{
				continue;
			}
			cst[y]=min(cst[y],d);
		}
		else
		{
			y=lower_bound(ally.begin(),ally.end(),x)-ally.begin();
			if(y>=ally.size()||ally[y]!=x)
			{
				continue;
			}
			cst[y+allx.size()]=min(cst[y+allx.size()],d);
		}
	}
	for(i=0;i<s;i++)
	{
		cst[i]=min(cst[i],cnt[i]);
		l=(cnt[i]-cst[i]+1)/2;
		r=(cnt[i]+cst[i])/2;
		if(l<=r)
		{
			if(i<allx.size())
			{
				fl.addedge(s,i,r-l,n);
				totf[s]-=l,totf[i]+=l;
			}
			else
			{
				fl.addedge(i,t,r-l,n);
				totf[i]-=l,totf[t]+=l;
			}
		}
		else
		{
			puts("-1");
			return 0;
		}
	}
	fl.addedge(t,s,INF,n);
	ll tot=0;
	for(i=0;i<=t;i++)
	{
		if(totf[i]>0)
		{
			tot+=totf[i];
			fl.addedge(fl.s,i,totf[i],n);
		}
		else if(totf[i]<0)
		{
			fl.addedge(i,fl.t,-totf[i],n);
		}
	}
	if(fl.maxflow()!=tot)
	{
		puts("-1");
		return 0;
	}
	ll ans=fl.calc(m,s,t);
	fl.s=t,fl.t=s;
	ans-=fl.maxflow();
	printf("%lld\n",n*min(B,R)+ans*abs(B-R));
	fl.print(n);
	for(i=0;i<n;i++)
	{
		putchar((fl.ans[i]^(R<B))?'r':'b');
	}
	return 0;
}