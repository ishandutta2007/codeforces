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
#define MAXN 5011
ll n,m,k,a[MAXN];
ll calc(ll l,ll r)
{
	ll ans=INF;
	for(ll i=0;i<m-k;++i)
		umin(ans,max(a[l+i],a[r-(m-k-i)+1]));
	return ans;
}
int main()
{
	ll task=read();
	while(task--)
	{
		n=read(),m=read(),k=read();
		k=min(k,m-1);
		for(ll i=1;i<=n;++i)a[i]=read();
		ll ans=0;
		for(ll i=0;i<=k;++i)
			umax(ans,calc(i+1,n-(k-i)));
		printf("%lld\n",ans);
	}
	return 0;
}