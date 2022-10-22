//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
const ll INF=1<<28;
/**********/
std::map<ll,ll>p;
int main()
{
    ll T=read();
    while(T--)
    {
        p.clear();
        ll n=read(),ans=n+1;
        for(ll i=1;i<=n;++i)
        {
            ll x=read();
            if(p.count(x))umin(ans,i-p[x]+1);
            p[x]=i;
        }
        printf("%lld\n",ans<=n?ans:-1ll);
    }
    return 0;
}