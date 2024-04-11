//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
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
#define MAXN 100011
ll v[MAXN],p[MAXN];
struct one
{
    ll s,t,d,w;
    void in(){s=read(),t=read(),d=read(),w=read();}
    bool operator <(const one& a)
    const
    {
        if(w==a.w)return d<a.d;
        return w<a.w;
    }
}a[MAXN];
bool cmps(one a,one b)
{
    return a.s<b.s;
}
std::priority_queue<one>q;
ll f[MAXN][203];
int main()
{
    ll n=read(),m=read(),k=read();
    for(ll i=1;i<=k;++i)a[i].in();
    std::sort(a+1,a+k+1,cmps);
    v[0]=0,p[0]=1;
    ll it=1;
    for(ll i=1;i<=n;++i)
    {
        while(it<=k&&a[it].s<=i)q.push(a[it]),++it;
        while(!q.empty()&&q.top().t<i)q.pop();
        if(q.empty())v[i]=0,p[i]=i+1;
        else v[i]=q.top().w,p[i]=q.top().d+1;
    }
    memset(f,0x3f,sizeof f);
    f[0][0]=0;
    for(ll i=0;i<=n;++i)
        for(ll j=0;j<=m;++j)
        {
            umin(f[i+1][j+1],f[i][j]);
            umin(f[p[i]][j],f[i][j]+v[i]);
        }
    ll ans=INF;
    for(ll j=0;j<=m;++j)umin(ans,f[n+1][j]);
    printf("%lld",ans);
    return 0;
}