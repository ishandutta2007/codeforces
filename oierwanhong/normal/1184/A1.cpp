//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
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
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
int main()
{
	ll r=read(),t=sqrt(r);
	for(ll x=1;x<=t;++x)
	{
		if((r-x*x-x-1)>0&&(r-x*x-x-1)%(2*x)==0)
		{
			std::cout<<x<<" "<<(r-x*x-x-1)/(2*x);
			return 0;
		}
	}
	std::cout<<"NO";
	return 0;
}