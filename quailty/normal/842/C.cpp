#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int a[MAXN],dp[MAXN],res[MAXN];
vector<int> e[MAXN],ok[MAXN];
int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}
void dfs(int u,int f)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==f)continue;
        dp[v]=gcd(dp[u],a[v]);
        ok[v].push_back(dp[u]);
        for(int i=0;i<(int)ok[u].size();i++)
            ok[v].push_back(gcd(ok[u][i],a[v]));
        sort(ok[v].begin(),ok[v].end());
        ok[v].erase(unique(ok[v].begin(),ok[v].end()),ok[v].end());
        dfs(v,u);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dp[1]=a[1];
    ok[1].push_back(0);
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        res[i]=dp[i];
        if(!ok[i].empty())
            res[i]=max(res[i],ok[i].back());
    }
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    return 0;
}