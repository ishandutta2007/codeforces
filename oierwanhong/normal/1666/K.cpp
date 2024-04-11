#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
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
const int MAXN = 200011;
ll LINF = 1.233e18;
namespace Flow
{
	struct edge{int v,nxt;ll w;}e[MAXN<<1|1];
	int cnt=1,last[MAXN];
	void add_single_edge(int u,int v,ll w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}
	void adde(int u,int v,ll w){add_single_edge(u,v,w),add_single_edge(v,u,0);}

	int dep[MAXN],cur[MAXN];
	int Q[MAXN];
	bool bfs(int st,int ed,int n)
	{
		for(int i=1;i<=n;++i)dep[i]=0,cur[i]=last[i];
		int h=0,t=0;
		Q[t++]=st,dep[st]=1;
		while(h<t)
		{
			int u=Q[h++];
			for(int i=last[u];i;i=e[i].nxt)
			{
				int v=e[i].v;
				if(e[i].w&&!dep[v])
				{
					dep[v]=dep[u]+1,Q[t++]=v;
				}
			}
		}
		return dep[ed]>0;
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
	ll Dinic(int st,int ed,int n)
	{
		ll res=0;
		while(bfs(st,ed,n))res+=ex_flow(st,ed);
		return res;
	}
}
int main()
{
	int n=read(),m=read(),S=n+n+1,T=S+1;
	int A=read(),B=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		Flow::adde(u,n+v,w),Flow::adde(n+v,u,w);
		Flow::adde(v,n+u,w),Flow::adde(n+u,v,w);
	}
	Flow::adde(S,A,LINF),Flow::adde(n+A,T,LINF);
	Flow::adde(B,T,LINF),Flow::adde(S,n+B,LINF);
	printf("%lld\n",Flow::Dinic(S,T,T));
	for(int i=1;i<=n;++i)
	{
		int now=!!Flow::dep[i];
		now+=!Flow::dep[n+i];
		if(now==2)putchar('A');
		else if(now==1)putchar('C');
		else putchar('B');
	}
	puts("");
	return 0;
}