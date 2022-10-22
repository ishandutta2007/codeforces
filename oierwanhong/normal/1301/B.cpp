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
ll abs(ll x)
{
	return x>0?x:-x;
}

/**********/
#define MAXN 100011
ll a[MAXN],n;
pll check(ll m)
{
	ll l=0,r=ll(1e9);
	for(ll i=1;i<n;++i)
	{
		if(a[i]==-1)
		{
			if(a[i+1]>=0)umax(l,a[i+1]-m),umin(r,a[i+1]+m);
		}
		else
		{
			if(a[i+1]==-1)umax(l,a[i]-m),umin(r,a[i]+m);
			else if(abs(a[i]-a[i+1])>m)return pll(-1,-1);
		}
	}
	if(l>r)return pll(-1,-1);
	return pll(l,r);
}
void solve()
{
	n=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	ll l=0,r=ll(1e9),mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid).first>=0)r=mid;
		else l=mid+1;
	}
	pll ans=check(l);
	if(ans.first==-1)puts("-1 -1");
	else printf("%lld %lld\n",l,ans.first);
}
int main()
{
	ll task=read();
	while(task--)solve();
	return 0;
}