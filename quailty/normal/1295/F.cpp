#include <bits/stdc++.h>
using namespace std;
const int MAXN=55;
const int Mod=998244353;
inline int fp(int a,int k)
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
int fac_inv[MAXN];
inline int C(int n,int k)
{
    int res=fac_inv[k];
    for(int i=0;i<k;i++)
        res=1LL*res*(n-i)%Mod;
    return res;
}
int l[MAXN],r[MAXN],x[MAXN<<1];
int dp[MAXN][MAXN<<1];
int main()
{
    for(int i=(fac_inv[0]=1);i<MAXN;i++)
        fac_inv[i]=1LL*fac_inv[i-1]*fp(i,-1)%Mod;
    int n,seg=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]),r[i]++;
        x[++seg]=l[i],x[++seg]=r[i];
    }
    sort(x+1,x+seg+1);
    seg=unique(x+1,x+seg+1)-(x+1);
    for(int i=1;i<=n;i++)
    {
        l[i]=lower_bound(x+1,x+seg+1,l[i])-x;
        r[i]=lower_bound(x+1,x+seg+1,r[i])-x;
    }
    for(int j=1;j<=seg;j++)
        dp[0][j]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=l[i];j<r[i];j++)
            for(int k=i;k>=1;k--)
            {
                if(j<l[k] || j>=r[k])break;
                int dx=x[j+1]-x[j],dy=i-k+2;
                dp[i][j]=(dp[i][j]+1LL*C(dx+dy-2,dy-1)*dp[k-1][j+1])%Mod;
            }
        for(int j=seg-1;j>=1;j--)
            dp[i][j]=(dp[i][j]+dp[i][j+1])%Mod;
    }
    int res=dp[n][1];
    for(int i=1;i<=n;i++)
        res=1LL*res*fp(x[r[i]]-x[l[i]],-1)%Mod;
    return 0*printf("%d\n",res);
}