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
const ll mod=998244353;
ll Qpow(ll a,ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1)res=(res*a)%mod;
        a=(a*a)%mod;
        p>>=1;
    }
    return res;
}
int main()
{
    ll n=read(),m=read(),l=read(),r=read();
    if((n*m)&1)printf("%lld",Qpow(r-l+1,n*m));
    else
    {
        if(r-l+1==1)puts("1");
        else
        {
            if((r-l+1)&1)printf("%lld",(Qpow(r-l+1,n*m)+1)*((mod+1)/2)%mod);
            else printf("%lld",(Qpow(r-l+1,n*m)*((mod+1)/2))%mod);
        }
    }
    
    return 0;
}