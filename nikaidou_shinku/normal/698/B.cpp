#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int a[MAXN];
struct Edge
{
    int to,nxt;
}edge[MAXN<<1];
int head[MAXN],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
vector<pair<int,int> >r;
int vis[MAXN],dep[MAXN],time_tag;
void dfs(int u,int la,int pre,int d)
{
    if(vis[u])
    {
        if(vis[pre]>vis[u])r.push_back(make_pair(u,d-dep[u]));
        return;
    }
    vis[u]=++time_tag;
    dep[u]=d;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(i!=(la^1))dfs(v,i,u,d+1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i==a[i])r.push_back(make_pair(i,1));
        else addedge(i,a[i]),addedge(a[i],i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i,-1,0,0);
    int rt=-1;
    for(int i=0;i<(int)r.size();i++)
        if(r[i].second==1)rt=i;
    for(int i=0;i<(int)r.size();i++)
        a[r[i].first]=r[max(0,rt)].first;
    printf("%d\n",(int)r.size()-(rt>=0));
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}