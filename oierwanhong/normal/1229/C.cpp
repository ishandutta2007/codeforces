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
#define MAXN 100011
std::vector<ll>g[MAXN];
ll ind[MAXN];
int main()
{
    ll n=read(),m=read();
    while(m--)
    {
        ll u=read(),v=read();
        if(u>v)std::swap(u,v);//make sure u<v
        g[u].push_back(v);++ind[v];
    }
    ll ans=0;
    for(ll i=1;i<=n;++i)ans+=g[i].size()*ind[i];
    printf("%lld\n",ans);
    ll q=read();
    while(q--)
    {
        ll u=read();
        ans-=g[u].size()*ind[u];
        for(auto v:g[u])
        {
            ans-=g[v].size()*ind[v];--ind[v];
            g[v].push_back(u);++ind[u];
            ans+=g[v].size()*ind[v];
        }
        g[u].clear();
        printf("%lld\n",ans);
    }
    return 0;
}