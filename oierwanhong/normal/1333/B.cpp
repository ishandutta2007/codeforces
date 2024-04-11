//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<28)
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
#define MAXN 200011
ll a[MAXN],b[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read();
        for(ll i=1;i<=n;++i)a[i]=read();
        for(ll i=1;i<=n;++i)b[i]=read();
        bool f1=0,f2=0,f=0;
        for(ll i=1;i<=n;++i)
        {
            if(a[i]<b[i]&&!f1)f=1;
            else if(a[i]>b[i]&&!f2)f=1;
            if(a[i]==1)f1=1;
            else if(a[i]==-1)f2=1;
        }
        puts(f?"NO":"YES");
    }
}