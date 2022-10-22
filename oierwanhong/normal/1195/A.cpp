//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}

/**********/
#define MAXN 5011
ll n,k,a[MAXN],c[MAXN];
int main()
{
	n=read(),k=read();
	ll tmp=0;
	for(ll i=1;i<=n;++i)++c[read()];
	for(ll i=1;i<=k;++i)
	{
		tmp+=c[i]/2;
	}
	std::cout<<((n+1)/2-tmp+tmp*2);
	return 0;
}