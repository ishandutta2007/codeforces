//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
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
#define MAXN 5011
bool vis[MAXN];
ll a[MAXN],b[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read();
        for(ll i=1;i<=n*2;++i)vis[i]=0;
        bool flag=0;
        for(ll i=1;i<=n;++i)b[i]=read(),vis[b[i]]=1;
        for(ll i=1;i<=n;++i)
        {
            a[i*2-1]=b[i];
            a[i*2]=0;
            for(ll j=b[i];j<=2*n;++j)
                if(!vis[j]){a[i*2]=j;vis[j]=1;break;}
            if(!a[i*2])flag=1;
        }
        if(flag)puts("-1");
        else
        {
            for(ll i=1;i<=2*n;++i)printf("%lld ",a[i]);
            puts("");
        }
    }
}