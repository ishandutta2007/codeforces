//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
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
int main()
{
    ll t=read();
    while(t--)
    {
        ll a=read(),b=read(),c=read();
        ll ans=ll(3e4),A,B,C;
        for(ll i=1;i<=10000;++i)
        {
            ll s=abs(a-i);
            for(ll j=i;j<=20000;j+=i)
            {
                if(umin(ans,s+abs(j-b)+c%j))A=i,B=j,C=c-c%j;
                if(umin(ans,s+abs(j-b)+(j-c%j)))A=i,B=j,C=c+(j-c%j);
            }
        }
        printf("%lld\n%lld %lld %lld\n",ans,A,B,C);
    }
}