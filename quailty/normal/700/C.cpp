
 #include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int MAXM=30005;
const int INF=0x7fffffff;
struct Edge
{
    int to,nxt,cost,id;
    bool cut,usd;
}edge[MAXM<<1];
int head[MAXN],tot;
void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int id)
{
    edge[tot].to=v;
    edge[tot].nxt=head[u];
    edge[tot].cost=w;
    edge[tot].id=id;
    edge[tot].cut=0;
    edge[tot].usd=1;
    head[u]=tot++;
}
int Low[MAXN],DFN[MAXN],Index;
void Tarjan(int u,int pre)
{
    Low[u]=DFN[u]=++Index;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        if(!edge[i].usd || (i^pre)==1)continue;
        int v=edge[i].to;
        if(!DFN[v])
        {
            Tarjan(v,i);
            if(Low[u]>Low[v])Low[u]=Low[v];
            if(Low[v]>DFN[u])
            {
                edge[i].cut=1;
                edge[i^1].cut=1;
            }
        }
        else if(Low[u]>DFN[v])
            Low[u]=DFN[v];
    }
}
vector<int>path,tp;
int vis[MAXN];
bool getPath(int u,int &tar,vector<int>&path)
{
    if(u==tar)return 1;
    vis[u]=1;
    for(int i=head[u];~i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(!edge[i].usd || vis[v])continue;
        if(getPath(v,tar,path))
        {
            path.push_back(i);
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    init();
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        if(x!=y)
        {
            addedge(x,y,w,i);
            addedge(y,x,w,i);
        }
    }
    memset(vis,0,sizeof(vis));
    if(!getPath(s,t,path))return 0*printf("0\n0\n");
    int res=INF;
    vector<int>cut,tmp;
    for(int i=0;i<(int)path.size();i++)
    {
        tmp.clear();
        tmp.push_back(edge[path[i]].id);
        edge[path[i]].usd=edge[path[i]^1].usd=0;
        memset(DFN,0,sizeof(DFN));
        memset(vis,0,sizeof(vis));
        Index=0;
        Tarjan(s,-1);
        tp.clear();
        memset(vis,0,sizeof(vis));
        if(!getPath(s,t,tp))
        {
            if(res>edge[path[i]].cost)
            {
                res=edge[path[i]].cost;
                cut=tmp;
            }
        }
        else
        {
            int id=-1;
            for(int j=0;j<(int)tp.size();j++)
                if(edge[tp[j]].cut && (id==-1 || edge[tp[j]].cost<edge[id].cost))id=tp[j];
            if(id>=0)
            {
                tmp.push_back(edge[id].id);
                if(res>edge[path[i]].cost+edge[id].cost)
                {
                    res=edge[path[i]].cost+edge[id].cost;
                    cut=tmp;
                }
            }
        }
        edge[path[i]].usd=edge[path[i]^1].usd=1;
        for(int j=0;j<tot;j++)edge[j].cut=0;
    }
    if(res==INF)printf("-1\n");
    else
    {
        printf("%d\n%d\n",res,(int)cut.size());
        for(int i=0;i<(int)cut.size();i++)printf("%d ",cut[i]);
    }
    return 0;
}