//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
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
ll a[111],vis[111];
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),m=read();
        for(ll i=1;i<=n;++i)a[i]=read(),vis[i]=0;
        for(ll i=1;i<=m;++i)vis[read()]=1;
        bool flag=0;
        for(ll i=1;i<n;++i)
        {
            for(ll j=1;j<=n-i;++j)
                if(a[j]>a[j+1])
                {
                    if(!vis[j])flag=1;
                    std::swap(a[j],a[j+1]);
                }
        }
        puts(flag?"NO":"YES");
    }
    return 0;
}