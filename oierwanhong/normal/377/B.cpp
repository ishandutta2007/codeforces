//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
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
#define MAXN 100011
struct one
{
	ll b,c,dex;
	bool operator <(const one& t)
	const
	{
		return c>t.c;
	}
}p[MAXN];
pll a[MAXN];
ll f[MAXN],n,m,s;
bool check(ll k)
{
    std::priority_queue<one>q,emp;
    ll sum=0,it=n;
    for(ll i=m;i>0;--i)
    {
		while(it&&p[it].b>=a[i].first)q.push(p[it--]);
		if(q.empty())return 0;
		sum+=q.top().c;
		for(ll j=i;j>max(i-k,0);--j)f[a[j].second]=q.top().dex;
		q.pop();
		i-=k-1;
    }
	return sum<=s;
}
bool cmp(one a,one b)
{
	return a.b<b.b;
}
int main()
{
    n=read(),m=read(),s=read();
    for(ll i=1;i<=m;++i)a[i]=pll(read(),i);
    for(ll i=1;i<=n;++i)p[i].b=read();
    for(ll i=1;i<=n;++i)p[i].c=read(),p[i].dex=i;
    std::sort(a+1,a+m+1),std::sort(p+1,p+n+1,cmp);
    un l=0,r=m+1,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check(mid))r=mid;
		else l=mid+1;
    }
	if(r==m+1)puts("NO");
	else
	{
		puts("YES");
		check(l);
		for(ll i=1;i<=m;++i)printf("%lld ",f[i]);
	}
	return 0;
}