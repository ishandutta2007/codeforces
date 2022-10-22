#include<iostream>
#include<cstdio>
typedef long long ll;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
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

#define maxn 1011
ll s1[maxn],s2[maxn],t1[maxn],t2[maxn];
ll a[maxn][maxn],b[maxn][maxn];
int main()
{
	ll n=read(),m=read();
	for(ll i=1;i<=n;++i)
	{
		s1[i]=0;
		for(ll j=1;j<=m;++j)
			if(a[i][j]=read())++s1[i];
	}
	for(ll i=1;i<=m;++i)
	{
		s2[i]=0;
		for(ll j=1;j<=n;++j)
			if(a[j][i])++s2[i];
	}
	for(ll i=1;i<=n;++i)
	{
		t1[i]=0;
		for(ll j=1;j<=m;++j)
			if(b[i][j]=read())++t1[i];
	}
	for(ll i=1;i<=m;++i)
	{
		t2[i]=0;
		for(ll j=1;j<=n;++j)
			if(b[j][i])++t2[i];
	}
	bool flag=1;
	for(ll i=1;i<=n;++i)
		if((s1[i]&1)!=(t1[i]&1))flag=0;
	for(ll i=1;i<=m;++i)
		if((s2[i]&1)!=(t2[i]&1))flag=0;
	if(flag)puts("Yes");
	else puts("No");
	return 0;
}