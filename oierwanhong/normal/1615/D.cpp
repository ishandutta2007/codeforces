#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 400011,INF = 1e9+233;
struct DSU
{
	int fa[MAXN],val[MAXN],size[MAXN];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i,val[i]=0,size[i]=1;}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return find(fa[x]);
	}
	bool connect(int x,int y){return find(x)==find(y);}
	bool query(int x)
	{
		bool res=0;
		while(fa[x]!=x)res^=val[x],x=fa[x];
		return res;
	}
	void uni(int x,int y,int k)
	{
		k^=query(x)^query(y);
		x=find(x),y=find(y);
		if(x==y)return;
		if(size[x]<size[y])fa[x]=y,val[x]=k,size[y]+=size[x];
		else fa[y]=x,val[y]=k,size[x]+=size[y];
	}
}dsu;
int dis[MAXN];
struct edge{int v,w,nxt;}e[MAXN<<1|1];
int cnt=1,last[MAXN];
void adde(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}

void dfs(int u,int fa=0)
{
	for(int i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		if(e[i].w>=0)dis[v]=dis[u]^e[i].w;
		else dis[v]=dis[u];
		dfs(v,u);
	}
}
bool fail=0;
void AddOpt(int x,int y,int k)
{
	//printf("Addopt %d %d %d\n",x,y,k);
	if(dsu.connect(x,y)&&(dsu.query(x)^dsu.query(y))!=k){fail=1;return;}
	dsu.uni(x,y,k);
}
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		cnt=1,fail=0;
		for(int i=1;i<=n;++i)last[i]=0,dis[i]=0;
		dsu.init(n);
		for(int i=1;i<n;++i)
		{
			int u=read(),v=read(),w=read();
			adde(u,v,w),adde(v,u,w);
		}
		dfs(1);
		for(int i=1;i<n;++i)
			if(e[i<<1].w>=0)AddOpt(e[i<<1].v,e[i<<1|1].v,e[i<<1].w&1);
		for(int i=1;i<=m;++i)
		{
			int u=read(),v=read(),type=read();
			int d=dis[u]^dis[v];
			type^=__builtin_popcount(d>>1)&1;
			AddOpt(u,v,type);
		}
		if(fail){puts("NO");continue;}
		puts("YES");
		for(int i=1;i<n;++i)
			if(e[i<<1].w>=0)printf("%d %d %d\n",e[i<<1|1].v,e[i<<1].v,e[i<<1].w);
			else printf("%d %d %d\n",e[i<<1|1].v,e[i<<1].v,dsu.query(e[i<<1].v)^dsu.query(e[i<<1|1].v));
	}
	return 0;
}