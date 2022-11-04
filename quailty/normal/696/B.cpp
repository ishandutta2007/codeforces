#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef double db;
const int MAXN=100005;
vector<int>e[MAXN];
int sz[MAXN];
db dp[MAXN];
void dfs1(int u)
{
    sz[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs1(v);
        sz[u]+=sz[v];
    }
}
void dfs2(int u)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dp[v]=dp[u]+(sz[u]-sz[v]-1.0)/2.0+1.0;
        dfs2(v);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        e[p].push_back(i);
    }
    dfs1(1);
    dp[1]=1;
    dfs2(1);
    for(int i=1;i<=n;i++)
        printf("%.10f ",dp[i]);
    return 0;
}