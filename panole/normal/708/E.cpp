#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int n,m,p,k,C[100010],inv[100010],sum[1510][1510],pm[100010],Pm[100010],P,Sum[100010],pre[100010];

int quickmi(int a,int b)
{
    int t=1;
    for (; b; b>>=1,a=1ll*a*a%mod)
        if (b&1) t=1ll*t*a%mod;
    return t;
}

int main()
{
    for (int i=1; i<=100000; i++) inv[i]=quickmi(i,mod-2);
    scanf("%d%d%d%d",&n,&m,&p,&k),p=1ll*p*quickmi(k,mod-2)%mod,scanf("%d",&k);
    pm[0]=Pm[0]=1,P=(mod+1-p)%mod,C[0]=1;
    for (int i=1; i<=100000; i++) pm[i]=1ll*pm[i-1]*p%mod,Pm[i]=1ll*Pm[i-1]*P%mod;
    for (int i=1; i<=k; i++) C[i]=1ll*C[i-1]*(k-i+1)%mod*inv[i]%mod;
    pre[0]=0;
    for (int i=1; i<=m; i++) pre[i]=(pre[i-1]+1ll*C[i-1]*pm[i-1]%mod*Pm[k-i+1])%mod;
    for (int i=2; i<=m; i++) inv[i]=1ll*quickmi(pre[i]-pre[i-1]+mod,mod-2)*(pre[i-1]-pre[i-2]+mod)%mod;
    for (int i=1; i<=m; i++) 
        for (int j=i; j<=m; j++)
            sum[1][j]=(sum[1][j]+1ll*(pre[i]-pre[i-1]+mod)*(pre[m-j+1]-pre[m-j]+mod))%mod;
    for (int i=2; i<=n+1; i++)
    {
        Sum[0]=0;
        for (int j=1; j<=m; j++) Sum[j]=(Sum[j-1]+sum[i-1][j]>=mod?Sum[j-1]+sum[i-1][j]-mod:Sum[j-1]+sum[i-1][j]);
        if (i==n+1) return printf("%d\n",Sum[m]),0;
        for (int j=1,nw=0; j<=m; j++)
        {
            sum[i][j]=1ll*(Sum[m]-Sum[j-1]-Sum[m-j])*pre[j]%mod*(pre[m-j+1]-pre[m-j])%mod;
            if (sum[i][j]<0) sum[i][j]+=mod;
            if (j>1) nw=1ll*nw*inv[m-j+2]%mod,nw=(nw+1ll*pre[j-1]*(pre[m-j+1]-pre[m-j]+mod)%mod*sum[i-1][j-1])%mod;
            sum[i][j]=(sum[i][j]+nw>=mod?sum[i][j]+nw-mod:sum[i][j]+nw);
        }
    }
    return 0;
}