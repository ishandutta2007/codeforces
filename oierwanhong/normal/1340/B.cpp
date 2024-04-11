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
/**********/
#define MAXN 2011
bool f[MAXN][MAXN];
bool p[11][8]={
    {0,1,1,1,0,1,1,1},
    {0,0,0,1,0,0,1,0},
    {0,1,0,1,1,1,0,1},
    {0,1,0,1,1,0,1,1},
    {0,0,1,1,1,0,1,0},
    {0,1,1,0,1,0,1,1},
    {0,1,1,0,1,1,1,1},
    {0,1,0,1,0,0,1,0},
    {0,1,1,1,1,1,1,1},
    {0,1,1,1,1,0,1,1}
};
ll status[11];
char s[MAXN][9];
ll count(ll n)
{
    ll c=0;
    while(n)
    {
        if(n&1)++c;
        n>>=1;
    }
    return c;
}
bool sub(ll a,ll b){return (a&b)==b;}
int main()
{
    for(ll i=0;i<=9;++i)
    {
        for(ll j=1;j<=7;++j)
            status[i]+=p[i][j]*(1<<j);
    }
    ll n=read(),k=read();
    for(ll i=1;i<=n;++i)scanf("%s",s[i]+1);
    f[n+1][0]=1;
    for(ll i=n;i;--i)
    {
        ll g=0;
        for(ll j=1;j<=7;++j)g+=(s[i][j]-'0')<<j;
        for(ll j=0;j<=k;++j)
            for(ll p=0;p<=9;++p)
                if(sub(status[p],g)&&j>=count(status[p]^g))f[i][j]|=f[i+1][j-count(status[p]^g)];
    }
    if(!f[1][k]){puts("-1");return 0;}
    for(ll i=1;i<=n;++i)
    {
        ll g=0;
        for(ll j=1;j<=7;++j)g+=(s[i][j]-'0')<<j;
        for(ll p=9;p>=0;--p)
        {
            ll cost=count(status[p]^g);
            if(sub(status[p],g)&&k>=cost&&f[i+1][k-cost])
            {
                printf("%lld",p);
                k-=cost;break;
            }
        }
    }
    return 0;
}