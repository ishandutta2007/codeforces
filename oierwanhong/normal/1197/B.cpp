//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef std::string str;
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
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
#define MAXN 200011
ll a[MAXN];
int main()
{
	ll n=read();
	bool flag=0,yes=1;
	for(ll i=1;i<=n;++i)
	{
		a[i]=read();
		if(a[i]==n)flag=1;
		else if(!flag)
		{
			if(a[i]<a[i-1])yes=0;
		}
		else if(flag)
		{
			if(a[i]>a[i-1])yes=0;
		}
	}
	if(yes)puts("YES");
	else puts("NO");
	return 0;
}