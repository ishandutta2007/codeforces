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
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
str a,t="1";
int main()
{
	std::cin>>a;
	ll ans=0;
	while(t.size()<=a.size()&&t<a)
	{
		++ans;
		t+="00";
	}
	std::cout<<ans;
	return 0;
}