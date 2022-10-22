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
#define MAXN 100011
char x[MAXN],y[MAXN];
void work()
{
	scanf("%s%s",x,y);
	ll lx=strlen(x),ly=strlen(y);
	ll fx=0,fy=0;
	for(ll i=ly-1;i>=0;--i)
		if(y[i]=='1')
		{
			fy=ly-i;break;
		}
	for(ll i=lx-fy;i>=0;--i)
		if(x[i]=='1')
		{
			fx=lx-i;break;
		}
	printf("%lld\n",fx-fy);
}
int main()
{
	ll t=read();
	while(t--)work();
	return 0;
}