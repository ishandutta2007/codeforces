//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
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

/**********/
#define MAXN 200011
ll cnt[MAXN];
int main()
{
	ll n=read();
	for(ll i=1;i<n;++i)
	{
		++cnt[read()];++cnt[read()];
	}
	for(ll i=1;i<=n;++i)
		if(cnt[i]==2)
		{
			std::cout<<"NO";
			return 0;
		}
	std::cout<<"YES";
	return 0;
}