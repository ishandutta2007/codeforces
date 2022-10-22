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
	ll a=read(),b=read(),c=read();
	if(a>b+c)std::cout<<"+";
	else if(b>a+c)std::cout<<"-";
	else if(a==b&&c==0)std::cout<<"0";
	else std::cout<<"?";
	return 0;
}