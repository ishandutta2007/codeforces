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
const ll mod=ll(1e9)+7;
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
ll calc(ll n,ll p)
{
    ll res=1;
    n/=p;
    while(n)
		res=res*Qpow(p,n)%mod,n/=p;
    return res;
}
int main()
{
    ll x=read(),n=read(),ans=1;
    for(ll i=2;i*i<=x;++i)
        if(x%i==0)
        {
            ans=ans*calc(n,i)%mod;
            while(x%i==0)x/=i;
        }
    if(x>1)ans=ans*calc(n,x)%mod;
    printf("%lld",ans);
    return 0;
}