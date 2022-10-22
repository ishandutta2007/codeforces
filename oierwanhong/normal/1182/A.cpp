//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
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
ll qpow(ll a,ll p)
{
	if(p==0)return 1;
	ll res=1;
	while(p)
	{
		if(p&1)res*=a;
		p>>=1;
		a*=a;
	}
	return res;
}
int main()
{
	ll n=read();
	if(n&1)std::cout<<0;
	else std::cout<<qpow(2,n>>1);
	return 0;
}