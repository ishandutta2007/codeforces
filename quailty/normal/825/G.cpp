#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
int col[MAXN],dep[MAXN],fa[MAXN][20],mi[MAXN][20];
vector<int> e[MAXN];
void dfs(int u)
{
    mi[u][0]=u;
    for(int i=1;i<20;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
        mi[u][i]=min(mi[u][i-1],mi[fa[u][i-1]][i-1]);
    }
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa[u][0])continue;
        fa[v][0]=u,dep[v]=dep[u]+1;
        dfs(v);
    }
}
inline pair<int,int> lca(int u,int v)
{
    int res=1e9;
    if(dep[u]<dep[v])swap(u,v);
    for(int i=0,d=dep[u]-dep[v];d;i++,d>>=1)
        if(d&1)res=min(res,mi[u][i]),u=fa[u][i];
    if(u==v)return make_pair(u,min(res,u));
    for(int i=19;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
        {
            res=min({res,mi[u][i],mi[v][i]});
            u=fa[u][i],v=fa[v][i];
        }
    return make_pair(fa[u][0],min({res,u,v,fa[u][0]}));
}
inline int go_up(int x)
{
    for(int i=19;i>=0;i--)
        if(col[fa[x][i]])
            x=fa[x][i];
    return fa[x][0];
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    for(int i=1,las=0,mi=n,b;i<=q;i++)
    {
        int t,x;
        scanf("%d%d",&t,&x);
        x=(x+las)%n+1;
        if(i==1)col[x]=1,mi=b=x;
        else if(t==1)
        {
            if(col[x])continue;
            int t=go_up(b);
            while(x!=t)
            {
                if(dep[x]<dep[t])swap(x,t);
                if(col[x])break;
                col[x]=1;
                mi=min(mi,x);
                x=fa[x][0];
            }
            col[x]=1;
            mi=min(mi,x);
        }
        else printf("%d\n",las=min(mi,lca(b,x).second));
    }
    return 0;
}