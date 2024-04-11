//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
typedef int ll;
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
#define MAXN 200011
ll s[MAXN][211];
std::vector<ll>a[MAXN];
int main()
{
    ll t=read();
    while(t--)
    {
    	for(ll i=1;i<=200;++i)a[i].clear();
        ll n=read(),ans=1;
        for(ll i=1;i<=n;++i)
        {
            ll x=read();
            for(ll j=1;j<=200;++j)s[i][j]=s[i-1][j]+(x==j);
            a[x].push_back(i);
        }
        for(ll x=1;x<=200;++x)
        {
            ll l=0,r=ll(a[x].size())-1;
            while(l<r)
            {
                ll t=0;
                for(ll y=1;y<=200;++y)
                    umax(t,s[a[x][r]-1][y]-s[a[x][l]][y]);
                umax(ans,(l+1)*2+t);
                ++l,--r;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}