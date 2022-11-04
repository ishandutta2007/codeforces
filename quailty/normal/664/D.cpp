#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int vis[MAXN],col[MAXN],res[MAXN];
vector<pair<int,int> >e[MAXN];
int bfs(int st)
{
    vector<int>now;
    queue<int>q;
    q.push(st);
    col[st]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        now.push_back(u);
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i].first,c=e[u][i].second;
            if(!col[v])
            {
                col[v]=col[u]*c;
                q.push(v);
            }
            else if(col[v]!=col[u]*c)return 0;
        }
    }
    int tot=0;
    for(int i=0;i<(int)now.size();i++)
        tot+=(col[now[i]]>0);
    if(tot>(int)now.size()-tot)
        for(int i=0;i<(int)now.size();i++)
            col[now[i]]*=-1;
    return 1;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        char c[5];
        scanf("%d%d%s",&u,&v,c);
        e[u].push_back(make_pair(v,(*c=='B' ? 1 : -1)));
        e[v].push_back(make_pair(u,(*c=='B' ? 1 : -1)));
    }
    int isok=1,mi=INF;
    for(int i=1;i<=n;i++)
        if(!vis[i])isok&=bfs(i);
    if(isok)
    {
        int tot=0;
        for(int i=1;i<=n;i++)
            tot+=(col[i]>0);
        mi=min(mi,tot);
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)e[i].size();j++)
            e[i][j].second*=-1;
    memset(vis,0,sizeof(vis));
    memcpy(res,col,sizeof(col));
    memset(col,0,sizeof(col));
    isok=1;
    for(int i=1;i<=n;i++)
        if(!vis[i])isok&=bfs(i);
    if(isok)
    {
        int tot=0;
        for(int i=1;i<=n;i++)
            tot+=(col[i]>0);
        if(tot<mi)
        {
            memcpy(res,col,sizeof(col));
            mi=tot;
        }
    }
    if(mi==INF)printf("-1\n");
    else
    {
        printf("%d\n",mi);
        for(int i=1;i<=n;i++)
            if(res[i]>0)printf("%d ",i);
    }
    return 0;
}