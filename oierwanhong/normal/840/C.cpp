#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
const ll INF=1ll<<58;
#define MAXN 2011
const ll mod=ll(1e9)+7;
ll Qpow(ll a,ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1)res=res*a%mod;
        a=a*a%mod,p>>=1;
    }
    return res;
}
ll f[MAXN],fac[MAXN],inv[MAXN],a[MAXN], c[MAXN],g[MAXN],tmp[MAXN];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)
    {
        a[i]=read();
        for(ll j=2;j*j<=a[i];++j)
            while(a[i]%(j*j)==0)a[i]/=(j*j);
    }
    std::sort(a+1,a+n+1);
    ll m=0;
    for(ll i=1;i<=n;++i)
        if(a[i]!=a[i-1])c[++m]=1;
        else ++c[m];
    fac[0]=inv[0]=1;
    for(ll i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod,inv[i]=Qpow(fac[i],mod-2);
    ll all=0;
    f[0]=1;
    for(ll i=1;i<=m;++i)
    {
        ll mul=1;
        for(ll j=c[i];j;--j)
        {
            g[c[i]-j]=mul*inv[c[i]-j]%mod;
            mul=(mul*j%mod*(j-1))%mod;
        }
        for(ll j=0;j<all+c[i];++j)tmp[j]=0;
        for(ll j=0;j<=all;++j)
            for(ll k=0;k<c[i];++k)tmp[j+k]=(tmp[j+k]+f[j]*g[k])%mod;
        all+=c[i]-1;
        for(ll j=0;j<=all;++j)f[j]=tmp[j];
    }
    for(ll j=0;j<=all;++j)f[j]=(f[j]*fac[n-j])%mod;
    ll ans=0;
    for(ll j=0;j<=all;++j)
        if(j&1)ans=(ans-f[j]+mod)%mod;
        else ans=(ans+f[j])%mod;
    printf("%lld",ans);
    return 0;
}