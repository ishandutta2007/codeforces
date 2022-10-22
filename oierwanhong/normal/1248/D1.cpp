//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
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
const ll INF=1ll<<58;
/**********/
#define MAXN 500011
char s[MAXN];
ll a[MAXN],sum[MAXN],premin[MAXN];
ll calc(ll n)
{
    premin[0]=INF;
    for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+a[i],premin[i]=min(premin[i-1],sum[i]);
    ll res=(!premin[n]),sufmin=INF,s=0;
    for(ll i=n;i>1;--i)
    {
    	s+=a[i];
        sufmin=min(sufmin+a[i],a[i]);
        if(s+premin[i-1]>=0&&sufmin>=0)++res;
    }
    return res;
}
int main()
{
    ll n=read(),all=0;scanf("%s",s+1);
    for(ll i=1;i<=n;++i)a[i]=(s[i]=='('?1:-1),all+=a[i];
    if((n&1)||all)return printf("0\n1 1")&0;
    ll maxv=0,ansx=1,ansy=1;
    for(ll x=1;x<=n;++x)
        for(ll y=x;y<=n;++y)
        {
            std::swap(a[x],a[y]);
            if(umax(maxv,calc(n)))ansx=x,ansy=y;
            std::swap(a[x],a[y]);
        }
    printf("%lld\n%lld %lld",maxv,ansx,ansy);
}