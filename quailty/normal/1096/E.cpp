#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=6005;
const int Mod=998244353;
int C[MAXN][MAXN];
ll fp(ll a,ll k)
{
    if(k<0)
    {
        a=fp(a,Mod-2);
        k=-k;
    }
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
int solve(int n,int k,int s)
{
    if(n==0)return s==0;
    int res=0;
    for(int i=0;i<=n && i*(k+1)<=s;i++)
    {
        int t=1LL*C[n+s-i*(k+1)-1][n-1]*C[n][i]%Mod;
        if(~i&1)res=(res+t)%Mod;
        else res=(res+Mod-t)%Mod;
    }
    return res;
}
int main()
{
    for(int i=(C[0][0]=1);i<MAXN;i++)
        for(int j=(C[i][0]=1);j<MAXN;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
    int p,s,r;
    scanf("%d%d%d",&p,&s,&r);
    ll up=0,dw=C[p+s-r-1][p-1];
    for(int i=r;i<=s;i++)
        for(int j=1;j<=p && i*j<=s;j++)
            up=(up+fp(j,-1)*solve(p-j,i-1,s-i*j)%Mod*C[p-1][j-1])%Mod;
    printf("%lld\n",up*fp(dw,-1)%Mod);
    return 0;
}