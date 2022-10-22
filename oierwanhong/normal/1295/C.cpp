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
str s,t;
std::vector<ll>a[26];
int main()
{
	ll task=read();
	while(task--)
	{
		for(ll i=0;i<26;++i)a[i].clear();
		std::cin>>s>>t;
		for(ll i=0;i<s.size();++i)
			a[s[i]-'a'].push_back(i);
		ll pos=-1,ans=1;
		for(ll i=0;i<t.size();++i)
			if(a[t[i]-'a'].empty())ans=-1;
		if(ans==-1)
		{
			printf("-1\n");
			continue;
		}
		for(ll i=0;i<t.size();++i)
		{
			if(std::upper_bound(a[t[i]-'a'].begin(),a[t[i]-'a'].end(),pos)==a[t[i]-'a'].end())++ans,pos=-1;
			pos=*std::upper_bound(a[t[i]-'a'].begin(),a[t[i]-'a'].end(),pos);
		}
		printf("%lld\n",ans);
	}
	return 0;
}