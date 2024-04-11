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

ll n,m,k;
ll a[200001],maxn=0,tmp,mx2=0;
int main()
{
	n=read(),m=read(),k=read();
	for(ll i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]>a[maxn])maxn=i;
	}
	tmp=a[maxn];
	a[maxn]=0;
	for(ll i=1;i<=n;++i)
		if(a[i]>mx2)mx2=a[i];
	
	write(m%(k+1)*tmp+m/(k+1)*k*tmp+m/(k+1)*mx2);
	return 0;
}