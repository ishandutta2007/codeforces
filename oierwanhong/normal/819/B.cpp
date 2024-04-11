//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
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
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 2000011
ll c[MAXN],p[MAXN];
int main()
{
    ll n=read(),cnt_positive=0,sum_positive=0,cnt_negative=0,sum_negative=0;
    for(ll i=1;i<=n;++i)p[i]=read();
    for(ll i=1;i<=n;++i)
        if(p[i]-i<=0)++cnt_negative,sum_negative+=i-p[i];
        else ++c[p[i]-i],++cnt_positive,sum_positive+=p[i]-i;
    ll ans=sum_positive+sum_negative,pos=0;
    for(ll i=1;i<n;++i)
    {
        sum_positive-=cnt_positive;
        cnt_positive-=c[i];
        sum_negative+=cnt_negative;
        cnt_negative+=c[i];
        ll x=p[n-i+1];
        sum_negative-=n+1-x,--cnt_negative;
        if(x>1)++c[x-1+i],sum_positive+=x-1,++cnt_positive;
        else ++cnt_negative;
        if(umin(ans,sum_positive+sum_negative))pos=i;
    }
    printf("%lld %lld",ans,pos);
    return 0;
}