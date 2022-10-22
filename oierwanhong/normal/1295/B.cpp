//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
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
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 200011
str s;
ll bal[MAXN];
int main()
{
	ll task,n,x;
	std::cin>>task;
	while(task--)
	{
		std::cin>>n>>x>>s;
		ll tot,ans=0;
		bal[0]=(s[0]=='0'?1:-1);
		for(ll i=1;i<n;++i)
			bal[i]=bal[i-1]+(s[i]=='0'?1:-1);
		tot=bal[n-1];
		if(x==0)++ans;
		if(tot==0)
		{
			for(ll i=0;i<n;++i)
				if(x==bal[i])ans=-1;
		}
		else
		{
			for(ll i=0;i<n;++i)
				if((x-bal[i])%tot==0&&(x-bal[i])/tot>=0)++ans;
		}
		printf("%lld\n",ans);
	}
}