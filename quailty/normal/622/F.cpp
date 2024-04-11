#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXK=1000005;
const ll Mod=1000000007;
ll fp(ll a,ll k)
{
    if(k<0)k=-k,a=fp(a,Mod-2);
    ll res=1LL;
    while(k>0)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
ll fac[MAXK],inv[MAXK];
void build()
{
    for(int i=(fac[0]=1);i<MAXK;i++)
        fac[i]=i*fac[i-1]%Mod;
    inv[MAXK-1]=fp(fac[MAXK-1],Mod-2);
    for(int i=MAXK-2;i>=0;i--)
        inv[i]=(i+1)*inv[i+1]%Mod;
}bool np[MAXK];
int pri[MAXK];
ll f[MAXK];
void sieve(int k)
{
    f[0]=0,f[1]=1;
    for(int i=2;i<=k+1;i++)
        np[i]=0;
    int tot=0;
    for(int i=2;i<=k+1;i++)
    {
        if(!np[i])
        {
            pri[tot++]=i;
            f[i]=fp(i,k);
        }
        for(int j=0;j<tot;j++)
        {
            if(i*pri[j]>k+1)break;
            np[i*pri[j]]=1;
            f[i*pri[j]]=f[i]*f[pri[j]]%Mod;
        }
    }
    for(int i=1;i<=k+1;i++)
        f[i]=(f[i]+f[i-1])%Mod;
}
ll pre[MAXK],suf[MAXK];
void powsum(int k,int n)
{
    sieve(k);
    if(n<=k+1)
    {
        printf("%I64d\n",f[n]);
        return;
    }
    for(int i=(pre[0]=1);i<=k+1;i++)
        pre[i]=(n+1-i)*pre[i-1]%Mod;
    for(int i=(suf[0]=1);i<=k+1;i++)
        suf[i]=(n-k-2+i)*suf[i-1]%Mod;
    ll res=0;
    for(int i=0,j=fp(-1,k+1);i<=k+1;i++,j=-j)
        res=(res+j*f[i]*inv[i]%Mod*inv[k+1-i]%Mod*pre[i]%Mod*suf[k+1-i])%Mod;
    res=(res+Mod)%Mod;
    printf("%I64d\n",res);
}
int main()
{
    build();
    int n,k;
    scanf("%d%d",&n,&k);
    powsum(k,n);
    return 0;
}