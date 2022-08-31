#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
    int v,nxt;
}e[500005];
int n,m,h[100005],t=0,f[100005],a[100005],tans[1000005],tt=0;
int tin[100005],vis[100005];
void add(int u,int v)
{
	//printf("u=%d,v=%d\n",u,v);
	tin[u]++,tin[v]++;
    e[++t].v=v;
    e[t].nxt=h[u];
    h[u]=t;
}
int find(int x)
{
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
void link(int x,int y)
{
	int tx=x,ty=y;
    x=find(x),y=find(y);
    if(x==y) return;
    f[x]=y;
    add(tx,ty);
    add(ty,tx);
}
void dfs(int u,int fa)
{
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(tin[v]==1&&a[v]==0) continue;
        if(v==fa) continue;
        tans[++tt]=v;
        a[v]^=1;
        dfs(v,u);
        if(a[v])
        {
            tans[++tt]=u;
            a[u]^=1;
            tans[++tt]=v;
        	a[v]^=1;
        }
        tans[++tt]=u;
        a[u]^=1;
    }
}
bool dfs2(int u,int fa)
{
	vis[u]=1;
	int ans=0;
	if(a[u]==1) ans=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(dfs2(v,u)) ans=1;
	}
	return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		f[i]=i; 
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        link(u,v);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int cnt=0,s;
    for(int i=1;i<=n;i++)
    	if(!vis[i])
    	{
    		if(dfs2(i,0)) cnt++,s=i;
    		if(cnt>1)
    		{
    			printf("-1");
    			return 0;
			}
		}
	if(cnt==0)
	{
		printf("0");
		return 0;
	}
    tans[++tt]=s;
    a[s]^=1;
    dfs(s,0);
    if(a[s])
    {
        tans[++tt]=e[h[s]].v;
        tans[++tt]=s;
        tans[++tt]=e[h[s]].v;
    }
    printf("%d\n",tt);
    for(int i=1;i<=tt;i++)
        printf("%d ",tans[i]);
    return 0;
}