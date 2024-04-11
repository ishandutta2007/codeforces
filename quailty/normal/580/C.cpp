#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int m,ans,a[MAXN];
struct Edge
{
    int to,next;
}edge[MAXN<<1];
int tot,head[MAXN];
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs(int u,int cat,int fa)
{
    if(cat>m)return;
    bool leaf=1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==fa)continue;
        leaf=0;
        dfs(v,(a[v] ? cat+1 : 0),u);
    }
    if(leaf)ans++;
}
int main()
{
    int n;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    init();
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    ans=0;
    dfs(1,a[1],0);
    printf("%d\n",ans);
    return 0;
}