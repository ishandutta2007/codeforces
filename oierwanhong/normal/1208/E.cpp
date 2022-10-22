//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
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
ll f[MAXN],a[MAXN],tot=0;
ll q[MAXN];
int main()
{
    ll n=read(),w=read();
    for(ll p=1;p<=n;++p)
    {
        ll l=read(),maxv=0;
        for(ll i=1;i<=l;++i)a[i]=read(),umax(maxv,a[i]);
        a[l+1]=0;
        tot+=maxv;
        ll h=1,t=1;
        if(l<w)q[t++]=0;
        for(ll i=1;i<=l;++i)
        {
            while(h<t&&q[h]<i-(w-l))++h;
            while(h<t&&a[q[t-1]]<=a[i])--t;
            q[t++]=i;
            f[i]=f[i]-maxv+a[q[h]];
        }
        h=t=1;if(l<w)q[t++]=l+1;
        for(ll i=w;i>=w-l&&i>l;--i)
        {
            while(h<t&&q[h]>i)++h;
            if(i-w+l>=0) 
            {
                while(h<t&&a[q[t-1]]<=a[i-w+l])--t;
                q[t++]=i-w+l;
            }
            f[i]=f[i]-maxv+a[q[h]];
        }
    }
    for(ll i=1;i<=w;++i)printf("%lld ",tot+f[i]);
    return 0;
}