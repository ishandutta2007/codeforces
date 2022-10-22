//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
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
	ll l=read(),k=read(),m=read(),t=read();
	for(ll i=1;i<=t;++i)
	{
		ll op=read(),x=read();
		if(op==0)
		{
			if(k>x)
			{
				k-=x,l-=x;
			}
			else l=x;
			std::cout<<l<<" "<<k<<std::endl;
		}
		else
		{
			if(k>=x)++k;
			++l;
			std::cout<<l<<" "<<k<<std::endl;
		}
	}
	return 0;
}