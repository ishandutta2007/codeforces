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
#define MAXN 200011
std::vector<ll>g[MAXN];
pll a[MAXN];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)a[i]=pll(-read(),i);
    std::sort(a+1,a+n+1);
    for(ll i=1;i<=n;++i)
    {
        g[i].push_back(2*a[i].second-1);
        if(i>1)printf("%lld %lld\n",2*a[i-1].second-1,2*a[i].second-1);
    }
    for(ll i=1;i<=n;++i)
    {
        ll d=-a[i].first;
        if(i+d-1<=n)
        {
            ll x=i+d-1;
            if(g[x].size()==1)g[x].push_back(2*a[i].second);
            printf("%lld %lld\n",g[x][0],2*a[i].second);
        }
        else
        {
            d-=(n-i);
            if(d==g[n].size())g[n].push_back(2*a[i].second);
            printf("%lld %lld\n",g[n][d-1],2*a[i].second);
        }
    }
    return 0;
}