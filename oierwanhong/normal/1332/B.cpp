//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
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
#define MAXN 2011
ll a[MAXN],c[MAXN],p[MAXN],cntp=0;
bool check(ll n)
{
    for(ll i=2;i*i<=n;++i)
        if(n%i==0)return 0;
    return n!=1;
}
int main()
{
    for(ll i=2;i<=1000;++i)
        if(check(i))p[++cntp]=i;
	ll t=read();
	while(t--)
	{
        ll n=read(),cnt=0;
        for(ll i=1;i<=n;++i)a[i]=read(),c[i]=0;
        for(ll i=1;i<=cntp;++i)
        {
            ll x=p[i],flag=0;
            for(ll j=1;j<=n;++j)
                if(a[j]%x==0&&!c[j])c[j]=cnt+1,flag=1;
            if(flag)++cnt;
        }
        printf("%lld\n",cnt);
        for(ll i=1;i<=n;++i)printf("%lld ",c[i]);
        puts("");
	}
	return 0;
}