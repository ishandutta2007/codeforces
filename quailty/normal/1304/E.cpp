#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int STEP=17;
const int INF=0x3f3f3f3f;
vector<int> e[MAXN];
int dep[MAXN],fa[MAXN][STEP];
void dfs(int u,int f)
{
    dep[u]=dep[f]+1,fa[u][0]=f;
    for(int i=1;i<STEP;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(auto &v:e[u])
        if(v!=f)dfs(v,u);
}
inline int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i=0,d=dep[u]-dep[v];d>0;i++,d>>=1)
        if(d&1)u=fa[u][i];
    if(u==v)return u;
    for(int i=STEP-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
            u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
inline int dis(int u,int v)
{
    int p=lca(u,v);
    return dep[u]+dep[v]-2*dep[p];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int x,y,a,b,k;
        scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        int mi[2]={INF,INF},len=dis(a,b);
        mi[len&1]=min(mi[len&1],len);
        len=min(dis(a,x)+dis(b,y),dis(a,y)+dis(b,x))+1;
        mi[len&1]=min(mi[len&1],len);
        printf("%s\n",(mi[k&1]<=k ? "YES" : "NO"));
    }
    return 0;
}