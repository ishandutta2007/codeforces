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
#define MAXN 100011
ll a[MAXN];
ll maxsub(ll l,ll r)
{
	ll ans=0,sum=0;
	for(ll i=l;i<=r;++i)
	{
		if(sum<0)sum=0;
		sum+=a[i];
		umax(ans,sum);
	}
	return ans;
}
int main()
{
	ll t=read();
	while(t--)
	{
		ll n=read(),sum=0;
		for(ll i=1;i<=n;++i)a[i]=read(),sum+=a[i];
		if(sum>max(maxsub(1,n-1),maxsub(2,n)))puts("YES");
		else puts("NO");
	}
	return 0;
}