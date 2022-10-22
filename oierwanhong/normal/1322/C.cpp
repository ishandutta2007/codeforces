//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<ctime>
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
const ll mod1=998244353,mod2=ll(1e9+7);
ll base,pw1[MAXN],pw2[MAXN];
ll f1[MAXN],f2[MAXN],w[MAXN];
std::map<pll,ll>p;
ll gcd(ll a,ll b)
{
    if(!b)return a;
    return gcd(b,a%b);
}
int main()
{
    srand(time(0));rand(),rand();
    base=rand();
    pw1[0]=pw2[0]=1;
    for(ll i=1;i<MAXN;++i)pw1[i]=pw1[i-1]*base%mod1,pw2[i]=pw2[i-1]*base%mod2;
    ll task=read();
    while(task--)
    {
        p.clear();
        ll n=read(),m=read();
        for(ll i=1;i<=n;++i)w[i]=read(),f1[i]=f2[i]=0;
        for(ll i=1;i<=m;++i)
        {
            ll u=read(),v=read();
            f1[v]=(f1[v]+pw1[u])%mod1;
            f2[v]=(f2[v]+pw2[u])%mod2;
        }
        ll cnt=0,ans=0;
        for(ll i=1;i<=n;++i)
        {
            //printf("%lld %lld\n",f1[i],f2[i]);
            if(f1[i]==0&&f2[i]==0)continue;
            else p[pll(f1[i],f2[i])]+=w[i];
        }
        for(auto x:p)ans=gcd(ans,x.second);
        printf("%lld\n",ans);
    }
    return 0;
}