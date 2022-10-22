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
#define MAXN 1011
ll a[MAXN][MAXN];
void work(ll x,ll y,ll n,ll k=0)
{
	if(n==4)
	{
		ll now=n*n-1;
		for(ll i=1;i<=n;++i)
		{
			for(ll j=1;j<=n;++j)a[x+i-1][y+j-1]=(now--)+k;
		}
		return;
	}
	
	for(ll i=0;;++i)
	{
		if(x+4*i>n)break;
		for(ll j=0;;++j)
			if(y+4*j>n)break;
			else work(x+4*i,y+4*j,4,k),k+=16;
	}
}
int main()
{
	ll n=read();
	work(1,1,n);
	for(ll i=1;i<=n;++i)
	{
		for(ll j=1;j<=n;++j)printf("%lld ",a[i][j]);
		putchar('\n');
	}
	return 0;
}