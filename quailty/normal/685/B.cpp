#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300005;
vector<int>e[MAXN];
int par[MAXN],dep[MAXN],cnt[MAXN],res[MAXN];
void dfs1(int u,int fa)
{
    dep[u]=dep[fa]+1,cnt[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs1(v,u);
        cnt[u]+=cnt[v];
    }
}
void dfs2(int u)
{
    int mx=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs2(v);
        if(cnt[v]>cnt[e[u][mx]])mx=i;
    }
    if((int)e[u].size())
    {
        res[u]=res[e[u][mx]];
        while(res[u]!=u)
        {
            if(cnt[res[u]]>=cnt[u]-cnt[res[u]])break;
            res[u]=par[res[u]];
        }
    }
    else res[u]=u;
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&par[i]);
        e[par[i]].push_back(i);
    }
    dfs1(1,0);
    dfs2(1);
    while(q--)
    {
        int v;
        scanf("%d",&v);
        printf("%d\n",res[v]);
    }
    return 0;
}