#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const int MAXN=105;
vector<pair<int,int> > e[MAXN];
int fa[MAXN],id[MAXN];
db t[MAXN];
void dfs(int u)
{
    db now=t[u],add=2.0/e[u].size();
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        if(v==fa[u])continue;
        fa[v]=u,id[v]=e[u][i].second;
        t[v]=fmod((now+=add)+1.0,2.0);
        dfs(v);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(make_pair(v,i));
        e[v].push_back(make_pair(u,i));
    }
    dfs(1);
    printf("%d\n",n-1);
    for(int i=2;i<=n;i++)
    {
        printf("%d %d ",1,id[i]);
        if(t[i]<1)printf("%d %d %.12f\n",i,fa[i],t[i]);
        else printf("%d %d %.12f\n",fa[i],i,t[i]-1);
    }
    return 0;
}