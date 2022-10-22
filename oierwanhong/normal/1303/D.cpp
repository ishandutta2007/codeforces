//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
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
ll a[MAXN],c[62];
ll count(ll x)
{
	ll cnt=0;
	while(x>1)
	{
		x>>=1;
		++cnt;
	}
	return cnt;
}
int main()
{
	ll task=read();
	while(task--)
	{
		memset(c,0,sizeof c);
		ll n=read(),m=read(),ans=0,sum=0;
		for(ll i=1;i<=m;++i)a[i]=read(),++c[count(a[i])],sum+=a[i];
		if(sum<n)
		{
			puts("-1");
			continue;
		}
		for(ll i=0;i<62;++i)
		{
			c[i]+=c[i-1]/2;
			if(!(n&(1ll<<i)))continue;
			if(c[i])
			{
				--c[i];
				n^=1ll<<i;continue;
			}
			for(ll j=i+1;j<62;++j)
				if(c[j])
				{
					--c[j];
					for(ll k=i;k<j;++k)++c[k];
					ans+=j-i;
					break;
				}
			n^=1ll<<i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}