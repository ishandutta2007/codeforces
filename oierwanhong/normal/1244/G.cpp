//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
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
ll b[MAXN];
int main()
{
    ll n=read(),k=read(),minv=0,maxv=0;
    for(ll i=1;i<=n;++i)minv+=i;
    if(minv>k)return puts("-1")&0;
    for(ll i=1;i<=n;++i)maxv+=max(i,n-i+1);
    if(maxv<k)
    {
        printf("%lld\n",maxv);
        for(ll i=1;i<=n;++i)printf("%lld ",i);
        puts("");
        for(ll i=1;i<=n;++i)printf("%lld ",n-i+1);
        return 0;
    }
    printf("%lld\n",k);
    ll l=1,r=n,s=k-minv;
    for(ll i=1;i<=n;++i)
        if(r>=i&&s>=r-i)s-=r-i,b[i]=r--;
        else b[i]=l++;
    for(ll i=1;i<=n;++i)printf("%lld ",i);
    puts("");
    for(ll i=1;i<=n;++i)printf("%lld ",b[i]);
    return 0;
}