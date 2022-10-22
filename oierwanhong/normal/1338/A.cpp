//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<set>
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
#define MAXN 200011
ll count(ll x)
{
    ll res=0;
    while(x)
    {
        ++res;
        x>>=1;
    }
    return res;
}
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),premax=-INF,ans=0;
        for(ll i=1;i<=n;++i)
        {
            ll x=read();
            if(x<premax)umax(ans,count(premax-x));
            else premax=x;
        }
        printf("%lld\n",ans);
    }
}