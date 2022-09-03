#include <cstdio>
#include <iostream>
#include <algorithm>
using std::min;

struct Node{int v;Node *x;}*p,*l[100009];
int n,m,u,v,tms,cst[100009];
int dfn[100009],low[100009];
int s[100009],t;
bool ins[100009];
long long ans,cnt=1;

void dfs(int u)
{
	dfn[u]=low[u]=++tms;
	ins[s[t++]=u]=true;
	int w;
	for (Node *p=l[u];p;p=p->x)
	{
		if (!dfn[w=p->v])
		{
			dfs(w);
			low[u]=min(low[u],low[w]);
		}
		else if (ins[w]) low[u]=min(low[u],dfn[w]);
	}
	if (low[u]==dfn[u])
	{
		int x=0,y=0X7FFFFFFF;
		do
		{
			ins[w=s[--t]]=false;
			if (y>cst[w]) x=1,y=cst[w];
			else if (y==cst[w]) ++x;
		}
		while (u!=w);
		ans+=y;
		cnt=(cnt*x)%1000000007;
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",cst+i);
	scanf("%d",&m);
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		p=(Node*)malloc(sizeof(Node));
		p->v=v,p->x=l[u],l[u]=p;
	}
	for (int i=1;i<=n;++i) if (!dfn[i]) dfs(i);
	std::cout<<ans<<' '<<cnt;
	return 0;
}