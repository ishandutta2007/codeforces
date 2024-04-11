//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
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
#define MAXN 100011
ll fa[51][MAXN],fsum[51][MAXN],fmx[51][MAXN];
int main()
{
    ll n=read(),k=read();
    for(ll i=1;i<=n;++i)fa[0][i]=read()+1;
    for(ll i=1;i<=n;++i)fsum[0][i]=fmx[0][i]=read();
    for(ll i=1;i<=50;++i)
        for(ll j=1;j<=n;++j)
        {
            ll nxt=fa[i-1][j];
            fa[i][j]=fa[i-1][nxt];
            fsum[i][j]=fsum[i-1][j]+fsum[i-1][nxt];
            fmx[i][j]=min(fmx[i-1][j],fmx[i-1][nxt]);
        }
    for(ll u=1;u<=n;++u)
    {
        ll s=0,mx=INF,pos=u,x=k;
        for(ll i=50;i>=0;--i)
            if((x>>i)&1)s+=fsum[i][pos],umin(mx,fmx[i][pos]),pos=fa[i][pos];
        printf("%lld %lld\n",s,mx);
    }
    return 0;
}