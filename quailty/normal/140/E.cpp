#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000005;
const int MAXL=5005;
int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}
int d[MAXL][MAXL],pm[MAXL],fc[MAXL];
int l[MAXN],dp[MAXN],cof[MAXL],las[MAXL];
void build(int n,int m,int p)
{
    for(int i=(d[0][0]=1);i<MAXL;i++)
        for(int j=1;j<=i;j++)
            d[i][j]=(1LL*(j-(i>1))*d[i-1][j]+d[i-1][j-1])%p;
    for(int i=(pm[0]=1);i<min(m+1,MAXL);i++)
        pm[i]=1LL*pm[i-1]*(m-i+1)%p;
    for(int i=(fc[0]=1);i<min(m+1,MAXL);i++)
        fc[i]=1LL*fc[i-1]*i%p;
}
void solve(int n,int m,int p)
{
    for(int i=1;i<=n;i++)
        scanf("%d",&l[i]);
    for(int i=(dp[0]=1);i<=n;i++)
    {
        for(int j=1;j<=l[i];j++)
        {
            dp[i]=(dp[i]+1LL*dp[i-1]*pm[j]%p*d[l[i]][j]%p)%p;
            if(las[j]==i-1)dp[i]=(dp[i]-1LL*cof[j]*fc[j]%p*d[l[i]][j]%p+p)%p;
        }
        for(int j=1;j<=l[i];j++)
        {
            if(las[j]==i-1)cof[j]=1LL*cof[j]*fc[j]%p*d[l[i]][j]%p;
            else cof[j]=0;
            cof[j]=(1LL*dp[i-1]*pm[j]%p*d[l[i]][j]%p-cof[j]+p)%p;
            las[j]=i;
        }
    }
}
int main()
{
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    build(n,m,p);
    solve(n,m,p);
    printf("%d\n",dp[n]);
    return 0;
}