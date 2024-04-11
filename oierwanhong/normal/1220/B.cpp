//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
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
ll a[1011][1011],b[1011];
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    ll n=read(),g=0;
    for(ll i=1;i<=n;++i)a[1][i]=read(),g=gcd(g,a[1][i]);
    for(ll i=2;i<=n;++i)b[i]=a[1][i]/g;
    for(ll i=2;i<=n;++i)
        for(ll j=1;j<=n;++j)
        {
            ll x=read();
            if(i>=j)continue;
            if(b[i]*b[j]<x)
            {
                ll t=sqrt(x/b[i]/b[j]);
                g/=t;
                for(ll k=2;k<=n;++k)b[k]*=t;
            }
        }
    printf("%lld ",g);
    for(ll i=2;i<=n;++i)printf("%lld ",b[i]);
    return 0;
}