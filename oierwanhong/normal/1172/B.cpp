//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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
const ll mod=998244353;
ll fac[MAXN],deg[MAXN];
int main()
{
    ll n=read();
    for(ll i=1;i<n;++i)++deg[read()],++deg[read()];
    fac[1]=1;
    for(ll i=2;i<=n;++i)fac[i]=fac[i-1]*i%mod;
    ll ans=1;
    for(ll i=1;i<=n;++i)ans=ans*fac[deg[i]]%mod;
    printf("%lld",ans*n%mod);
    return 0;
}