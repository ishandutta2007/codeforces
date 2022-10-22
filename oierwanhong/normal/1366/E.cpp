//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
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
const ll INF=1ll<<58;
/**********/
#define MAXN 200011
ll a[MAXN],b[MAXN];
const ll mod=998244353;
int main()
{
    ll n=read(),m=read(),ans=1;
    for(ll i=1;i<=n;++i)a[i]=read();
    for(ll i=1;i<=m;++i)b[i]=read();
    ll j=n;
    for(ll i=m;i;--i)
    {
        while(a[j]>b[i])--j;
        if(a[j]<b[i])return puts("0"),0;
        ll now=j;
        while(a[j]>=b[i])--j;
        if(i>1)ans=ans*(now-j)%mod;
    }
    if(j)ans=0;
    printf("%lld",ans);
    return 0;
}