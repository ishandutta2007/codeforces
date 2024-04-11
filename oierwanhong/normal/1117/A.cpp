#include<iostream>
#include<cstdio>
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
void write(ll x)
{
	if(x==0)
	{
		putchar('0');
		putchar(' ');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	ll a[21],top=0;
	while(x)
	{
		a[++top]=x%10;
		x/=10;
	}
	for(ll i=top;i>=1;--i)putchar(a[i]+'0');
	putchar(' ');
}

ll n;
ll a[100001],f[100001];
ll maxn=-INF,ans=0;
int main()
{
	n=read();
	for(ll i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]>maxn)ans=1;
		if(a[i]>=maxn)
		{
			maxn=a[i];
			if(a[i-1]==a[i])f[i]=f[i-1]+1;
			else f[i]=1;
			if(f[i]>ans)ans=f[i];
		}
	}
	write(ans);
	return 0;
}