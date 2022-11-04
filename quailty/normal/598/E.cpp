#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[35][35][55];
void dfs(int n,int m,int k)
{
    if(k>n*m)return;
    if(dp[n][m][k]<INF)return;
    if(k==0 || k==m*n)
    {
        dp[n][m][k]=0;
        return;
    }
    for(int i=1;i<=m/2;i++)
        for(int j=0;j<=min(n*i,k);j++)
        {
            dfs(n,i,j);
            dfs(n,m-i,k-j);
            dp[n][m][k]=min(dp[n][m][k],dp[n][i][j]+dp[n][m-i][k-j]+n*n);
        }
     for(int i=1;i<=n/2;i++)
        for(int j=0;j<=min(m*i,k);j++)
        {
            dfs(i,m,j);
            dfs(n-i,m,k-j);
            dp[n][m][k]=min(dp[n][m][k],dp[i][m][j]+dp[n-i][m][k-j]+m*m);
        }
}
int main()
{
    memset(dp,INF,sizeof(dp));
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        dfs(n,m,k);
        printf("%d\n",dp[n][m][k]);
    }
    return 0;
}