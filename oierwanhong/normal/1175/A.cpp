//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
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
void work()
{
	ll n=read(),k=read(),ans=0;
	while(n)
	{
		ans+=n%k,n-=n%k;
		if(!n)break;
		while(n%k==0)n/=k,++ans;
	}
	std::cout<<ans<<std::endl;
}
int main()
{
	ll t=read();
	while(t--)work();
	return 0;
}