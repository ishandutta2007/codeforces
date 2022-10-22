#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=100100;
struct Edge{int num,ne;}e[2*V];
int p[V],K;
int nxt[V];
void add(int x,int y)
{
	e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
bool vis[V];
int d[V];
void dfs(int u)
{
	vis[u]=1;
	for(int i=p[u];i!=-1;i=e[i].ne)
	{
		int v=e[i].num;
		if(vis[v])continue;
		nxt[u]=v;d[v]=d[u]+1;
		dfs(v);break;
	}
}
int n,m,S,x,y;
int main()
{
	while(~scanf("%d%d%d",&n,&m,&S))
	{
		memset(p,-1,sizeof(p));K=0;
		memset(vis,0,sizeof(vis));
		memset(nxt,-1,sizeof(nxt));
		memset(d,-1,sizeof(d));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		}
		d[1]=0;dfs(1);
		int last=1;
		for(int i=1;i<=n;i++)
		if(d[i]>d[last])last=i;
		int first=last;
		for(int i=p[last];i!=-1;i=e[i].ne)
		if(d[e[i].num]<d[first])first=e[i].num;
		printf("%d\n",d[last]-d[first]+1);
		while(1)
		{
			printf("%d",first);
			if(first==last)break;
			printf(" ");first=nxt[first];
		}puts("");
	}
}