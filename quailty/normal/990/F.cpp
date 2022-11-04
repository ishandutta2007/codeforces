#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int s[MAXN],x[MAXN],y[MAXN];
vector<pair<int,int> > e[MAXN];
int vis[MAXN],res[MAXN];
void dfs(int u)
{
    vis[u]=1;
    for(auto &t:e[u])
    {
        int v=t.first,id=t.second;
        if(vis[v])continue;
        dfs(v);
        s[u]+=s[v];
        res[id]=(y[id]==v ? s[v] : -s[v]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        e[x[i]].push_back({y[i],i});
        e[y[i]].push_back({x[i],i});
    }
    dfs(1);
    if(s[1])printf("Impossible\n");
    else
    {
        printf("Possible\n");
        for(int i=1;i<=m;i++)
            printf("%d\n",res[i]);
    }
    return 0;
}