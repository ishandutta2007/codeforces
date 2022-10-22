//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
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
std::map<ll,ll>p[MAXN];
ll a[MAXN],cnt[MAXN];
int main()
{
    ll n=read(),ans=0;
    for(ll i=1;i<=n;++i)a[i]=read(),ans+=a[i];
    ll q=read();
    while(q--)
    {
        ll s=read(),t=read(),u=read();
        if(p[s].count(t))
        {
            ll v=p[s][t];
            if(cnt[v]<=a[v])++ans;
            --cnt[v];
            p[s].erase(t);
        }
        if(u)
        {
            if(cnt[u]<a[u])--ans;
            ++cnt[u];
            p[s][t]=u;
        }
        printf("%lld\n",ans);
    }
    return 0;
}