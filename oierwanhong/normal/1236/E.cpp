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
const ll INF=1ll<<58;
/**********/
#define MAXN 300011
ll a[MAXN];
std::map<ll,ll>l,r;
int main()
{
    ll n=read(),m=read();
    if(n==1)return puts("0")&0;
    for(ll i=1;i<=m;++i)a[i]=read();
    for(ll i=m;i;--i)
    {
        l[a[i]+i]=l[a[i]+i+1]+1;
        r[a[i]-i]=r[a[i]-i-1]+1;
    }
    ll ans=0;
    for(ll i=1;i<=n;++i)ans+=(min(n,i+m+1-r[i])-max(1,i-m-1+l[i]))+1;
    printf("%lld",ans);
}