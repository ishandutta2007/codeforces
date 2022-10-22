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
ll a[MAXN],fx[MAXN],c[MAXN],nn;
ll place(ll val)
{
    return std::lower_bound(fx+1,fx+nn+1,val)-fx;
}
int main()
{
    ll n=read(),k=read();
    for(ll i=1;i<=n;++i)fx[i]=a[i]=read();
    std::sort(fx+1,fx+n+1);
    nn=std::unique(fx+1,fx+n+1)-fx-1;
    for(ll i=1;i<=n;++i)++c[place(a[i])];
    for(ll i=1;i<=n;++i)
        if(c[i]>=k)
        {
            puts("0");return 0;
        }
    ll ans=INF,cnt=0,costl=0,costr=0;
    for(ll i=1;i<=nn;++i)costr+=fx[i]*c[i];
    for(ll i=1;i<=nn;++i)
    {
        costl+=cnt*(fx[i]-fx[i-1]);costr-=(n-cnt)*(fx[i]-fx[i-1]);
        cnt+=c[i];
        if(cnt>=k)
        {
            umin(ans,costl-min(cnt-k,cnt-c[i]));
            continue;
        }
        umin(ans,costl+costr-min(n-k,n-c[i]));
    }
    cnt=0;
    for(ll i=nn;i;--i)
    {
        costr+=cnt*(fx[i+1]-fx[i]);if(i<nn)costl-=(n-cnt)*(fx[i+1]-fx[i]);
        cnt+=c[i];
        if(cnt>=k)
        {
            umin(ans,costr-min(cnt-k,cnt-c[i]));
            continue;
        }
        umin(ans,costl+costr-min(n-k,n-c[i]));
    }
    printf("%lld",ans);
    return 0;
}