#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1005;
const int Mod=1000000007;
int C[MAXN][MAXN],dp[65][MAXN];
int solve(int n,ll r,ll z)
{
    memset(dp,0,sizeof(dp));
    dp[60][0]=1;
    for(int i=59;i>=0;i--)
        for(int k=(z>>i&1);k<=n;k+=2)
            for(int j=0,tj=(r>>i&1)-k;j<=n;j++,tj=min(n,tj+2))
                if(tj>=0)dp[i][tj]=(dp[i][tj]+1LL*dp[i+1][j]*C[n][k])%Mod;
    int res=0;
    for(int j=0;j<=n;j++)
        res=(res+dp[0][j])%Mod;
    return res;
}
int main()
{
    for(int i=(C[0][0]=1);i<MAXN;i++)
        for(int j=(C[i][0]=1);j<MAXN;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    int n;
    ll l,r,z;
    scanf("%d%lld%lld%lld",&n,&l,&r,&z);
    return 0*printf("%d\n",(solve(n,r,z)-solve(n,l-1,z)+Mod)%Mod);
}