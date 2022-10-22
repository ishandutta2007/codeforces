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
#define MAXN 200011
char s[MAXN];
void work()
{
	ll n=read(),a=read(),b=read();
	scanf("%s",s+1);
	ll x=0,t=1,ans=b;
	while(s[t]=='0')ans+=a+b,++t;
	if(t>n)
	{
		printf("%lld\n",ans);
		return;
	}
	ans+=a+b,x=t;
	while(t<=n)
	{
		while(s[t]=='1')ans+=a+2*b,++t;
		x=t;
		while(s[t]=='0')++t;
		if(t>n)break;
		ans+=min((t-x)*(a+2*b),(t-x+2)*a+(t-x+1)*b);
		x=t;
	}
	ans+=(n-x+1)*(a+b)+a;
	printf("%lld\n",ans);
}
int main()
{
	ll t=read();
	while(t--)work();
	return 0;
}