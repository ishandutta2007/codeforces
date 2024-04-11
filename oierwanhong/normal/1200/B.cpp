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
#define MAXN 1011
ll a[MAXN];
void work()
{
	ll n=read(),m=read(),k=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	bool flag=1;
	for(ll i=1;i<n;++i)
	{
		if(a[i]+m<a[i+1]-k)
		{
			flag=0;break;
		}
		m+=a[i]-max(a[i+1]-k,0);
	}
	if(flag)puts("YES");
	else puts("NO");
}
int main()
{
	ll t=read();
	while(t--)work();
	return 0;
}