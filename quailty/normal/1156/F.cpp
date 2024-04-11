#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
const int Mod=998244353;
int fp(int a,int k)
{
    if(k<0)a=fp(a,Mod-2),k=-k;
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
int c[MAXN],f[MAXN],dp[MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        c[a]++;
    }
    for(int i=(f[0]=1);i<=n;i++)
        f[i]=1LL*i*f[i-1]%Mod;
    int res=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
        {
            dp[i][j]=(dp[i][j]+dp[i-1][j])%Mod;
            dp[i][j+1]=(dp[i][j+1]+1LL*c[i]*dp[i-1][j])%Mod;
            if(j<=n-2)res=(res+1LL*dp[i-1][j]*c[i]%Mod*(c[i]-1)%Mod*f[n-j-2])%Mod;
        }
    res=1LL*res*fp(f[n],-1)%Mod;
    printf("%d\n",res);
    return 0;
}