#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
const int Mod=998244353;
int a[MAXN],dp[MAXN],C[MAXN][MAXN];
int main()
{
    for(int i=(C[0][0]=1);i<MAXN;i++)
        for(int j=(C[i][0]=1);j<MAXN;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dp[n+1]=1;
    for(int i=n;i>=1;i--)
        if(a[i]>0)for(int j=i+a[i]+1;j<=n+1;j++)
            dp[i]=(dp[i]+1LL*dp[j]*C[j-i-1][a[i]])%Mod;
    int res=0;
    for(int i=1;i<=n;i++)
        res=(res+dp[i])%Mod;
    printf("%d\n",res);
    return 0;
}