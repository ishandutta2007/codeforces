//By luogu send again.
//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
typedef long long ll;
typedef std::pair<ll,ll> pll;
#define INF (1ll<<58)
ll read()
{
    ll f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
    if(b>a)return a=b,1;
    return 0;
}
bool umin(ll& a,ll b)
{
    if(b<a)return a=b,1;
    return 0;
}
ll abs(ll x)
{
    return x>0?x:-x;
}
 
/**********/
#define MAXM 11
#define MAXN 2011
ll fac[MAXN],inv[MAXN],sum[MAXN];
const ll mod=ll (1e9+7);
ll Qpow(ll a,ll p)
{
    ll res=1;
    while (p)
    {
        if (p&1)res=(res*a)%mod;
        a=(a*a)%mod;
        p>>=1;
    }
    return res;
}
ll C(ll n,ll m)
{
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
int main()
{
    int n=read(),m=read();
    fac[0]=inv[0]=1;
    for (int i = 1; i <= n+m; ++i)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    inv[n+m]=Qpow(fac[n+m],mod-2);
    for (int i = n+m-1; i ; --i)
    {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
    for (int i = 1; i <= n; ++i)
    {
        sum[i]=(sum[i-1]+C(m+i-2,m-1))%mod;
    }
    ll ans=0;
    for (int i = 1; i <= n; ++i)
    {
        ans=(ans+sum[i]*C(m+(n-i)-1,m-1))%mod;
    }
    printf("%lld",ans);
    return 0;
}