//Send again By Luogu
//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<28)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 511
ll a[MAXN][MAXN];
int main()
{
    ll n=read();
    if(n<=2){puts("-1");return 0;}
    ll cnt=0;
    for(ll i=n;i>3;--i)a[1][i]=++cnt;
    for(ll i=4;i<=n;++i)a[2][i]=++cnt;
    for(ll i=3;i<n;++i)
    {
        if(i&1)
            for(ll j=n;j;--j)a[i][j]=++cnt;
        else 
            for(ll j=1;j<=n;++j)a[i][j]=++cnt;
    }
    if(n&1)
    {
        for(ll j=n;j;--j)
            if(j!=2)a[n][j]=++cnt;
    }
    else
    {
        for(ll j=1;j<=n;++j)
            if(j!=2)a[n][j]=++cnt;
    }
        
    a[n][2]=++cnt;
    a[1][1]=cnt+6,a[1][2]=cnt+1,a[1][3]=cnt+4;
    a[2][1]=cnt+2,a[2][2]=cnt+3,a[2][3]=cnt+5;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j)printf("%lld%c",a[i][j],j==n?'\n':' ');
    return 0;
}