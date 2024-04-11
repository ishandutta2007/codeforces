#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
vector<int> e[MAXN];
int dep[MAXN];
void dfs(int u,int fa)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dep[v]=dep[u]^1;
        dfs(v,u);
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
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    int cnt[2]={0,0};
    for(int i=1;i<=n;i++)
        cnt[dep[i]]++;
    printf("%lld\n",1LL*cnt[0]*cnt[1]-(n-1));
    return 0;
}