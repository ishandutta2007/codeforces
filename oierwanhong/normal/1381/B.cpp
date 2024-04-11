#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
void umin(ll& a,ll t){if(t<a)a=t;}
const ll INF=1ll<<50;
#define MAXN 4011
bool f[MAXN];
ll a[MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read()<<1;
        for(ll i=1;i<=n;++i)a[i]=read(),f[i]=0;
        f[0]=1;
        for(ll i=1,j;i<=n;i=j)
        {
            j=i+1;
            while(j<=n&&a[j]<a[i])++j;
            for(ll k=n;k>=j-i;--k)f[k]|=f[k-(j-i)];
        }
        puts(f[n>>1]?"YES":"NO");
    }
    return 0;
}