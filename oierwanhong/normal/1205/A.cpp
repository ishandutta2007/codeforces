//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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
ll a[200011];
int main()
{
    ll n=read();
    if(n&1)
    {
        puts("YES");
        for(ll i=1;i<=n;i+=2)a[i]=(i/2)*4+1,a[n+i]=(i/2)*4+2;
        for(ll i=2;i<=n;i+=2)a[i]=(i/2)*4,a[n+i]=(i/2)*4-1;
        for(ll i=1;i<=n*2;++i)printf("%lld ",a[i]);
    }
    else puts("NO");
}