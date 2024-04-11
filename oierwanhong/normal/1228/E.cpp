//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<28;
/**********/
#define MAXN 100011
const ll mod=ll(1e9)+7;
ll fac[MAXN],inv[MAXN];
ll Qpow(ll a,ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1)res=res*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return res;
}
ll C(ll n,ll m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
    ll n=read(),k=read();
    fac[0]=inv[0]=1;
    for(ll i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod,inv[i]=Qpow(fac[i],mod-2);
    ll ans=0;
    for(ll i=0;i<=n;++i)
        for(ll j=0;j<=n;++j)
        {
            ll x=i*n+j*n-i*j;
            ll f=C(n,i)*C(n,j)%mod*Qpow(k-1,x)%mod*Qpow(k,n*n-x)%mod;
            if((i+j)&1)ans=(ans-f)%mod;
            else ans=(ans+f)%mod;
        }
    printf("%lld",(ans+mod)%mod);
    return 0;
}