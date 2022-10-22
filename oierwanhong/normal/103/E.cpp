#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
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
const int MAXN = 1000011,SINF = 1e9;
const ll LINF = 1.233e18;
namespace Flow
{
	struct edge{int v,nxt;ll w;}e[MAXN<<1|1];
	int cnt=1,last[MAXN],cur[MAXN];
	void add_single_edge(int u,int v,ll w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}
	void adde(int u,int v,ll w)
	{
		//printf("Addedge %d %d %lld\n",u,v,w);
		add_single_edge(u,v,w),add_single_edge(v,u,0);
	}
	void clear(){cnt=1;memset(last,0,sizeof last);}
	int Q[MAXN],dep[MAXN];
	bool bfs(int st,int ed,int n)
	{
		for(int i=1;i<=n;++i)cur[i]=last[i],dep[i]=0;
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
	ll Dinic(int st,int ed,int n)
	{
		ll res=0;
		while(bfs(st,ed,n))res+=ex_flow(st,ed);
		return res;
	}
}

int main()
{
	int n=read(),S=n+n+1,T=S+1;
	for(int i=1;i<=n;++i)
	{
		int m=read();
		while(m--)Flow::adde(i,n+read(),LINF);
	}
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		int x=-read()+SINF;
		Flow::adde(S,i,x);
		ans+=x;
	}
	for(int i=1;i<=n;++i)Flow::adde(n+i,T,SINF);
	printf("%lld\n",-ans+Flow::Dinic(S,T,T));
	return 0;
}