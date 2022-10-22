#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 400011,SINF = 1e9+233;
const ll LINF = 1e18+233;
namespace Flow
{
	struct edge{int v,nxt;ll w;}e[MAXN<<1|1];
	int cnt=1,last[MAXN],cur[MAXN];
	void add_single_edge(int u,int v,ll w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}
	void adde(int u,int v,ll w){add_single_edge(u,v,w),add_single_edge(v,u,0);}
	void clear(int n)
	{
		cnt=1;
		for(int i=1;i<=n;++i)last[i]=0;
	}
	int dep[MAXN],Q[MAXN];
	bool bfs(int st,int ed,int n)
	{
		for(int i=1;i<=n;++i)cur[i]=last[i],dep[i]=0;
		int h=0,t=0;
		dep[st]=1,Q[t++]=st;
		while(h<t)
		{
			int u=Q[h++];
			for(int i=last[u];i;i=e[i].nxt)
			{
				int v=e[i].v;
				if(e[i].w)
				{
					if(!dep[v])dep[v]=dep[u]+1,Q[t++]=v;
					if(v==ed)return 1;
				}
			}
		}
		return 0;
	}
	ll ex_flow(int u,int t,ll flow=LINF)
	{
		if(u==t)return flow;
		ll f=0;
		for(int &i=cur[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(e[i].w&&dep[v]==dep[u]+1)
			{
				ll tmp=ex_flow(v,t,min(e[i].w,flow-f));
				e[i].w-=tmp,e[i^1].w+=tmp;
				f+=tmp;
				if(f==flow)return f;
			}
		}
		return f;
	}
	ll Dinic(int s,int t,int n)
	{
		ll res=0;
		while(bfs(s,t,n))res+=ex_flow(s,t);
		return res;
	}
}
std::vector<int>g[MAXN];
int lb[MAXN],rb[MAXN],a[MAXN];
int main()
{
	int n=read(),m=read(),S=n+1,T=S+1;
	for(int i=1;i<=n;++i)lb[i]=0,rb[i]=SINF;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i){int u=read(),v=read();g[u].emplace_back(v);}
	while(1)
	{
		bool flag=0;
		for(int i=1;i<=n;++i)flag|= lb[i]<rb[i];
		if(!flag)break;
		Flow::clear(T);
		for(int i=1;i<=n;++i)
		{
			int lm=(lb[i]+rb[i])>>1,rm=lm+1;
			ll d= abs(a[i]-lm)-abs(a[i]-rm);
			if(d>0)Flow::adde(S,i,d);
			else Flow::adde(i,T,-d);
		}
		for(int u=1;u<=n;++u)
			for(auto v:g[u])
				if(lb[u]==lb[v]&&rb[u]==rb[v])Flow::adde(u,v,LINF);
		Flow::Dinic(S,T,T);
		for(int i=1;i<=n;++i)
			if(Flow::dep[i]==0)rb[i]=(lb[i]+rb[i])>>1;
			else lb[i]=((lb[i]+rb[i])>>1)+1;
	}
	for(int i=1;i<=n;++i)printf("%d ",lb[i]);
	puts("");
	return 0;
}