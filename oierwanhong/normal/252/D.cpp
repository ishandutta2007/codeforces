#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<ctime>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
const ll INF=1ll<<58;
#define MAXN 2011
ll a[MAXN],t[MAXN], q[MAXN],begin[MAXN], end[MAXN];
ll n,k;
ll check_rev(ll* s)
{
	for(ll i=1;i<=n;++i)a[i]=i;
	for(ll x=1;x<=k;++x)
	{
		for(ll i=1;i<=n;++i)t[q[i]]=a[i];
		bool fail=0;
		for(ll i=1;i<=n;++i)a[i]=t[i], fail|=(a[i]!=s[i]);
		if(!fail)return x;
	}
	return k+1;
}
ll check(ll* s)
{
	for(ll i=1;i<=n;++i)a[i]=i;
	for(ll x=1;x<=k;++x)
	{
		for(ll i=1;i<=n;++i)t[i]=a[q[i]];
		bool fail=0;
		for(ll i=1;i<=n;++i)a[i]=t[i], fail|=(a[i]!=s[i]);
		if(!fail)return x;
	}
	return k+1;
}
void yes(){puts("YES");exit(0);}
int main()
{
	n=read(),k=read();
	bool fail=0;
	for(ll i=1;i<=n;++i)q[i]=read();
	for(ll i=1;i<=n;++i)end[i]=read(),begin[i]=i,fail|=(end[i]!=i);
	if(!fail)return puts("NO"),0;
	ll x=check(end),y=check_rev(end);
	ll rx=check(begin),ry=check_rev(begin);
	if(k==1&&(x==1||y==1))yes();
	else if(x==1&&y==1)return puts("NO"),0;
	else if(x<=k&&(k-x)%2==0)yes();
	else if(y<=k&&(y-k)%2==0)yes();
	puts("NO");
	return 0;
}