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
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 1000011
ll a[MAXN];
pll pos[MAXN<<2|1];
void upd(ll x,ll i)
{
    if(x>pos[i].first)pos[i].second=pos[i].first,pos[i].first=x;
    else if(x!=pos[i].first)umax(pos[i].second,x);
}
void SOSdp()
{
    for(ll s=MAXN<<2;s;--s)
        for(ll i=21;i>=0;--i)
            if(s&(1<<i)&&pos[s].first)
            {
                upd(pos[s].first,s^(1<<i));upd(pos[s].second,s^(1<<i));
            }
}
int main()
{
    ll n=read(),ans=0;
    for(ll i=1;i<=n;++i)a[i]=read(),upd(i,a[i]);
    SOSdp();
    for(ll i=1;i<=n-2;++i)
    {
        ll p=0;
        for(ll j=21;j>=0;--j)
            if(!(a[i]&(1<<j))&&pos[p|(1<<j)].second>i)p|=1<<j;
        umax(ans,a[i]|p);
    }
    printf("%lld",ans);
    return 0;
}