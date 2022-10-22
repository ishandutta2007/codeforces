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
ll n,m,cnt=0;
char a[511][511];
bool check(ll i,ll j)
{
	ll x=i,y=j,tmp=1;
	while(x>1&&a[x-1][j]=='*')--x,++tmp;
	x=i;
	while(x<n&&a[x+1][j]=='*')++x,++tmp;
	x=i;
	while(y>1&&a[i][y-1]=='*')--y,++tmp;
	y=j;
	while(y<m&&a[i][y+1]=='*')++y,++tmp;
	return tmp==cnt;
}
int main()
{
	n=read(),m=read();
	for(ll i=1;i<=n;++i)
	{
		char c=getchar();
		while(c!='.'&&c!='*')c=getchar();
		if(c=='*')++cnt;
		a[i][1]=c;
		for(ll j=2;j<=m;++j)
		{
			a[i][j]=getchar();
			if(a[i][j]=='*')++cnt;
		}
	}
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)
			if(a[i][j]=='*'&&a[i-1][j]=='*'&&a[i+1][j]=='*'&&a[i][j-1]=='*'&&a[i][j+1]=='*'&&check(i,j))
			{
				std::cout<<"YES";
				return 0;
			}
	std::cout<<"NO";
	return 0;
}