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
str a,b,c;
ll ans=2;
void up(ll t)
{
	if(t<ans)ans=t;
}
void check(str a,str b,str c)
{
	if(a[1]!=b[1])return;
	if(a[0]+1==b[0])
	{
		if(a[1]==c[1]&&(c[0]+1==a[0]||b[0]+1==c[0]))up(0);
		else up(1);
	}
	else if(b[0]+1==a[0])
	{
		if(a[1]==c[1]&&(c[0]+1==b[0]||a[0]+1==c[0]))up(0);
		else up(1);
	}
	else if(a[0]+2==b[0])
	{
		if(a[1]==c[1]&&a[0]+1==c[0])up(0);
		else up(1);
	}
	else if(b[0]+2==a[0])
	{
		if(a[1]==c[1]&&b[0]+1==c[0])up(0);
		else up(1);
	}
}
int main()
{
	std::cin>>a>>b>>c;
	if(a==b)
	{
		if(a==c)up(0);
		else up(1);
	}
	else if(a==c||b==c)up(1);
	check(a,b,c);
	check(a,c,b);
	check(b,c,a);
	std::cout<<ans;
	return 0;
}