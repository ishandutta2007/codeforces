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
#define MAXN 300011
const ll mod=998244353;
struct one
{
	ll a,b;
	bool operator <(const one& t)
	const
	{
		if(a==t.a)return b<t.b;
		return a<t.a;
	}
}a[MAXN];

ll fac[MAXN],cx[MAXN],cy[MAXN];
int main()
{
	ll n=read();
	fac[0]=fac[1]=1;
	for(ll i=2;i<=n;++i)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	
	for(ll i=1;i<=n;++i)
	{
		scanf("%lld%lld",&a[i].a,&a[i].b);
		++cx[a[i].a],++cy[a[i].b];
	}
	std::sort(a+1,a+n+1);
	ll kx=1,ky=1;
	for(ll i=1;i<=n;++i)
	{
		kx=(kx*fac[cx[i]])%mod;
		ky=(ky*fac[cy[i]])%mod;
	}
	ll tmp=1;
	for(ll i=1;i<n;++i)
		if(a[i].b>a[i+1].b)tmp=0;
	if(tmp)
	{
		ll k=1;
		for(ll i=1;i<n;++i)
		{
			if(a[i].a==a[i+1].a&&a[i].b==a[i+1].b)++k;
			else
			{
				tmp=(tmp*fac[k])%mod;
				k=1;
			}
		}
		tmp=(tmp*fac[k])%mod;
	}
	printf("%lld",(fac[n]-kx-ky+tmp+mod+mod)%mod);
	return 0;
}