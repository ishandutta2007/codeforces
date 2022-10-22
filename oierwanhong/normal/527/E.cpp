#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
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
const int MAXN = 2000011;
struct edge{int v,nxt;}e[MAXN<<1|1];
int cnt=1,last[MAXN],deg[MAXN];
void adde(int u,int v){++deg[v],e[++cnt].v=v,e[cnt].nxt=last[u],last[u]=cnt;}

bool vis[MAXN];
pii s[MAXN];
int top=0;
void dfs(int u)
{
	for(int &i=last[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[i>>1])continue;
		vis[i>>1]=1;
		dfs(v);
		s[++top]=pii(u,v);
	}
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;++i){int u=read(),v=read();adde(u,v),adde(v,u);}
	int lst=0;
	for(int u=1;u<=n;++u)
		if(deg[u]&1)
		{
			if(lst)++m,adde(lst,u),adde(u,lst),lst=0;
			else lst=u;
		}
	if(m&1)++m,adde(1,1);
	dfs(1);
	printf("%d\n",m);
	for(int i=1;i<=m;++i)
		if(i&1)printf("%d %d\n",s[i].first,s[i].second);
		else printf("%d %d\n",s[i].second,s[i].first);
	return 0;
}