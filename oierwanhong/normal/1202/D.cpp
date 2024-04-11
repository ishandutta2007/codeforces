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
void solve()
{
    ll n=read();
    for(ll x=2;x<=n+1;++x)
    {
        if(x*(x+1)/2>n)
        {
            ll t=n-x*(x-1)/2;
            printf("133");
            while(t--)putchar('7');
            for(ll p=3;p<=x;++p)putchar('3');
            puts("7");
            return;
        }
    }
}
int main()
{
    ll t=read();
    while(t--)solve();
    return 0;
}