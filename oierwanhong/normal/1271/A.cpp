#include<iostream>
#include<cstdio>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
#define INF (1ll<<58)
ll read()
{
    ll f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
    if(b>a)return a=b,1;
    return 0;
}
bool umin(ll& a,ll b)
{
    if(b<a)return a=b,1;
    return 0;
}
ll abs(ll x)
{
    return x>0?x:-x;
}
 
/**********/
int main()
{
	ll a=read(),b=read(),c=read(),d=read(),e=read(),f=read();
	if(e<f)
	{
		ll x=min(min(b,c),d);
		d-=x;
		printf("%lld",e*min(a,d)+f*x);
	}
	else
	{
		ll x=min(a,d);
		d-=x;
		printf("%lld",e*x+f*min(min(b,c),d));
	}
	return 0;
}