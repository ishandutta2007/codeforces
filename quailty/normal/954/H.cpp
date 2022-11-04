#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int Mod=1000000007;
const int Inv=500000004;
int a[MAXN],pre[MAXN],dp[MAXN][MAXN],now[2*MAXN],res[2*MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%d",&a[i]);
    pre[1]=1;
    for(int i=2;i<=n;i++)
        pre[i]=1LL*a[i-1]*pre[i-1]%Mod;
    dp[n][0]=1;
    for(int i=n-1;i>=1;i--)
    {
        dp[i][0]=1;
        for(int j=0;j<=n-i-1;j++)
            dp[i][j+1]=1LL*a[i]*dp[i+1][j]%Mod;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n-i;j++)
            res[j]=(res[j]+1LL*pre[i]*dp[i][j])%Mod;
    for(int i=2;i<=n;i++)
    {
        for(int i=2*n-1;i>=1;i--)
            swap(now[i-1],now[i]);
        now[1]=1;
        for(int j=0;j<=n-i;j++)
            now[j+2]=(now[j+2]+1LL*(a[i-1]-1)*dp[i][j])%Mod;
        for(int j=1;j<=2*n-2;j++)
            res[j]=(res[j]+1LL*pre[i]*now[j])%Mod;
    }
    for(int i=1;i<=2*n-2;i++)
        res[i]=1LL*res[i]*Inv%Mod;
    for(int i=1;i<=2*n-2;i++)
        printf("%d%c",res[i]," \n"[i==2*n-2]);
    return 0;
}