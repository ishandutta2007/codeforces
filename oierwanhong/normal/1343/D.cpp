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
#define MAXN 1000011
ll a[MAXN],c[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),k=read();
        for(ll i=0;i<=2*k;++i)c[i]=0;
        for(ll i=1;i<=n;++i)a[i]=read();
        for(ll i=1;i<=n/2;++i)
        {
            ll x=a[i]+a[n-i+1];
            c[0]+=2,--c[min(a[i],a[n-i+1])+1];
            --c[x];++c[x+1];++c[max(a[i],a[n-i+1])+k+1];
        }
        ll ans=n;
        for(ll i=1;i<=2*k;++i)c[i]+=c[i-1],umin(ans,c[i]);
        printf("%lld\n",ans);
    }
}