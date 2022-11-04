#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100005;
vector<int>ed[MAXN];
int r[MAXN],vis[MAXN],col[MAXN];
vector<pair<int,int> >e[MAXN];
int bfs(int st)
{
    queue<int>q;
    q.push(st);
    col[st]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i].first,c=e[u][i].second;
            if(col[v]<0)
            {
                col[v]=col[u]^c;
                q.push(v);
            }
            else if(col[v]!=(col[u]^c))return 0;
        }
    }
    return 1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&r[i]);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        while(x--)
        {
            int y;
            scanf("%d",&y);
            ed[y].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<2;j++)
            e[ed[i][j]].push_back(make_pair(ed[i][j^1],r[i]^1));
    memset(vis,0,sizeof(vis));
    memset(col,-1,sizeof(col));
    bool isok=1;
    for(int i=1;i<=m;i++)
        if(!vis[i])isok&=bfs(i);
    return 0*printf("%s",(isok ? "YES" : "NO"));
}