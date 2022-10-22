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
#define MAXN 1000011
ll a[MAXN];
std::priority_queue<ll>q;
int main()
{
    ll n=read(),x,ans=0;
    for(ll i=1;i<=n;++i)
    {
        a[i]=read();
        if(a[i]==-1)x=i;
    }
    for(ll i=n;i>x;--i)
    {
        q.push(-a[i]);
        if(!(i&(i-1)))ans-=q.top(),q.pop();
    }
    printf("%lld",ans);
    return 0;
}