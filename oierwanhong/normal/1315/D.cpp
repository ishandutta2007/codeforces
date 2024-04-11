//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
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
struct one
{
    ll a,t;
    bool operator <(const one& p)
    const
    {
        return t<p.t;
    }
}a[200011];
bool cmp(one a,one b)
{
    return a.a<b.a;
}
std::priority_queue<one>q;
int main()
{
    ll n=read(),ans=0,sum=0;
    for(ll i=1;i<=n;++i)a[i].a=read();
    for(ll i=1;i<=n;++i)a[i].t=read();
    std::sort(a+1,a+n+1,cmp);
    for(ll i=1;i<=n;++i)
    {
        ll t=a[i].a-a[i-1].a;
        while(t&&!q.empty())
        {
            sum-=q.top().t;q.pop();
            ans+=sum,--t;
        }
        sum+=a[i].t,q.push(a[i]);
    }
    while(!q.empty()){sum-=q.top().t,q.pop(),ans+=sum;}
    printf("%lld",ans);
    return 0;
}