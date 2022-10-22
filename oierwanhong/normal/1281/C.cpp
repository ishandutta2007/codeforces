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
str s;
const ll mod=ll(1e9+7);
int main()
{
	ll task=read();
	while(task--)
	{
		ll x=read(),ans=0;
		std::cin>>s;
		ans=s.size();
		for(ll i=0;i<x;++i)
		{
			if(s.size()>=x)
			{
				ans=(ans+((ans-i-1+mod)%mod)*(s[i]-'1'))%mod;
			}
			else
			{
				if(s[i]=='2')s+=s.substr(i+1);
				if(s[i]=='3')s+=s.substr(i+1)+s.substr(i+1);
				ans=s.size();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}