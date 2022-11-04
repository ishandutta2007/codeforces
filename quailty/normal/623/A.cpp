#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=505;
const int MAXM=250005;
char res[MAXN];
struct Edge
{
    int to,nxt;
}edge[MAXM];
int head[MAXN],tot;
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    head[u]=tot++;
}
int vis[MAXN];
bool bfs(int st)
{
    queue<int>q;
    vis[st]=-1;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(vis[v]==vis[u])return 0;
            if(vis[v]==-vis[u])continue;
            vis[v]=-vis[u];
            q.push(v);
        }
    }
    return 1;
}
bool g[MAXN][MAXN];
int d[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u][v]=1;
        g[v][u]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j && !g[i][j])
            {
                addedge(i,j);
                d[i]++;
            }
    bool isok=1;
    for(int i=1;i<=n;i++)
        if(!vis[i] && d[i]>0)
            isok&=bfs(i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
            {
                if(!g[i][j] && vis[i]*vis[j]>=0)isok=0;
                if(g[i][j] && vis[i]*vis[j]<0)isok=0;
            }
    if(isok)
    {
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==-1)res[i]='a';
            else if(vis[i]==1)res[i]='c';
            else res[i]='b';
        }
        if(isok)printf("Yes\n%s\n",res+1);
        else printf("No\n");
    }
    else printf("No\n");
    return 0;
}