//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib> 
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
#define MAXN 100011
ll a[MAXN];
int main()
{
	ll n=read(),m=read(),k=read();
	for(ll i=1;i<=m;++i)a[i]=read();
	ll it=1,ans=0,tmp=k;
	while(it<=m)
	{
		ll cnt=0;
		while(it<=m&&a[it]<=tmp)++it,++cnt;
		while(cnt)
		{
			++ans;
			tmp+=cnt;
			cnt=0; 
			while(it<=m&&a[it]<=tmp)++it,++cnt;
		}
		if(it<=n)tmp+=(a[it]-tmp-1)/k*k+k;
	}
	std::cout<<ans;
	return 0;
}