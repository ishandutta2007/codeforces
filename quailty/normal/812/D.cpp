#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int rt[MAXN],pre[MAXN],dp[MAXN];
vector<int> e[MAXN];
int in[MAXN],out[MAXN],time_tag;
void dfs(int u)
{
    in[u]=++time_tag,dp[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs(v);
        dp[u]+=dp[v];
    }
    out[u]=time_tag;
}
int main()
{
    int n,m,k,q;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<=n;i++)
        rt[i]=1;
    for(int i=1;i<=k;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(pre[b])
        {
            e[pre[b]].push_back(a);
            rt[a]=0;
        }
        pre[b]=a;
    }
    for(int i=1;i<=n;i++)
        if(rt[i])dfs(i);
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(pre[y])
        {
            int t=pre[y];
            if(in[t]>=in[x] && in[t]<=out[x])
                printf("%d\n",dp[x]);
            else printf("0\n");
        }
        else printf("0\n");
    }
    return 0;
}