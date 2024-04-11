#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(ll& a,ll t){if(a>t)return a=t,1;return 0;}
/**********/
#define MAXN 400011
struct edge{int v,nxt;}e[MAXN<<1|1];
int cnt=1,last[MAXN],deg[MAXN];
void adde(int u,int v){++deg[v], e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;}

int Q[MAXN],res[MAXN];
bool ban[MAXN],cut[MAXN];
pii ed[MAXN];
int main()
{
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){int u=read(),v=read();ed[i]=pii(u,v); adde(u,v),adde(v,u);}
	int h=0,t=0;
	for(int i=1;i<=n;++i)
		if(deg[i]<k)Q[t++]=i,ban[i]=1;
	while(h<t)
	{
		int u=Q[h++];
		for(int i=last[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			--deg[v];
			if(!ban[v]&&deg[v]<k)Q[t++]=v,ban[v]=1;
		}
	}
	res[m]=n-h;
	for(int i=m;i;--i)
	{
		int a=ed[i].first,b=ed[i].second;
		if(!ban[a]&&!ban[b])
		{
			cut[i]=1;
			--deg[a],--deg[b];
			if(deg[a]<k)Q[t++]=a,ban[a]=1;
			if(deg[b]<k)Q[t++]=b,ban[b]=1;
			while(h<t)
			{
				int u=Q[h++];
				for(int i=last[u];i;i=e[i].nxt)
				{
					int v=e[i].v;
					if(cut[i>>1])continue;
					--deg[v];
					if(!ban[v]&&deg[v]<k)Q[t++]=v,ban[v]=1;
				}
			}
		}
		res[i-1]=n-h;
	}
	for(int i=1;i<=m;++i)printf("%d\n",res[i]);
	return 0;
}