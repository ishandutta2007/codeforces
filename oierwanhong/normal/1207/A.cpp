//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return f*x;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/

void work()
{
	ll b=read(),p=read(),f=read(),h=read(),c=read(),ans=0;
	if(h>c)
	{
		ll k=min(b/2,p);
		b-=k*2,p-=k;
		ans+=k*h;
		k=min(b/2,f);
		ans+=k*c;
	}
	else
	{
		ll k=min(b/2,f);
		b-=k*2,f-=k;
		ans+=k*c;
		k=min(b/2,p);
		ans+=k*h;
	}
	printf("%lld\n",ans);
}
int main()
{
	ll t=read();
	while(t--)work();
	return 0;
}