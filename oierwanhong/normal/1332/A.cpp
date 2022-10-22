//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
typedef int ll;
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
int main()
{
	ll t=read();
	while(t--)
	{
		ll a=read(),b=read(),c=read(),d=read();
		ll x=read(),y=read(),x1=read(),y1=read(),x2=read(),y2=read();
		bool flag=0;
		if(x1==x2)flag|=(a>0||b>0);
		else flag|=(x+b-a<x1||x+b-a>x2);
		if(y1==y2)flag|=(c>0||d>0);
		else flag|=(y+d-c<y1||y+d-c>y2);
		puts(flag?"No":"Yes");
	}
	return 0;
}