//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
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
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),a=read(),b=read(),cur=1;
        if(b==1)
        {
            for(ll i=1;i<=n;++i)putchar('a');
            puts("");continue;
        }
        while(cur<=n)
        {
            ll p=a-b,k=(p>0);
            while(p>0&&cur<=n)putchar('a'),--p,++cur;
            while(k<b&&cur<=n)putchar('a'+k),++k,++cur;
        }
        puts("");
    }
}