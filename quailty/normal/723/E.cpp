#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=205;
const int MAXM=205*205;
struct Edge
{
    int to,nxt;
    bool usd;
}edge[MAXM];
int head[MAXN],deg[MAXN],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void addedge(int u,int v)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    edge[tot].usd=0;
    head[u]=tot++;
}
vector<pair<int,int> >tmp;
vector<int>stk,path;
bool vis[MAXN],isok;
void dfs1(int u)
{
    vis[u]=1;
    for(int i=head[u];~i && !isok;i=edge[i].nxt)
    {
        if(edge[i].usd)continue;
        int v=edge[i].to;
        stk.push_back(i);
        if(!vis[v])
        {
            if(deg[v]%2==0)dfs1(v);
            else
            {
                path=stk;
                isok=1;
            }
        }
        stk.pop_back();
    }
}
void dfs2(int u)
{
    for(int &i=head[u];~i;i=edge[i].nxt)
        if(!edge[i].usd)
        {
            edge[i].usd=edge[i^1].usd=1;
            int tmp=i;
            dfs2(edge[i].to);
            path.push_back(tmp);
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,res=0;
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
            deg[u]++,deg[v]++;
        }
        for(int i=1;i<=n;i++)
            if(deg[i]%2==0)res++;
        printf("%d\n",res);
        tmp.clear();
        while(1)
        {
            bool odd=0;
            for(int i=1;i<=n;i++)
                if(deg[i]%2==1)
                {
                    memset(vis,0,sizeof(vis));
                    odd=1;
                    isok=0;
                    dfs1(i);
                    for(int i=0;i<(int)path.size();i++)
                    {
                        int id=path[i];
                        int u=edge[id^1].to,v=edge[id].to;
                        edge[id].usd=edge[id^1].usd=1;
                        tmp.push_back(make_pair(u,v));
                        deg[u]--,deg[v]--;
                    }
                }
            if(!odd)break;
        }
        for(int i=1;i<=n;i++)
        {
            path.clear();
            dfs2(i);
            for(int i=0;i<(int)path.size();i++)
            {
                int id=path[i];
                int u=edge[id^1].to,v=edge[id].to;
                edge[id].usd=edge[id^1].usd=1;
                tmp.push_back(make_pair(u,v));
                deg[u]--,deg[v]--;
            }
        }
        for(int i=0;i<(int)tmp.size();i++)
            printf("%d %d\n",tmp[i].first,tmp[i].second);
    }
    return 0;
}