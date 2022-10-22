#include<iostream>
#include<algorithm>
#include<cstdio>
typedef long long ll;
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

#define maxn 1011
ll a[maxn],t[maxn];
int main()
{
	ll n=read(),h=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	ll i=n;
	for(;i>=1;--i)
	{
		for(ll j=1;j<=i;++j)t[j]=a[j];
		std::sort(t+1,t+i+1);
		ll sum=0;
		for(ll j=i;j>=1;j-=2)sum+=t[j];
		if(sum<=h)break;
	}
	std::cout<<i;
	return 0;
}