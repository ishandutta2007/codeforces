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
#define MAXN 1000011
ll a[MAXN],t[MAXN],b[MAXN],len=0,ans=INF;
ll n;
ll calc(ll x,ll l,ll r)
{
	ll k=0,val=0;
	for(ll i=l+1;i<=r;++i)k-=a[i]%x,val+=(i-l)*(a[i]%x);
	ll res=val;
	k+=(a[l]%x);
	for(ll i=l+1;i<=r;++i)
	{
		val+=k;
		k+=2*(a[i]%x);
		umin(res,val);
	}
	return res;
}
void work(ll x)
{
	ll pre=0,res=0,begin=1;
	for(ll i=1;i<=n;++i)b[i]=a[i];
	for(ll i=1;i<=n;++i)
	{
		ll cur=a[i]%x;
		pre+=cur;
		if(pre>=x)
		{
			ll rest=pre-x;
			a[i]-=rest;
			res+=calc(x,begin,i);
			a[i]=rest;
			pre-=x;
			begin=i;
		}
	}
	for(ll i=1;i<=n;++i)a[i]=b[i];
	if(pre==0)umin(ans,res);
}
int main()
{
	n=read();
	ll sum=0;
	for(ll i=1;i<=n;++i)
	{
		a[i]=read();sum+=a[i];
	}
	ll cur=sum;
	for(ll i=2;i*i<=cur;++i)
	{
		if(cur%i==0)t[++len]=i;
		while(cur%i==0)cur/=i;
	}
	if(cur>1)t[++len]=cur;
	for(ll i=1;i<=len;++i)work(t[i]);
	printf("%lld",ans==INF?-1:ans);
	return 0;
}