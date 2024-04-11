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
ll c[4];
void work()
{
	c[0]=c[1]=c[2]=0;
	ll n=read();
	for(ll i=1;i<=n;++i)++c[read()%3];
	ll ans=c[0];
	if(c[1]>c[2])ans+=c[2]+(c[1]-c[2])/3;
	else ans+=c[1]+(c[2]-c[1])/3;
	std::cout<<ans<<std::endl;
}
int main()
{
	ll t=read();
	while(t--)work();
	return 0;
}