//Send again by Luogu
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
#define MAXN 100011
ll ans=INF;
pll a[MAXN],p[MAXN];
ll dist(pll a,pll b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
void closest_pair(un l,un r)
{
    if(l==r)return;
    un mid=(l+r)>>1;
    ll split_line=a[mid].first;
    closest_pair(l,mid),closest_pair(mid+1,r);
    //merge_sort
    {
        un mid=(l+r)>>1,i=l,j=mid+1,k=l;
        while(i<=mid&&j<=r)
            if(a[i].second<=a[j].second)p[k++]=a[i++];
            else p[k++]=a[j++];
        while(i<=mid)p[k++]=a[i++];
        while(j<=r)p[k++]=a[j++];
        for(ll w=l;w<=r;++w)a[w]=p[w];
    }
    ll cnt=0;
    for(ll i=l;i<=r;++i)
        if((a[i].first-split_line)*(a[i].first-split_line)<ans)p[++cnt]=a[i];
    for(ll i=1;i<=cnt;++i)
        for(ll j=i-1;j>0&&(p[i].second-p[j].second)*(p[i].second-p[j].second)<ans;--j)
            umin(ans,dist(p[i],p[j]));
}
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)a[i]=pll(i,a[i-1].second+read());
    closest_pair(1,n);
    printf("%lld",ans);
    return 0;
}