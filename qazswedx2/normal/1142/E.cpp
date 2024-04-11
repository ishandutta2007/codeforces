#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{
    int v,nxt;
}e[500005],e1[500005];
struct edge1
{
	int u,v;
}e2[500005];
int n,m,dfn[100005],low[100005],cnt,g[100005],gt,vis[100005];
int st[100005],tp=0,q[1000005],head,tail;
int tin[100005],h[100005],h1[100005],t,t1;
vector<int> a[100005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void add1(int u,int v)
{
	//printf("u=%d,v=%d\n",u,v);
	e1[++t1].v=v;
	e1[t1].nxt=h1[u];
	h1[u]=t1;
}
void dfs(int u)
{
    dfn[u]=low[u]=++cnt;
    //printf("u=%d\n",u);
    st[++tp]=u;
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!vis[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        gt++;
        while(st[tp+1]!=u)
        {
        	//printf("tp=%d\n",tp);
            vis[st[tp]]=1;
            g[st[tp]]=gt;
            a[gt].push_back(st[tp]);
            tp--;
        }
    }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		e2[i].u=u,e2[i].v=v;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	for(int i=1;i<=m;i++)
	{
		int gu=g[e2[i].u],gv=g[e2[i].v];
		if(gu!=gv)
		{
			add1(gu,gv);
			tin[gv]++;
		}
	} 
	/*for(int i=1;i<=n;i++)
		printf("%d ",g[i]);
	printf("\n");
	for(int i=1;i<=gt;i++)
		printf("%d ",tin[i]);
	printf("\n");*/ 
	head=1;
	tail=0;
	for(int i=1;i<=gt;i++)
		if(!tin[i])
			q[++tail]=a[i][0];
	while(head<tail)
	{
		int u=q[head],v=q[head+1],op;
		printf("? %d %d\n",u,v);
		fflush(stdout);
		scanf("%d",&op);
		if(op==1) swap(u,v),swap(q[head],q[head+1]);
		int nw=g[u];
		swap(a[nw][0],a[nw][a[nw].size()-1]);
		a[nw].pop_back();
		if(a[nw].empty())
		{
			for(int i=h1[nw];i;i=e1[i].nxt)
			{
				int nv=e1[i].v;
				tin[nv]--;
				if(!tin[nv]) q[++tail]=a[nv][0];
			}
			head++;
		}
		else q[head]=a[nw][0];
	}
	printf("! %d",q[head]);
	return 0;
}