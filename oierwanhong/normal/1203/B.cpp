//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
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
#define MAXN 1011
#define MAXE 10011
ll a[MAXN],c[MAXE];
void work()
{
	memset(c,0,sizeof c);
	ll n=read();
	for(ll i=1;i<=n*4;++i)a[i]=read(),++c[a[i]];
	bool flag=0;
	ll maxv=0,minv=MAXE;
	for(ll i=1;i<MAXE;++i)
	{
		if(c[i])
		{
			umin(minv,i);
			umax(maxv,i);
			if(c[i]&1)flag=1;
		}
	}
	//printf("max=%lld min=%lld\n",maxv,minv);
	if(flag)
	{
		puts("NO");return;
	}
	ll k=minv*maxv;
	for(ll i=1;i<MAXE;++i)
	{
		if(c[i])
		{
			if(k%i||c[k/i]!=c[i])
			{
				flag=1;break;
			}
			c[k/i]=c[i]=0;
		}
	}
	if(flag)puts("NO");
	else puts("YES");
}
int main()
{
	ll q=read();
	while(q--)work();
	return 0;
}