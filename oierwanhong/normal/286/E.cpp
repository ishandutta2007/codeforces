#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
typedef long long ll;
typedef unsigned un;
//typedef std::string str;
typedef std::pair<ll,ll> pll;
typedef std::pair<int,int> pii;
typedef std::pair<double,double> pd;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
const ll INF=1ll<<50;
#define MAXN 3000011
const ll mod=998244353;
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
ll Inv(ll x){return Qpow(x,mod-2);}
ll f[MAXN];
int status[MAXN];
void NTT(ll* a,ll len,ll type)
{
    for(ll i=0;i<len;++i)
        if(status[i]>i)std::swap(a[i],a[status[i]]);
    for(ll cur=1;cur<len;cur<<=1)
    {
        ll w=Qpow(type==1?3:Inv(3),(mod-1)/(cur<<1));
        for(ll j=0;j<len;j+=cur<<1)
        {
            ll wn=1;
            for(ll k=0;k<cur;++k,wn=w*wn%mod)
            {
                ll x=a[j+k],y=wn*a[j+cur+k]%mod;
                a[j+k]=(x+y)%mod,a[j+cur+k]=(x-y)%mod;
            }
        }
    }
    if(type==-1)
    {
        ll inv_len=Inv(len);
        for(ll i=0;i<len;++i)a[i]=(a[i]*inv_len%mod+mod)%mod;
    }
}
int ans[MAXN];
bool a[MAXN];
int main()
{
    ll n=read(),m=read();
    f[0]=1;
    for(ll i=1;i<=n;++i)
    {
        ll x=read();a[x]=f[x]=1;
    }
    ll len=1;
    while(len<=m+m)len<<=1;
    for(ll i=0;i<len;++i)
        status[i]=(status[i>>1]>>1)|((i&1)*(len>>1));
    NTT(f,len,1);
    for(ll i=0;i<len;++i)f[i]=f[i]*f[i]%mod;
    NTT(f,len,-1);
    ll cnt=0;
    for(ll i=1;i<=m;++i)
        if(a[i]==0&&f[i])return puts("NO"),0;
        else if(f[i]==2)ans[++cnt]=i;
    puts("YES");
    printf("%lld\n",cnt);
    for(ll i=1;i<=cnt;++i)printf("%d ",ans[i]);
    return 0;
}