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
#define MAXN 200011
ll a[MAXN];
int main()
{
	ll n=read(),m=read(),k=-1;
	for(ll i=1;i<=n;++i)
	{
		a[i]=a[i-1]+(i-1)/2;
		if(a[i]>=m)
		{
			k=i;break;
		}
	}
	if(m==0)
	{
		ll cur=1;
		for(ll i=1;i<=n;++i)
		{
			cur+=2;
			std::cout<<cur<<" ";
		}
		return 0;
	}
	if(k==-1)
	{
		puts("-1");return 0;
	}
	bool flag=0;
	if(a[k]>m)--k,flag=1;
	for(ll i=1;i<=k;++i)std::cout<<i<<" ";
	ll f=k/2,cur=k;
	if(flag)
	{
		++cur;
		while(a[k]+f>m)--f,cur+=2;
		std::cout<<cur<<" ";
		++k;
	}
	ll t=cur+1;
	for(ll i=k+1;i<=n;++i)std::cout<<(cur+=t)<<" ";
	return 0;
}