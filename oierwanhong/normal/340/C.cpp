#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
#define MAXN 1000011
ll a[MAXN];
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    ll n=read(),ans=0;
    for(ll i=1;i<=n;++i)a[i]=read();
    std::sort(a+1,a+n+1);
    ll s=0;
    for(ll i=1;i<=n;++i)
    {
        ans+=(i-1)*a[i]-s;
        s+=a[i];
    }
    ans*=2;
    for(ll i=1;i<=n;++i)ans+=a[i];
    ll g=gcd(n,ans);
    printf("%lld %lld",ans/g,n/g);
    return 0;
}