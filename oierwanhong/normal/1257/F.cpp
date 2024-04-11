//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<ctime>
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
const ll INF=1<<28;
/**********/
const ll mod1=998244353,mod2=ll(1e9)+9;
ll a[200011],b[200011],M=(1<<15)-1,cnt[1<<15|1];
std::map<pll,ll>p;
int main()
{
    srand(time(0));rand();
    ll b1=rand(),b2=rand();
    for(ll i=1;i<=M;++i)cnt[i]=cnt[i>>1]+(i&1);
    ll n=read();
    for(ll i=1;i<=n;++i)a[i]=read();
    for(ll x=0;x<=M;++x)
    {
        for(ll i=1;i<=n;++i)b[i]=(a[i]>>15)^x;
        for(ll i=n;i>1;--i)b[i]=cnt[b[i]]-cnt[b[i-1]]+30;
        ll f1=0,f2=0;
        for(ll i=2;i<=n;++i)f1=(f1*b1+b[i])%mod1,f2=(f2*b2+b[i])%mod2;
        if(!p[{f1,f2}])p[{f1,f2}]=x+1;
    }
    for(ll x=0;x<=M;++x)
    {
        for(ll i=1;i<=n;++i)b[i]=(a[i]&M)^x;
        for(ll i=n;i>1;--i)b[i]=-cnt[b[i]]+cnt[b[i-1]]+30;
        ll f1=0,f2=0;
        for(ll i=2;i<=n;++i)f1=(f1*b1+b[i])%mod1,f2=(f2*b2+b[i])%mod2;
        ll y=p[{f1,f2}];
        if(y)return printf("%lld",((y-1)<<15)+x)&0;
    }
    return puts("-1")&0;
}