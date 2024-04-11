//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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
#define MAXN 500011
ll f[2][MAXN],a[MAXN],b[MAXN];
int main()
{
    ll n=read(),k=read();
    for(ll i=1;i<n;++i)a[i]=read();
    for(ll i=1;i<n;++i)b[i]=read();
    f[1][1]=k;
    printf("0 ");
    for(ll i=2;i<=n;++i)
    {
        f[0][i]=min(f[0][i-1],f[1][i-1])+a[i-1];
        f[1][i]=min(f[0][i-1]+k,f[1][i-1])+b[i-1];
        printf("%lld ",min(f[0][i],f[1][i]));
    }
}