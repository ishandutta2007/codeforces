//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
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

str s;
int main()
{
	ll task=read();
	while(task--)
	{
		std::cin>>s;
		ll sum=0,flag1=0,flag2=0;
		for(ll i=0;i<s.size();++i)
		{
			ll cur=s[i]-'0';
			sum+=cur;
			if(cur==0&&!flag1)flag1=1;
			else if((cur&1)==0)flag2=1;
		}
		if((sum%3==0)&&flag1&&flag2)puts("red");
		else puts("cyan");
	}
	return 0;
}