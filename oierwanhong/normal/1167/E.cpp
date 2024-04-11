//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
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
#define MAXN 1000011
ll first[MAXN],last[MAXN],premax[MAXN];
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<=n;++i)
    {
        ll x=read();
        if(!first[x])first[x]=i;
        last[x]=i;
        premax[i]=max(premax[i-1],x);
    }
    ll suf=m+1,pos=n+1;
    for(ll i=m;i;--i)
    {
        if(!first[i]){suf=i;continue;}
        if(last[i]>pos)break;
        suf=i,pos=first[i];
    }
    ll ans=0,it=0;
    for(ll l=1;l<=m;++l)
    {
        ll r=max(suf-1,l);
        umax(r,premax[it]);
        //printf("r=%lld\n",r);
        ans+=m-r+1;
        if(first[l])
        {
            if(first[l]<it)break;
            it=last[l];
        }
    }
    printf("%lld",ans);
    return 0;
}