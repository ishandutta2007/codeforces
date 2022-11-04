#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int DEG=17;
vector<int> e[MAXN];
int time_tag,in[MAXN],out[MAXN],dep[MAXN];
int fa[MAXN][DEG];
void dfs(int u)
{
    in[u]=++time_tag;
    for(int i=1;i<DEG;i++)
        fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dep[v]=dep[u]+1;
        fa[v][0]=u;
        dfs(v);
    }
    out[u]=time_tag;
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    for(int i=0,d=dep[u]-dep[v];d;i++,d>>=1)
        if(d&1)u=fa[u][i];
    if(u==v)return u;
    for(int i=DEG-1;i>=0;i--)
        if(fa[u][i]!=fa[v][i])
            u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int dis(int u,int v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        e[p].push_back(i);
    }
    dfs(1);
    while(q--)
    {
        int k[3];
        for(int i=0;i<3;i++)
            scanf("%d",&k[i]);
        bool flag=0;
        for(int i=0;i<3;i++)
        {
            int u=k[i],v=k[(i+1)%3],w=k[(i+2)%3],f=lca(u,v);
            if((lca(u,w)==w || lca(v,w)==w) && in[w]>=in[f] && in[w]<=out[f])
            {
                printf("%d\n",max(dis(u,w),dis(v,w))+1);
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            flag=0;
            for(int i=0;i<3;i++)
            {
                int u=k[i],v=k[(i+1)%3],w=k[(i+2)%3],f=lca(u,v);
                if(in[w]<in[f] || in[w]>out[f])
                {
                    printf("%d\n",max({dis(u,f),dis(v,f),dis(w,f)})+1);
                    flag=1;
                    break;
                }
            }
        }
        if(!flag)
        {
            int u=k[0],v=k[1],w=k[2],f=lca(u,v);
            printf("%d\n",max({dis(u,f),dis(v,f),dis(w,f)})+1);
        }
    }
    return 0;
}