#include<bits/stdc++.h>
using namespace std;
const int MAXK=5005;
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
int dp[MAXK][MAXK];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    dp[0][0]=1;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=min(n,i);j++)
            dp[i][j]=(1LL*j*dp[i-1][j]+1LL*(n-j+1)*dp[i-1][j-1])%Mod;
    int res=0;
    for(int j=1;j<=min(n,k);j++)
        res=(res+1LL*fp(m,-j)*dp[k][j])%Mod;
    return 0*printf("%d\n",res);
}