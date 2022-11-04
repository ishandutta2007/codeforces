#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1505;
const int Mod=1000000007;
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
int p[MAXN],pp[MAXN],dp[2][MAXN],sum[MAXN];
int main()
{
    int n,m,a,b,k;
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&k);
    int c=1;
    for(int i=0;i<=min(m,k);i++)
    {
        p[i]=1LL*c*fp(a,i)%Mod*fp(b-a,k-i)%Mod*fp(b,-k)%Mod;
        c=1LL*c*(k-i)%Mod*fp(i+1,-1)%Mod;
    }
    memcpy(pp,p,sizeof(p));
    for(int i=1;i<=m;i++)
        pp[i]=(pp[i]+pp[i-1])%Mod;
    int now=0,la=1;
    for(int j=1;j<=m;j++)
        dp[now][j]=1;
    for(int i=1;i<=n;i++)
    {
        swap(now,la);
        for(int j=0;j<=m;j++)
            sum[j]=((j ? sum[j-1] : 0)+1LL*p[j]*dp[la][m-j])%Mod;
        for(int j=0;j<m;j++)
        {
            int tmp=(1LL*pp[m-j-1]*(dp[la][m-j]-dp[la][m]+Mod)+sum[m-j-1])%Mod;
            dp[now][j+1]=(dp[now][j]+1LL*tmp*p[j])%Mod;
        }
    }
    printf("%d\n",dp[now][m]);
    return 0;
}