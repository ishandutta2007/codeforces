//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
/**********/
#define MAXN 211
pll a[MAXN];
ll sum[MAXN];
ll dist(pll a,pll b){return abs(a.first-b.first)+abs(a.second-b.second);}
int main()
{
	a[0].first=read(),a[0].second=read();
	ll ax=read(),ay=read(),bx=read(),by=read();
	ll sx=read(),sy=read(),t=read();
	ll lim=ll(5e16),n=0,ans=0;
	while(1)
	{
		a[n+1]=pll(a[n].first*ax+bx,a[n].second*ay+by);
		++n;
		if(a[n].first>lim||a[n].second>lim)break;
	}
	--n;
	for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+dist(a[i-1],a[i]);
	for(ll i=0;i<=n;++i)
	{
		ll rest=t-dist(a[i],pll(sx,sy));
		if(rest<0)continue;
		ll l=0,r=n;
		while(l<r)
		{
			ll mid=(l+r+1)>>1;
			if(sum[mid]-sum[i]<=rest)l=mid;
			else r=mid-1;
		}
		umax(ans,r-i+1);
		l=0,r=n;
		while(l<r)
		{
			ll mid=(l+r)>>1;
			if(sum[i]-sum[mid]<=rest)r=mid;
			else l=mid+1;
		}
		umax(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}