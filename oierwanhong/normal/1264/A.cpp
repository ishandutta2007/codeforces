//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
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
	ll n=read(),g=0,s=0,b=0,pre=0,add=0;
	bool end=0;
	pre=read();
	g=1;
	for(ll i=2;i<=n;++i)
	{
		ll x=read();
		if(end)continue;
		if(!s)
		{
			if(x==pre)++g;
			else s=1;
		}
		else if(!b)
		{
			if(x==pre)++s;
			else
			{
				if(s<=g)++s;
				else b=1;
			}
		}
		else
		{
			if(x==pre)
			{
				if(add)++add;
				else ++b;
			}
			else
			{
				if((i-1)<=n/2)b+=add;
				add=1;
			}
		}
		pre=x;
	}
	if(g>=s||g>=b||(g+s+b>n/2))printf("0 0 0\n");
	else printf("%lld %lld %lld\n",g,s,b);
}
int main()
{
	ll task=read();
	while(task--)work();
	return 0;
}