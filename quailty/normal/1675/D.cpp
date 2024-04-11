#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN],p[MAXN];
void dfs(int u,int fa,int top)
{
    p[top].push_back(u);
    int c=0;
    for(auto v : e[u])
    {
        if(v==fa)continue;
        if(!c)dfs(v,u,top),c=1;
        else dfs(v,u,v);
    }
}
int solve()
{
    int n,rt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        if(p==i)rt=i;
        else
        {
            e[i].push_back(p);
            e[p].push_back(i);
        }
    }
    dfs(rt,0,rt);
    vector<int> path_top;
    for(int i=1;i<=n;i++)
        if(!p[i].empty())path_top.push_back(i);
    printf("%zu\n",path_top.size());
    for(auto top : path_top)
    {
        printf("%zu\n",p[top].size());
        for(auto u : p[top])
            printf("%d ",u);
        printf("\n");
    }
    for(int i=1;i<=n;i++)
        e[i].clear(),p[i].clear();
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}