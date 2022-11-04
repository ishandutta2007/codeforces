#include<bits/stdc++.h>
using namespace std;
const int MAXN=(1<<17)+5;
vector<pair<int,int>> e[MAXN];
int res_node[MAXN],res_edge[MAXN];
void dfs(int u,int f,int& c,int d,int n)
{
    for(auto& [v,w] : e[u])
    {
        if(v==f)continue;
        ++c;
        if(d)res_node[v]=c+n,res_edge[w]=c;
        else res_node[v]=c,res_edge[w]=c+n;
        dfs(v,u,c,d^1,n);
    }
}
int solve()
{
    int p;
    scanf("%d",&p);
    int n=(1<<p);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].emplace_back(v,i);
        e[v].emplace_back(u,i);
    }
    res_node[1]=n;
    int cnt=0;
    dfs(1,0,cnt,0,n);
    printf("1\n");
    for(int i=1;i<=n;i++)
        printf("%d ",res_node[i]);
    printf("\n");
    for(int i=1;i<n;i++)
        printf("%d ",res_edge[i]);
    printf("\n");
    for(int i=1;i<=n;i++)
        e[i].clear();
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}