//Wan Hong 2.1
//notebook
#include<iostream>
#include<algorithm>
#include<cstdio>
typedef long long ll;
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

#define maxn 200011
ll n,m,k,ans=0;
ll p[maxn],vis[maxn],sum[maxn],f[maxn];
ll calc(ll l,ll r)
{
	return sum[r]-sum[l-1];
}
struct sale
{
	ll x,y;
	bool operator <(const sale &t)
	const
	{
		return x<t.x;
	}
}a[maxn];
int main()
{
	n=read(),m=read(),k=read();
	for(ll i=1;i<=n;++i)p[i]=read();
	std::sort(p+1,p+n+1);
	std::reverse(p+1,p+k+1);
	for(ll i=1;i<=k;++i)
		sum[i]=sum[i-1]+p[i];
	for(ll i=1;i<=m;++i)a[i].x=read(),a[i].y=read();
	std::sort(a+1,a+m+1);
	
	ll cnt=0;
	for(ll i=1;i<=m;++i)
	{
		if(a[i].x>k)break;
		if(a[i].x!=a[cnt].x)a[++cnt]=a[i];
		else a[cnt].y=max(a[cnt].y,a[i].y);
	}
	
	f[0]=0;
	for(ll i=1;i<=k;++i)
	{
		f[i]=f[i-1]+p[i];
		for(ll j=1;j<=cnt;++j)
			if(i-a[j].x>=0)
				f[i]=min(f[i],f[i-a[j].x]+calc(i-a[j].x+1,i-a[j].y));
	}
	
	std::cout<<f[k];
	return 0;
}