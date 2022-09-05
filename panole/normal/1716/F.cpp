#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int C[2010],T,s[2010][2010],n,m,k,inv[2010];

int quickmi(int a,int b)
{
    int t=1;
    for (; b; b>>=1,a=1ll*a*a%mod)
        if (b&1) t=1ll*t*a%mod;
    return t;
}

int main()
{
    s[0][0]=1;
    for (int i=1; i<=2000; i++)
    {
        s[i][0]=0;
        for (int j=1; j<=i; j++)
            s[i][j]=(s[i-1][j-1]+1ll*j*s[i-1][j])%mod;
    }
    for (int i=1; i<=2000; i++) inv[i]=quickmi(i,mod-2);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i=0,nw=1,mi=quickmi(m,n),jc=1,iv=quickmi(m,mod-2); i<=k; i++)
        {
            C[i]=1ll*nw*mi%mod*jc%mod;
            nw=1ll*nw*(n-i)%mod*inv[i+1]%mod;
            mi=1ll*mi*(m+1>>1)%mod*iv%mod;
            jc=1ll*jc*(i+1)%mod;
        }
        int ans=0;
        for (int i=0; i<=k; i++) ans=(ans+1ll*s[k][i]*C[i])%mod;
        printf("%d\n",ans);
    }
    return 0;
}