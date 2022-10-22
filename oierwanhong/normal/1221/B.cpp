//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef int ll;
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
const ll mx[]={1,2,2,1},my[]={-2,-1,1,2};
char a[111][111];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)
    {
        for(ll j=1;j<=n;++j)putchar(((i+j)&1)?'W':'B');
        puts("");
    }
}