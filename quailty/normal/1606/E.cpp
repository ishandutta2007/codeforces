#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int Mod=998244353;
int C[MAXN][MAXN],pw[MAXN][MAXN];
int dp[MAXN][MAXN];
int solve(int n,int x)
{
    if(dp[n][x]>=0)return dp[n][x];
    if(n==0)return dp[n][x]=1;
    if(n==1)return dp[n][x]=0;
    if(x<n)return dp[n][x]=pw[x][n];
    int& res=dp[n][x];
    res=solve(n,x-n+1);
    for(int i=1;i<=n;i++)
        res=(res+1LL*C[n][i]%Mod*pw[n-1][i]%Mod*solve(n-i,x-n+1))%Mod;
    return res;
}
int main()
{
    for(int i=(C[0][0]=1);i<MAXN;i++)
        for(int j=(C[i][0]=1);j<MAXN;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    for(int i=0;i<MAXN;i++)
        for(int j=(pw[i][0]=1);j<MAXN;j++)
            pw[i][j]=1LL*i*pw[i][j-1]%Mod;
    int n,x;
    scanf("%d%d",&n,&x);
    memset(dp,-1,sizeof(dp));
    int res=solve(n,x);
    return 0*printf("%d\n",res);
}