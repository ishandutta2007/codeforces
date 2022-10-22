//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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

/**********/
#define MAXN 200011
ll f[MAXN][3],n,a[MAXN],b[MAXN];
int main()
{
	ll n=read(),ans=0;
	for(ll i=1;i<=n;++i)a[i]=read();
	for(ll i=1;i<=n;++i)b[i]=read();
	for(ll i=1;i<=n;++i)
	{
		f[i][0]=max(f[i-1][0],max(f[i-1][1],f[i-1][2]));
		f[i][1]=max(f[i-1][0],f[i-1][2])+a[i];
		f[i][2]=max(f[i-1][0],f[i-1][1])+b[i];
		ans=max(ans,max(f[i][0],max(f[i][1],f[i][2])));
	}
	std::cout<<ans;
	return 0;
}