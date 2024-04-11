#include<iostream>
#include<cstdio>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
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
ll work(std::vector<ll>a,ll x)
{
	std::vector<ll>l,r;
	for(std::vector<ll>::iterator it=a.begin();it!=a.end();++it)
		if((*it)&(1<<x))l.push_back(*it);
		else r.push_back(*it);
	if(x==0)return (!l.empty())&&(!r.empty());
	if(l.empty())return work(r,x-1);
	if(r.empty())return work(l,x-1);
	return min(work(l,x-1),work(r,x-1))+(1<<x);
}
int main()
{
	std::vector<ll>a;
	ll n=read();
	for(ll i=1;i<=n;++i)
	{
		a.push_back(read());
	}
	printf("%lld",work(a,31));
	return 0;
}