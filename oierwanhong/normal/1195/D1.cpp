//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
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
#define MOD 998244353
ll a[MAXN],n,s[21];
ll calc(ll x)
{
	ll cnt=0;
	while(x)
	{
		x/=10,++cnt;
	}
	return cnt;
}
ll ctrb1(ll x,ll p)
{
	ll tmp=10,res=0;
	for(ll k=1;k<=p;++k)
	{
		res=(res+x%10*tmp)%MOD;
		x/=10;
		tmp=(tmp*100)%MOD;
	}
	return (res+x*tmp)%MOD;
}
ll ctrb2(ll x,ll p)
{
	ll tmp=1,res=0;
	for(ll k=1;k<=p;++k)
	{
		res=(res+x%10*tmp)%MOD;
		x/=10;
		tmp=tmp*100%MOD;
	}
	return (res+x*tmp)%MOD;
}
int main()
{
	ll n=read(),ans=0;
	for(ll i=1;i<=n;++i)
	{
		a[i]=read();++s[calc(a[i])];
	}
	for(ll i=1;i<=n;++i)
	{
		ll l=calc(a[i]);
		ans=(ans+(ctrb1(a[i],l)+ctrb2(a[i],l))%MOD*s[l])%MOD;
	}
	std::cout<<ans;
	return 0;
}