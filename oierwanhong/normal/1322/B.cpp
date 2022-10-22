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
#define MAXN 500011
const ll MAXM=ll(2e7+11);
ll a[MAXN];
struct BIT
{
	ll t[MAXM];
	void modify(ll i,ll k)
	{
		++i;
		while(i<MAXM)
		{
			t[i]+=k;
			i+=(i&-i);
		}
	}
	ll Qsum(ll i)
	{
		++i;
		ll res=0;
		while(i)
		{
			res+=t[i];
			i-=(i&-i);
		}
		return res;
	}
}t0,t1;
int main()
{
	ll ans=0;
	ll n=read(),rest=0;
	for(ll i=1;i<=n;++i)a[i]=read();
	ll cnt=0;
	for(ll i=1;i<=n;++i)
		if(a[i]&1)++cnt;
	ans+=((cnt*(n-cnt))&1);
	for(ll k=1;(1ll<<k)<=ll(2e7);++k)
	{
		ll c0=0,c1=0;
		ll cur=0;
		for(ll i=1;i<=n;++i)
		{
			ll val=a[i]&((1ll<<k)-1);
			ll rest=(1ll<<k)-val;
			if(a[i]&(1ll<<k))
			{
				cur+=(t0.Qsum(rest-1));
				cur+=((c1-t1.Qsum(rest-1)));
				t1.modify(val,1);
				++c1;
			}
			else
			{
				cur+=(c0-t0.Qsum(rest-1));
				cur+=(t1.Qsum(rest-1));
				t0.modify(val,1);
				++c0;
			} 
		}
			
		ans+=(1ll<<k)*(cur&1);
		for(ll i=1;i<=n;++i)
		{
			ll val=a[i]&((1ll<<k)-1);
			if(a[i]&(1ll<<k))t1.modify(val,-1);
			else t0.modify(val,-1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}