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
ll a[MAXN],b[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read();
        for(ll i=1;i<=n;++i)a[i]=read();
        b[1]=1;
        ll pos=0,flag=1;
        for(ll i=2;i<=n;b[i]=3-b[i-1],++i)
            if(a[i]==a[i-1])pos=i;
            else flag=0;
        if(a[1]!=a[n])
        {
            if(n%2==0)
            {
                puts("2");
                for(ll i=1;i<=n;++i)printf("%lld ",b[i]);
                putchar('\n');
            }
            else if(pos)
            {
                puts("2");
                for(ll i=1;i<=n;++i)
                {
                    if(i>=pos)b[i]=3-b[i];
                    printf("%lld ",b[i]);
                }
                putchar('\n');
            }
            else
            {
                puts("3");
                for(ll i=1;i<=n;++i)
                    if(i==n)puts("3");
                    else printf("%lld ",b[i]);
            }
        }
        else
        {
            if(flag)
            {
                puts("1");
                for(ll i=1;i<=n;++i)printf("1 ");
                putchar('\n');
            }
            else
            {
                puts("2");
                for(ll i=1;i<=n;++i)printf("%lld ",b[i]);
                putchar('\n');
            }
        }
    }
    return 0;
}