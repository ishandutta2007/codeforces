#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 600011;
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
std::vector<int>g[MAXN];
int fa[MAXN],val[MAXN];
int Q[MAXN],pre[MAXN];
void bfs(int s,int n)
{
	for(int i=1;i<=n;++i)pre[i]=0;
	int h=0,t=0;
	Q[t++]=s;
	while(h<t)
	{
		int u=Q[h++];
		for(auto v:g[u])
			if(v!=pre[u])pre[v]=u,Q[t++]=v;
	}
}
std::vector<int>a[MAXN];
int ans=0;
bool dfs(int u)
{
	int cur=0;
	for(auto v:g[u])
	{
		if(v==fa[u])continue;
		bool k=dfs(v);
		if(val[v])
		{
			ans+=cur,cur^=1;
		}
		else ans+=k;
	}
	return cur;
}
int main()
{
	int n=read(),m=read();
	DSU::init(n);
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		if(DSU::uni(u,v))g[u].push_back(v),g[v].push_back(u);
	}
	//fprintf(stderr,"Pass 80!\n");
	bfs(1,n);
	for(int i=1;i<=n;++i)fa[i]=pre[i];
	int q=read();
	for(int i=1;i<=q;++i)
	{
		int x=read(),y=read();
		bfs(y,n);
		while(x)
		{
			if(pre[x])
			{
				if(fa[x]==pre[x])val[x]^=1;
				else val[pre[x]]^=1;
			}
			a[i].push_back(x),x=pre[x];
		}
	}
	//fprintf(stderr,"Pass 98!\n");
	ans+=dfs(1);
	if(ans==0)
	{
		puts("YES");
		for(int i=1;i<=q;++i)
		{
			printf("%d\n",int(a[i].size()));
			for(auto x:a[i])printf("%d ",x);
			puts("");
		}
	}
	else
	{
		puts("NO");
		printf("%d\n",ans);
	}
	return 0;
}