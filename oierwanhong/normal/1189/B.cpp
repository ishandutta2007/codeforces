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
#define MAXN 200011
ll a[MAXN];
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	std::sort(a+1,a+n+1);
	std::reverse(a+1,a+n+1);
	if(a[1]>=a[2]+a[3])std::cout<<"NO";
	else
	{
		std::cout<<"YES"<<std::endl;
		if(n&1)
		{
			for(ll i=1;i<=n;i+=2)std::cout<<a[i]<<" ";
			for(ll i=n-1;i>0;i-=2)std::cout<<a[i]<<" ";
		}
		else
		{
			for(ll i=1;i<=n;i+=2)std::cout<<a[i]<<" ";
			for(ll i=n;i>0;i-=2)std::cout<<a[i]<<" ";
		}
	}
	return 0;
}