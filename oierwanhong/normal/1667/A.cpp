
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 200011;
ll a[MAXN];
int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	ll ans=1e18;
	for(int p=1;p<=n;++p)
	{
		ll cur=0,pre=0;
		for(int i=p+1;i<=n;++i)
		{
			cur+= pre/a[i]+1;
			pre=(pre/a[i]+1)*a[i];
		}
		pre=0;
		for(int i=p-1;i;--i)
		{
			cur+= pre/a[i]+1;
			pre=(pre/a[i]+1)*a[i];
		}
		umin(ans,cur);
	}
	printf("%lld\n",ans);
	return 0;
}