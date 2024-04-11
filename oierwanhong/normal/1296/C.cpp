//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
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
#define MAXN 200011
std::map<pll,ll>p;
char a[MAXN];
void mov(pll& now,char op)
{
	if(op=='L')--now.first;
	if(op=='R')++now.first;
	if(op=='U')++now.second;
	if(op=='D')--now.second;
}
int main()
{
	ll task=read();
	while(task--)
	{
		p.clear();
		ll n=read(),ans=INF,l,r;
		pll now(0,0);
		p[now]=0;
		scanf("%s",a+1);
		for(ll i=1;i<=n;++i)
		{
			mov(now,a[i]);
			if(p.count(now)&&umin(ans,i-p[now]))l=p[now]+1,r=i;
			p[now]=i;
		}
		if(ans==INF)puts("-1");
		else printf("%lld %lld\n",l,r);
	}
	return 0;
}