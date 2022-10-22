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
void umax(ll &a,ll b)
{
	if(b>a)a=b;
}
void umin(ll &a,ll b)
{
	if(b<a)a=b;
}

#define maxn 300011
ll a[maxn],r1=0,r2=0;
int main()
{
	ll n=read(),p=1;
	for(ll i=1;i<=n;++i)
	{
		a[i]=read();
	}
	while(p<n&&a[p]==a[n])++p;
	r1=n-p;p=n;
	while(p>1&&a[p]==a[1])--p;
	r2=p-1;
	std::cout<<std::max(r1,r2);
	return 0;
}