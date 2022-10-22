//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
typedef int ll;
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
#define MAXN 100011
struct Trie
{
    ll t[MAXN*40][2],val[MAXN*40],cnt=1;
    void insert(ll x)
    {
        ll u=1;
        for(ll i=30;i>=0;--i)
        {
            ++val[u];
            ll &v=t[u][(x>>i)&1];
            if(!v)v=++cnt;
            u=v;
        }
        ++val[u];
    }
    void erase(ll x)
    {
        ll u=1;
        for(ll i=30;i>=0;--i)
        {
            --val[u];
            u=t[u][(x>>i)&1];
        }
        --val[u];
    }
    ll Query(ll p,ll l)
    {
        ll u=1,res=0;
        for(ll i=30;i>=0;--i)
        {
        	ll v=0;
            for(ll j=0;j<=1;++j)
                if((j^((p>>i)&1))<((l>>i)&1))res+=val[t[u][j]];
                else if((j^((p>>i)&1))==((l>>i)&1))v=t[u][j];
            if(!v)break;
            u=v;
        }
        return res;
    }
}t;
int main()
{
    ll n=read();
    while(n--)
    {
        ll op=read(),p=read();
        if(op==1)t.insert(p);
        else if(op==2)t.erase(p);
        else printf("%d\n",t.Query(p,read()));
    }
    return 0;
}