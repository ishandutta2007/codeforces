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
#define MAXN 5011
ll a[MAXN],p[MAXN],sum=0;
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)a[i]=read(),sum+=a[i];
	if(a[1]>sum/2)
	{
		std::cout<<1<<std::endl<<1;
		return 0;
	}
	ll tmp=a[1],cnt=0;
	p[++cnt]=1;
	for(ll i=2;i<=n;++i)
		if((a[i]<<1)<=a[1])
		{
			p[++cnt]=i;
			tmp+=a[i];
		}
	if(tmp>sum/2)
	{
		std::cout<<cnt<<std::endl;
		for(ll i=1;i<=cnt;++i)std::cout<<p[i]<<" ";
	}
	else printf("0");
	return 0;
}