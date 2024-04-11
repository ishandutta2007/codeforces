//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
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
#define MAXN 200011
char a[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),k=read(),tot=n*(n-1)/2,cnt=0;
        for(ll i=1;i<=n;++i)
        {
            if(cnt==0)tot=(n-i)*(n-i-1)/2;
            else if(cnt==1)tot=n-i;
            else tot=INF;
            //printf("%lld ",tot);
            if(k>tot)putchar('b'),k-=tot,++cnt;
            else putchar('a');
        }
        putchar('\n');
    }
    return 0;
}