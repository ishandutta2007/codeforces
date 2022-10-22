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
#define MAXN 511
ll a[MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read(),c1=0;
        for(ll i=1;i<=n;++i)a[i]=read(),c1+=(a[i]&1);
        if(c1&1)
        {
            std::sort(a+1,a+n+1);
            bool flag=0;
            for(ll i=2;i<=n;++i)
                if(a[i]-a[i-1]==1)flag=1;
            puts(flag?"YES":"NO");
        }
        else puts("YES");
    }
    return 0;
}