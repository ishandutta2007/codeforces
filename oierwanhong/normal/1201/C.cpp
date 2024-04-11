//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
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
ll a[MAXN];
int main()
{
    ll n=read(),k=read();
    for(ll i=1;i<=n;++i)a[i]=read();
    std::sort(a+1,a+n+1);
    for(ll i=(n+1)/2+1;i<=n;++i)
    {
        if((a[i]-a[i-1])*(i-(n+1)/2)>=k)
        {
            printf("%lld",a[i-1]+k/(i-(n+1)/2));
            return 0;
        }
        k-=(a[i]-a[i-1])*(i-(n+1)/2);
    }
    printf("%lld",a[n]+k/(n+1-(n+1)/2));
    return 0;
}