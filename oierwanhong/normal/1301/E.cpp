//By Luogu send again.
//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef int ll;
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
#define MAXN 505
ll a[MAXN][MAXN],b[MAXN][MAXN],c[MAXN][MAXN],d[MAXN][MAXN],f[MAXN/2][MAXN][MAXN];
ll s(ll sum[][MAXN],ll x1,ll y1,ll x2,ll y2)
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main()
{
	ll n=read(),m=read(),task=read();
	for(ll i=1;i<=n;++i)
	{
		char cur;
		for(ll j=1;j<=m;++j)
		{
			std::cin>>cur;
			a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+(cur=='R');
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+(cur=='G');
			c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+(cur=='Y');
			d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+(cur=='B');
			//printf("%d ",a[i][j]);
		}
		//putchar('\n');
	}
	for(ll k=1;k<=250;++k)
		for(ll i=k<<1;i<=n;++i)
			for(ll j=k<<1;j<=m;++j)
			{
				f[k][i][j]=f[k][i-1][j]+f[k][i][j-1]-f[k][i-1][j-1];
				ll sa=s(a,i-k-k+1,j-k-k+1,i-k,j-k),sb=s(b,i-k-k+1,j-k+1,i-k,j),sc=s(c,i-k+1,j-k-k+1,i,j-k),sd=s(d,i-k+1,j-k+1,i,j);
				if(sa==k*k && sb==k*k && sc==k*k && sd==k*k)++f[k][i][j];
			}
	while(task--)
	{
		ll x1=read(),y1=read(),x2=read(),y2=read();
		ll l=0,r=min((x2-x1+1)/2,(y2-y1+1)/2);
		while(l<r)
		{
			ll mid=(l+r+1)>>1,tmp=s(f[mid],x1+mid+mid-1,y1+mid+mid-1,x2,y2);
			if(tmp>0)l=mid;
			else r=mid-1;
		}
		printf("%d\n",l*l*4);
	}
	return 0;
}