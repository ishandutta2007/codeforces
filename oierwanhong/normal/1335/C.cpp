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
std::map<ll,ll>p;
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),x=0,y=0;p.clear();
        for(ll i=1;i<=n;++i)
        {
            ll a=read();
            ++p[a];
        }
        x=p.size();
        for(auto a:p)y=max(y,a.second);
        printf("%lld\n",max(min(x-1,y),min(x,y-1)));
    }
    return 0;
}