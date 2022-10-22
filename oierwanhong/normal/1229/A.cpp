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
const ll INF=1ll<<28;
/**********/
#define MAXN 200011
std::map<ll,ll>p;
bool vis[MAXN];
ll a[MAXN], b[MAXN];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)
    {
        a[i]=read();
        ++p[a[i]];
    }
    for(ll i=1;i<=n;++i)b[i]=read();
    for(auto x:p)
        if(x.second>1)
            for(ll i=1;i<=n;++i)
                if((x.first|a[i])==x.first)vis[i]=1;
    ll ans=0;
    for(ll i=1;i<=n;++i)ans+=vis[i]*b[i];
    printf("%lld",ans);
    return 0;
}