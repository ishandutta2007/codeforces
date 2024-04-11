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
const ll INF=1ll<<58;
/**********/
#define MAXN 200011
ll n;
struct BIT
{
    ll t[MAXN];
    #define lowb (i&-i)
    void modify(ll i,ll k)
    {
        while(i<=n)t[i]+=k,i+=lowb;
    }
    ll Qsum(ll i)
    {
        ll res=0;
        while(i)res+=t[i],i-=lowb;
        return res;
    }
}t;
pll a[MAXN];
int main()
{
    n=read();
    for(ll i=1;i<=n;++i)a[read()].first=i;
    for(ll i=1;i<=n;++i)a[read()].second=i;
    std::sort(a+1,a+n+1);
    ll ans=0;
    for(ll i=1;i<=n;++i)
    {
        t.modify(a[i].second,1);
        if(t.Qsum(a[i].second)<i)++ans;
    }
    printf("%lld",ans);
}