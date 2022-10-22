#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 200011,INF = 1e9+233;
namespace Flow
{
	struct edge{int v,w,nxt;}e[MAXN<<1|1];
	int cnt=1,last[MAXN],cur[MAXN];
	void add_directed_edge(int u,int v,int w){e[++cnt].v=v,e[cnt].w=w,e[cnt].nxt=last[u],last[u]=cnt;}
	void adde(int u,int v,int w){ add_directed_edge(u,v,w),add_directed_edge(v,u,0);}
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
		Q[t++]=st,dep[st]=1;
		while(h<t)
		{
			int u=Q[h++];
			for(int i=last[u];i;i=e[i].nxt)
			{
				int v=e[i].v;
				if(!dep[v]&&e[i].w)dep[v]=dep[u]+1,Q[t++]=v;
			}
		}
		return dep[ed];
	}
	int ex_flow(int u,int t,int flow=INF)
	{
		if(u==t)return flow;
		int f=0;
		for(int &i=cur[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(dep[v]==dep[u]+1&&e[i].w)
			{
				int tmp=ex_flow(v,t,min(e[i].w,flow-f));
				e[i].w-=tmp,e[i^1].w+=tmp;
				f+=tmp;
				if(f==flow)return f;
			}
		}
		return f;
	}
	int Dinic(int s,int t,int n)
	{
		int res=0;
		while(bfs(s,t,n))res+=ex_flow(s,t);
		return res;
	}
}
namespace DSU
{
	int fa[MAXN];
	void init(int n){for(int i=1;i<=n;++i)fa[i]=i;}
	int find(int x)
	{
		if(fa[x]==x)return x;
		return fa[x]=find(fa[x]);
	}
	bool uni(int x,int y)
	{
		x=find(x),y=find(y);
		if(x==y)return 0;
		return fa[x]=y,1;
	}
}
char s[11];
int pw[7];
int eg[7][7],fa[7],rest[7],n, h;
int it[7];
void update()
{
	int all=h*(h+1)/2;
	int S=all+h+1,T=S+1,cur=0;
	Flow::clear(T);
	for(int u=1;u<=h;++u)
		for(int v=u;v<=h;++v)
		{
			++cur;
			Flow::adde(S,cur,eg[u][v]);
			Flow::adde(cur,all+u,INF);
			if(u!=v)Flow::adde(cur,all+v,INF);
		}
	for(int u=1;u<=h;++u)Flow::adde(all+u,T,rest[u]-1);
	if(Flow::Dinic(S,T,T)+h-1==n-1)
	{
		for(int i=2;i<=h;++i)printf("%d %d\n",pw[fa[i]-1],pw[i-1]);
		cur=0;
		for(int u=1;u<=h;++u)
			for(int v=u;v<=h;++v)
			{
				++cur;
				for(int i=Flow::last[cur];i;i=Flow::e[i].nxt)
				{
					int k=Flow::e[i].v;
					if(k==S)continue;
					if(k-all==u)
					{
						int rf=Flow::e[i^1].w;
						while(rf--)printf("%d %d\n",pw[v-1],it[u]),++it[u];
					}
					else
					{
						int rf=Flow::e[i^1].w;
						while(rf--)printf("%d %d\n",pw[u-1],it[v]),++it[v];
					}
				}
			}
		exit(0);
	}
}
void dfsTree(int x)
{
	if(x>h)
	{
		DSU::init(h);
		for(int i=2;i<=h;++i)
			if(!DSU::uni(i,fa[i]))return;
		for(int i=2;i<=h;++i)
		{
			if(fa[i]<i)--eg[fa[i]][i];
			else --eg[i][fa[i]];
		}
		update();
		for(int i=2;i<=h;++i)
		{
			if(fa[i]<i)++eg[fa[i]][i];
			else ++eg[i][fa[i]];
		}
		return;
	}
	for(int y=1;y<=h;++y)
		if(x!=y&&(eg[x][y]||eg[y][x]))fa[x]=y,dfsTree(x+1);
}
int main()
{
	pw[0]=1;
	for(int i=1;i<=6;++i)pw[i]=pw[i-1]*10;
	n=read();
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%s",s+1);
		u=strlen(s+1);
		scanf("%s",s+1);
		v=strlen(s+1);
		if(u>v)std::swap(u,v);
		++eg[u][v];
	}
	h=1;
	int cur=1;
	while(cur<=n)
	{
		it[h]=cur+1;
		rest[h]=cur*9;
		++h,cur*=10;
	}
	--h,cur/=10;
	rest[h]=n-cur+1;
	dfsTree(2);
	puts("-1");
	return 0;
}