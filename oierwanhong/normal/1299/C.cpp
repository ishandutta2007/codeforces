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
ll s[MAXN],sum[MAXN],top=0;
double ans[MAXN];
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		sum[i]=sum[i-1]+x;
		ll pre=i,tmp=x;
		while(top&&(sum[pre-1]-sum[s[top]-1])*(i-pre+1)>=tmp*(pre-s[top]))
		{
			tmp+=sum[pre-1]-sum[s[top]-1];
			pre=s[top];
			--top;
		}
		s[++top]=pre;
	}
	ll cur=n;
	while(top)
	{
		ll t=cur;
		while(cur>=s[top])ans[cur--]=(double(sum[t]-sum[s[top]-1]))/(t-s[top]+1);
		--top;
	}
	for(ll i=1;i<=n;++i)printf("%.9f\n",ans[i]);
	return 0;
}