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
const int MAXN = 311,INF = 1e9+233;
struct DSU
{
	int fa[55];
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
	bool same(int x,int y){return find(x)==find(y);}
}st[MAXN],now;
struct Edge
{
	int u,v,w;
	bool operator< (const Edge& you)const{return w<you.w;}
}ke[MAXN],tp[5011],T[MAXN];
//Matroid
pii dis[MAXN];
int deg[MAXN],lim[MAXN], pre[MAXN];
int Q[MAXN<<6|1];
bool inq[MAXN];
bool inU[MAXN],X2[MAXN];
bool testdeg(int u,int v){return deg[u]<lim[u]&&deg[v]<lim[v];}
bool expand(int n)
{
	for(int i=1;i<=n;++i)pre[i]=0,inq[i]=0,dis[i]=pii(INF,0),X2[i]=0;
	int h=0,t=0;
	for(int i=1;i<=n;++i)
	{
		if(!inU[i]&&!now.same(ke[i].u,ke[i].v))Q[t++]=i,dis[i]=pii(ke[i].w,0);
		if(!inU[i]&&testdeg(ke[i].u,ke[i].v))X2[i]=1;
	}
	while(h<t)
	{
		int u=Q[h++];inq[u]=0;
		if(inU[u])//test I1
		{
			for(int v=1;v<=n;++v)
				if(!inU[v]&&!st[u].same(ke[v].u,ke[v].v)&&umin(dis[v],pii(dis[u].first+ke[v].w,dis[u].second+1)))
				{
					pre[v]=u;
					if(!inq[v])inq[v]=1,Q[t++]=v;
				}
		}
		else
		{
			++deg[ke[u].u],++deg[ke[u].v];
			for(int v=1;v<=n;++v)
				if(inU[v])
				{
					--deg[ke[v].u],--deg[ke[v].v];
					if(deg[ke[u].u]<=lim[ke[u].u]&&deg[ke[u].v]<=lim[ke[u].v]&&umin(dis[v],pii(dis[u].first-ke[v].w,dis[u].second+1)))
					{
						pre[v]=u;
						if(!inq[v])inq[v]=1,Q[t++]=v;
					}
					++deg[ke[v].u],++deg[ke[v].v];
				}
			--deg[ke[u].u],--deg[ke[u].v];
		}
	}
	pii mind(INF-1,0);
	for(int i=1;i<=n;++i)
		if(X2[i])umin(mind,dis[i]);
	for(int u=1;u<=n;++u)
		if(X2[u]&&mind==dis[u])
		{
			while(u)inU[u]^=1,u=pre[u];
			return 1;
		}
	return 0;
}
int a[55][55];
int n,k,m,cnt;
int main()
{
	n=read(),k=read(),m=cnt=0;
	for(int i=1;i<=k;++i)lim[i]=read();
	for(int i=k+1;i<=n;++i)lim[i]=n+1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			a[i][j]=read();
			int x=a[i][j];
			if(i>k&&j>k)tp[++cnt]=Edge{i,j,x};
			else if(i<=k&&j>k)ke[++m]=Edge{i,j,x};
		}
	std::sort(tp+1,tp+cnt+1);
	//MST for {k+1...n}
	now.init(n);
	for(int i=1;i<=cnt;++i)
		if(now.uni(tp[i].u,tp[i].v))ke[++m]=tp[i];
	//for(int i=1;i<=m;++i)printf("(%d,%d)\n",ke[i].u,ke[i].v);
	//printf("M=%d\n",m);
	//M=n-1+(n-k)k,O(kn)
	int all=1<<(k*(k-1)/2),ans=1e9+233;
	for(int s=0;s<all;++s)
	{
		for(int i=1;i<=n;++i)deg[i]=0;
		now.init(n);
		int cur=0,fail=0,edges=0,sum=0;
		for(int u=1;u<=k;++u)
			for(int v=u+1;v<=k;++v)
			{
				if(s&(1<<cur))fail|=!now.uni(u,v),++deg[u],++deg[v],sum+=a[u][v],T[++edges]=Edge{u,v,a[u][v]};
				++cur;
			}
		for(int u=1;u<=k;++u)
			if(deg[u]>lim[u])fail=1;
		if(fail)continue;
		for(int i=1;i<=m;++i)st[i].init(n);
		for(int i=1;i<=m;++i)inU[i]=0;
		//printf("New T:\n");
		//Repeat k^(k-2) times
		//for(int i=1;i<=edges;++i)printf("(%d,%d)\n",T[i].u,T[i].v);
		while(expand(m))
		{
			//puts("Enter 138!");
			now.init(n);
			for(int i=1;i<=n;++i)deg[i]=0;
			for(int i=1;i<=edges;++i)++deg[T[i].u],++deg[T[i].v],now.uni(T[i].u,T[i].v);
			for(int i=1;i<=m;++i)
				if(inU[i])
				{
					//printf("U:(%d,%d)\n",ke[i].u,ke[i].v);
					++deg[ke[i].u],++deg[ke[i].v];
					now.uni(ke[i].u,ke[i].v);
					st[i].init(n);
					for(int j=1;j<=m;++j)
						if(inU[j]&&i!=j)st[i].uni(ke[j].u,ke[j].v);
					for(int j=1;j<=edges;++j)st[i].uni(T[j].u,T[j].v);
				}
		}
		for(int i=1;i<=m;++i)
			if(inU[i])sum+=ke[i].w,++edges;
		if(edges==n-1)umin(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}