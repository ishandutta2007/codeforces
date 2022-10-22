//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
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
#define MAXN 111
char a[MAXN][MAXN];
ll n,m,cnt_all,cnt_edge,cnt_corner;
bool flag;
bool calc_all()
{
	cnt_all=cnt_edge=cnt_corner=0;
	flag=0;
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)
			if(a[i][j]=='A')
			{
				++cnt_all;
				ll c=(i==1||i==n)+(j==1||j==m);
				if(c==1)++cnt_edge;
				if(c==2)++cnt_corner;
			}
	return cnt_all==n*m;
}
bool calc_edge()
{
	for(ll i=1;i<=n;++i)
	{
		ll tmp=0;
		for(ll j=1;j<=m;++j)
			if(a[i][j]=='A')++tmp;
		if(tmp==m)
		{
			if(i==1||i==n)return 1;
			flag=1;
		}
	}
	for(ll j=1;j<=m;++j)
	{
		ll tmp=0;
		for(ll i=1;i<=n;++i)
			if(a[i][j]=='A')++tmp;
		if(tmp==n)
		{
			if(j==1||j==m)return 1;
			flag=1;
		}
	}
	return 0;
}
int main()
{
	ll task=read();
	while(task--)
	{
		flag=0;
		n=read(),m=read();
		for(ll i=1;i<=n;++i)scanf("%s",a[i]+1);
		if(calc_all())
		{
			puts("0");continue;
		}
		if(calc_edge())
		{
			puts("1");continue;
		}
		if(cnt_corner||flag)puts("2");
		else if(cnt_edge)puts("3");
		else if(cnt_all)puts("4");
		else puts("MORTAL");
	}
	return 0;
}