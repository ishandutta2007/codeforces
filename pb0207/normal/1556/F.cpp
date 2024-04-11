#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=16,M=4782969,P=1e9+7;

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

int n,f[M+11],g[1<<N];

int win[N][N],a[N];

int gw[15][1<<15];

int npw[M+11],pw[M+11];

int go[1<<N];

int Zip(int S,int T)
{
    if(!(S&T))
        S^=(1<<n)-1;
    int ret=go[S]+go[T];
    return ret;
}

void inc(int &a,int b)
{
    a+=b;
    a>=P?a-=P:0;
}

signed main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]),g[1<<i]=i;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            win[i][j]=a[i]*qpow(a[i]+a[j],P-2)%P;
    int ALL=(1<<n)-1;
    for(int S=0;S<=ALL;S++)
        go[S]=go[S>>1]*3+(S&1);
    for(int i=0;i<n;i++)
    {
        gw[i][0]=1;
        for(int S=1;S<=ALL;S++)
            gw[i][S]=gw[i][S-(S&-S)]*win[i][g[S&(-S)]]%P;
    }
    for(int S=0;S<=ALL;S++)
    {
        for(int T=(ALL^S);;T=(T-1)&(ALL^S))
        {
            int i=g[S&(-S)];
            if(!S)
                npw[Zip(S,T)]=pw[Zip(S,T)]=1;
            else if((S&(-S))==S)
            {
                npw[Zip(S,T)]=(1-gw[i][T]+P)%P;
                pw[Zip(S,T)]=gw[i][T];
            }
            else
            {
                npw[Zip(S,T)]=npw[Zip(S^(1<<i),T)]*(1-gw[i][T]+P)%P;
                pw[Zip(S,T)]=pw[Zip(S^(1<<i),T)]*(gw[i][T])%P;
            }
            if(!T)
                break;
        }
    }
    int ans=0;;
    for(int i=0;i<n;i++)
        f[Zip(1<<i,1<<i)]=1;
    for(int S=0;S<=ALL;S++)
    {
        for(int T=S;;T=(T-1)&S)
        {
            if(!T)
                break;
            int ST=Zip(S,T);
            if(!f[ST])
                continue;
            for(int R=(ALL^S);;R=(R-1)&(ALL^S))
            {
                if(!R)
                    break;
                int nST=Zip(S^R,R);
                int pr=1;
                pr=npw[Zip(R,T)]*pw[Zip(R,S^T)]%P;
                inc(f[nST],f[ST]*pr%P);
            }
        }
    }
    for(int T=ALL;T;T=(T-1)&ALL)
        ans=(ans+f[Zip(ALL,T)])%P;
    printf("%lld\n",ans);
}