//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
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
std::vector<ll>a;
#define MAXN 300011
struct Trie
{
    ll t[MAXN*25][2],val[MAXN*25],cnt;
    Trie(){cnt=1;}
    void insert(ll x)
    {
        ll u=1;
        for(ll i=24;i>=0;--i)
        {
            ++val[u];
            ll &v=t[u][x>>i&1];
            if(!v)v=++cnt;
            u=v;
        }
        ++val[u];
    }
    ll Query(ll x)
    {
        ll u=1,res=0;
        for(ll i=24;i>=0;--i)
        {
            ll c=x>>i&1;
            if(val[t[u][c]]==(1<<i))u=t[u][!c],res+=(1<<i);
            else u=t[u][c];
            if(!u)break;
        }
        return res;
    }
}t;
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<=n;++i)a.push_back(read());
    std::sort(a.begin(),a.end());
    a.resize(std::unique(a.begin(),a.end())-a.begin());
    for(auto x:a)t.insert(x);
    ll k=0;
    for(ll i=1;i<=m;++i)
    {
        ll x=read();
        k^=x;
        printf("%lld\n",t.Query(k));
    }
    return 0;
}