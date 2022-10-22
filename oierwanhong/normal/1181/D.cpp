//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>
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
#define MAXN 500011
ll n,m,q;
struct Segment_Tree
{
    ll t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void modify(un pos,ll k,un l=1,un r=n,un num=1)
    {
        if(l==r){rt+=k;return;}
        un mid=(l+r)>>1;
        if(pos<=mid)modify(pos,k,l,mid,num<<1);
        else modify(pos,k,mid+1,r,num<<1|1);
        rt=tl+tr;
    }
    ll Qkth(ll k,un l=1,un r=n,un num=1)
    {
        if(l==r)return l;
        un mid=(l+r)>>1;
        if(k<=tl)return Qkth(k,l,mid,num<<1);
        else return Qkth(k-tl,mid+1,r,num<<1|1);
    }
    ll size(){return t[1];}
}sgt;
std::vector<ll>g[MAXN];
ll c[MAXN],ans[MAXN];
pll query[MAXN];
int main()
{
    m=read(),n=read(),q=read();
    for(ll i=1;i<=m;++i)++c[read()];
    for(ll i=1;i<=n;++i)g[c[i]].push_back(i);
    for(ll i=1;i<=q;++i)query[i]=pll(read()-m,i);
    std::sort(query+1,query+q+1);
    ll cur=0,sum=0,it=1;
    for(ll i=0;i<=m;++i)
    {
        for(auto x:g[i])sgt.modify(x,1),++cur;
        while(it<=q&&query[it].first-sum<=cur)ans[query[it].second]=sgt.Qkth(query[it].first-sum),++it;
        sum+=cur;
    }
    while(it<=q)ans[query[it].second]=sgt.Qkth((query[it].first-sum-1)%n+1),++it;
    for(ll i=1;i<=q;++i)printf("%lld\n",ans[i]);
    return 0;
}