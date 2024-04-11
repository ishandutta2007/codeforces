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
#define MAXN 5011
char a[MAXN];
int main()
{
	ll task=read();
	while(task--)
	{
		scanf("%s",a+1);
		ll n=strlen(a+1),s=0,t=n+1,c=0;
		for(ll i=1;i<=n;++i)
			if(a[i]=='1')
			{
				s=i;break;
			}
		for(ll i=n;i;--i)
			if(a[i]=='1')
			{
				t=i;break;
			}
		for(ll i=s;i<=t;++i)
			if(a[i]=='0')++c;
		if(!s)puts("0");
		else printf("%lld\n",c);
	}
	return 0;
}