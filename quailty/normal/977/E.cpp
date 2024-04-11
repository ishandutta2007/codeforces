#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN],c[MAXN];
int cnt,vis[MAXN];
void dfs(int u)
{
    vis[u]=1;
    c[cnt].push_back(u);
    for(auto &v:e[u])
        if(!vis[v])dfs(v);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])cnt++,dfs(i);
    int res=0;
    for(int i=1;i<=cnt;i++)
    {
        int isok=((int)c[i].size()>2);
        for(auto &u:c[i])
            isok&=((int)e[u].size()==2);
        res+=isok;
    }
    printf("%d\n",res);
    return 0;
}