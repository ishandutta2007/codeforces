#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
const int OST=30;
const int Mod=1000000007;
int dp[MAXN][60];
vector<int>e[MAXN];
void dfs(int u,int fa,int k)
{
    dp[u][OST-1]=dp[u][OST+k]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u,k);
        int tmp[60];
        memset(tmp,0,sizeof(tmp));
        for(int i=-k+1;i<=k;i++)
            for(int j=-k;j<k;j++)
            {
                if(i+j>=0)tmp[max(i,j)+OST]=(tmp[max(i,j)+OST]+1LL*dp[u][i+OST]*dp[v][j+1+OST])%Mod;
                else tmp[min(i,j)+OST]=(tmp[min(i,j)+OST]+1LL*dp[u][i+OST]*dp[v][j+1+OST])%Mod;
            }
        memcpy(dp[u],tmp,sizeof(tmp));
    }
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    k++;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0,k);
    int res=0;
    for(int i=0;i<=k;i++)
        res=(res+dp[1][i+OST])%Mod;
    return 0*printf("%d",res);
}