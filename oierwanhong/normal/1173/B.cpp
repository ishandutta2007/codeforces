//By Luogu send again
//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
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
int main()
{
	ll n=read(),r=n/2+1;
	std::cout<<r<<std::endl;
	for(ll i=1;i<=r;++i)std::cout<<i<<" "<<1<<std::endl;
	for(ll i=2;i<=(n-r)+1;++i)std::cout<<r<<" "<<i<<std::endl;
	return 0;
}