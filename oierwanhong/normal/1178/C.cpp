//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
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

/**********/
#define MOD 998244353
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p)
	{
		if(p&1)res=(res*a)%MOD;
		a=(a*a)%MOD;
		p>>=1;
	}
	return res;
}
int main()
{
	ll a=read(),b=read();
	std::cout<<Qpow(2,a)*Qpow(2,b)%MOD;
	return 0;
}