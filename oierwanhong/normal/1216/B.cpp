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
std::vector<ll>a,c[2011];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)
    {
        ll x=read();c[x].push_back(i),a.push_back(x);
    }
    std::sort(a.begin(),a.end());std::reverse(a.begin(),a.end());
    ll ans=0,sum=0;
    for(ll i=0;i<n;++i)ans+=a[i]*i+1;
    printf("%lld\n",ans);
    for(ll i=1000;i>=0;--i)
        for(auto x:c[i])printf("%lld ",x);
    return 0;
}