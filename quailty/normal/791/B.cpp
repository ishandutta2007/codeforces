#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=150005;
int vis[MAXN];
vector<int>e[MAXN];
void dfs(int u,vector<int>&t)
{
    vis[u]=1;
    t.push_back(u);
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(!vis[v])dfs(e[u][i],t);
    }
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
    {
        if(vis[i])continue;
        vector<int>t;
        dfs(i,t);
        int v=(int)t.size(),c=0;
        for(int j=0;j<(int)t.size();j++)
            c+=(int)e[t[j]].size();
        if(c!=1LL*v*(v-1))return 0*printf("NO");
    }
    return 0*printf("YES");
}