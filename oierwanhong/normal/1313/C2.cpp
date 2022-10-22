#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
bool umin(ll& a,ll t){if(t<a)return a=t,1;return 0;}
const ll INF=1ll<<58;
#define MAXN 500011
ll a[MAXN],s[MAXN],w[MAXN], lv[MAXN];
int main()
{
	ll n=read(),sum=0,minv=INF,top=0;
	for(ll i=1;i<=n;++i)a[i]=read(),sum+=a[i];
	for(ll i=1;i<=n;++i)
	{
		lv[i]=lv[i-1];
		ll sw=0;
		while(top&&a[s[top]]>=a[i])
		{
			sw+=w[top];lv[i]+=w[top]*(a[s[top]]-a[i]);
			--top;
		}
		s[++top]=i,w[top]=sw+1;
	}
	top=0;
	ll f=0,pos=0;
	for(ll i=n;i;--i)
	{
		ll sw=0;
		while(top&&a[s[top]]>=a[i])
		{
			sw+=w[top];f+=w[top]*(a[s[top]]-a[i]);
			--top;
		}
		s[++top]=i,w[top]=sw+1;
		if(umin(minv,f+lv[i]))pos=i;
	}
	for(ll i=pos-1;i;--i)umin(a[i],a[i+1]);
	for(ll i=pos+1;i<=n;++i)umin(a[i],a[i-1]);
	for(ll i=1;i<=n;++i)printf("%lld ",a[i]);
	return 0;
}