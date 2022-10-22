#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 2011,INF=1e9+233;
struct edge{int v,w,nxt;}e[200011];
int cnt=1,last[MAXN],cur[MAXN];
void add_directed_edge(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}
void adde(int u,int v,int w){add_directed_edge(u,v,w),add_directed_edge(v,u,0);}

int dep[MAXN],Q[MAXN];
bool bfs(int s,int t,int n)
{
	for(int i=1;i<=n;++i)dep[i]=0,cur[i]=last[i];
	int qh=0,qt=0;
	Q[qt++]=s,dep[s]=1;
	while(qh<qt)
	{
		int u=Q[qh++];
		for(int i=last[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(e[i].w&&!dep[v])dep[v]=dep[u]+1,Q[qt++]=v;
		}
	}
	return dep[t];
}
int ex_flow(int u,int t,int flow=INF)
{
	if(u==t)return flow;
	int f=0;
	for(int& i=cur[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(dep[v]==dep[u]+1&&e[i].w)
		{
			int tmp=ex_flow(v,t, min(e[i].w,flow-f));
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

pii p[MAXN];
int type[MAXN];
int main()
{
	int n=read(),S=n+n+1,T=S+1;
	ll sum=0;
	for(int i=1;i<=n;++i)
	{
		p[i].first=read(),p[i].second=read();
		if(p[i].second&1)type[i]=2+(p[i].first&1);
		else type[i]=!(p[i].first&1);
		if(type[i]==0)adde(S,i,INF);
		if(type[i]==3)adde(n+i,T,INF);
		int w=read();
		sum+=w;
		adde(i,n+i,w);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(i!=j&&abs(p[i].first-p[j].first)<=1&&abs(p[i].second-p[j].second)<=1)
			{
				if(type[i]+1==type[j])adde(n+i,j,INF);
			}
	printf("%lld\n",sum-Dinic(S,T,T));
	return 0;
}