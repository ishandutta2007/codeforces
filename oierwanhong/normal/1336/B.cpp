//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
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
const ll INF=ll(2e9);
ll a[MAXN];
std::set<ll>s1,s2;
ll f(std::set<ll>& s,ll x)
{
    auto it=s.lower_bound(x);
    if(it!=s.end())
    {
        if(it==s.begin())return *it;
        auto p=it--;
        return (*p)-x<x-*it?*p:*it;
    }
    else return *--it;
}
int main()
{
    ll t=read();
    while(t--)
    {
        s1.clear(),s2.clear();
        ll n1=read(),n2=read(),n3=read(),ans=2*INF*INF;
        for(ll i=1;i<=n1;++i)a[i]=read();
        for(ll i=1;i<=n2;++i)s1.insert(read());
        for(ll i=1;i<=n3;++i)s2.insert(read());
        for(ll i=1;i<=n1;++i)
        {
            auto it1=s1.lower_bound(a[i]);
            if(it1!=s1.end())
            {
                ll p=f(s2,(a[i]+*it1)>>1);
                umin(ans,(a[i]-p)*(a[i]-p)+(a[i]-*it1)*(a[i]-*it1)+(*it1-p)*(*it1-p));
            }
            if(it1!=s1.begin())
            {
                ll p=f(s2,(a[i]+*--it1)>>1);
                umin(ans,(a[i]-p)*(a[i]-p)+(a[i]-*it1)*(a[i]-*it1)+(*it1-p)*(*it1-p));
            }
            it1=s2.lower_bound(a[i]);
            if(it1!=s2.end())
            {
                ll p=f(s1,(a[i]+*it1)>>1);
                umin(ans,(a[i]-p)*(a[i]-p)+(a[i]-*it1)*(a[i]-*it1)+(*it1-p)*(*it1-p));
            }
            if(it1!=s2.begin())
            {
                ll p=f(s1,(a[i]+*--it1)>>1);
                umin(ans,(a[i]-p)*(a[i]-p)+(a[i]-*it1)*(a[i]-*it1)+(*it1-p)*(*it1-p));
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}