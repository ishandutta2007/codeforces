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
	ll n=read(),ans=0;
	while(n%5==0)ans+=3,n/=5;
	while(n%3==0)ans+=2,n/=3;
	while(n%2==0)++ans,n>>=1;
	if(n==1)std::cout<<ans<<std::endl;
	else std::cout<<-1<<std::endl;
}
int main()
{
	ll q=read();
	while(q--)work();
	return 0;
}