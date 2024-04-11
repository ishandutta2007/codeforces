#include<bits/stdc++.h>
using namespace std;

int n,mod,f[5010][5010],mi[5010][5010],g[5010][5010],jc[5010],inv[5010];

int quickmi(int a,int b)
{
    int t=1;
    for (; b; b>>=1,a=1ll*a*a%mod)
        if (b&1) t=1ll*t*a%mod;
    return t;
}

int main()
{
    scanf("%d%d",&n,&mod);
    jc[0]=inv[0]=1;
    for (int i=1; i<=n; i++) jc[i]=1ll*jc[i-1]*i%mod,inv[i]=quickmi(jc[i],mod-2);
    f[0][0]=1;
    for (int i=1; i<=n; i++)
    {
        f[i][0]=0;
        for (int j=1; j<=i; j++)
            f[i][j]=(f[i-1][j-1]+1ll*(i-1+j)*f[i-1][j])%mod;
    }
    for (int i=0; i<=n; i++)
    {
        g[i][0]=1;
        for (int j=1; j<=i; j++)
            g[i][j]=1ll*g[i][j-1]*(i-j+1)%mod;
        mi[i][0]=1;
        for (int j=1; j<=n; j++)
            mi[i][j]=1ll*mi[i][j-1]*i%mod;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=i&&j<=n-i; j++)
            ans=(ans+1ll*f[i][j]*mi[n-1][j]%mod*g[n-i][j]%mod*mi[i][n-i-j]%mod*jc[n]%mod*inv[i]%mod*inv[n-i])%mod;
    printf("%d\n",ans);
    return 0;
}