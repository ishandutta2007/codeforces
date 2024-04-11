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
#define MAXN 111
char a[MAXN][MAXN],b[MAXN][MAXN];
ll p1,x,k;
char turn(ll x)
{
	if(x<=10)return '0'+x-1;
	if(x<=36)return 'a'+x-11;
	return 'A'+x-37;
}
void work(ll n,ll m,ll sx,ll sy,ll cur,ll rest)
{
	if(!n||!m)return;
	if(n==1)
	{
		for(ll j=1;j<=m;++j)
		{
			ll i=1;
			b[sx+i-1][sy+j-1]=turn(cur);
			if(a[sx+i-1][sy+j-1]=='R')
			{
				if(!--rest)
				{
					++cur;
					if(cur<=p1)rest=x+1;
					else rest=x;
					if(cur>k)cur=k;
				}
			}
		}
		return;
	}
	if(m==1)
	{
		for(ll i=1;i<=n;++i)
		{
			ll j=m;
			b[sx+i-1][sy+j-1]=turn(cur);
			if(a[sx+i-1][sy+j-1]=='R')
			{
				if(!--rest)
				{
					++cur;
					if(cur<=p1)rest=x+1;
					else rest=x;
					if(cur>k)cur=k;
				}
			}
		}
		return;
	}
	for(ll j=1;j<=m;++j)
	{
		ll i=1;
		b[sx+i-1][sy+j-1]=turn(cur);
		if(a[sx+i-1][sy+j-1]=='R')
		{
			if(!--rest)
			{
				++cur;
				if(cur<=p1)rest=x+1;
				else rest=x;
				if(cur>k)cur=k;
			}
		}
	}
	for(ll i=2;i<=n;++i)
	{
		ll j=m;
		b[sx+i-1][sy+j-1]=turn(cur);
		if(a[sx+i-1][sy+j-1]=='R')
		{
			if(!--rest)
			{
				++cur;
				if(cur<=p1)rest=x+1;
				else rest=x;
				if(cur>k)cur=k;
			}
		}
	}
	for(ll j=m-1;j;--j)
	{
		ll i=n;
		b[sx+i-1][sy+j-1]=turn(cur);
		if(a[sx+i-1][sy+j-1]=='R')
		{
			if(!--rest)
			{
				++cur;
				if(cur<=p1)rest=x+1;
				else rest=x;
				if(cur>k)cur=k;
			}
		}
	}
	for(ll i=n-1;i>1;--i)
	{
		ll j=1;
		b[sx+i-1][sy+j-1]=turn(cur);
		if(a[sx+i-1][sy+j-1]=='R')
		{
			if(!--rest)
			{
				++cur;
				if(cur<=p1)rest=x+1;
				else rest=x;
				if(cur>k)cur=k;
			}
		}
	}
	work(n-2,m-2,sx+1,sy+1,cur,rest);
}
int main()
{
	ll task=read();
	while(task--)
	{
		ll n=read(),m=read();
		k=read();
		ll cnt=0;
		for(ll i=1;i<=n;++i)scanf("%s",a[i]+1);
		for(ll i=1;i<=n;++i)b[i][m+1]=0;
		for(ll i=1;i<=n;++i)
			for(ll j=1;j<=m;++j)
				if(a[i][j]=='R')++cnt;
		p1=cnt%k,x=cnt/k;
		work(n,m,1,1,1,p1?x+1:x);
		for(ll i=1;i<=n;++i)printf("%s\n",b[i]+1);
	}
	return 0;
}