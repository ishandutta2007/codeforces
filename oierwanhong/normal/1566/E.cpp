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
const int MAXN = 500011;
std::vector<int>g[MAXN];
bool useful[MAXN],cut[MAXN];
int deg[MAXN];
int ans;
void dfs(int u,int fa=0)
{
	int norm=0,sp=0;
	for(auto v:g[u])
		if(v!=fa)dfs(v,u),++deg[u];
	for(auto v:g[u])
		if(v!=fa&&!useful[v])norm=1;
	for(auto v:g[u])
		if(v!=fa&&useful[v])
		{
			if(norm)--ans,--deg[u],cut[v]=1;
			else if(!sp)--deg[u],sp=v;
			else --ans,--deg[u],cut[sp]=1,cut[v]=1,norm=1;
		}
	useful[u]=(fa!=0&&deg[u]!=0);
	for(auto v:g[u])
		if(v!=fa&&!cut[v]&&deg[v])useful[u]=0;
}
int main()
{
	int task=read();
	while(task--)
	{
		ans=0;
		int n=read();
		for(int i=1;i<=n;++i)g[i].clear(),useful[i]=0,deg[i]=0,cut[i]=0;
		for(int i=1;i<n;++i){int u=read(),v=read();g[u].push_back(v),g[v].push_back(u);}
		for(int u=2;u<=n;++u)
			if(g[u].size()==1)++ans;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}