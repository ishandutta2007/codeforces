//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long ll;
typedef int un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
/**********/
#define MAXN 1011
#define MAXL 1000011
const ll mod=998244353;
struct one
{
    ll val,x,y;
    bool operator <(const one& t)const{return val<t.val;}
}a[MAXL];
ll s2[MAXL],sx[MAXL],sy[MAXL],f[MAXL],sumf[MAXL];
ll Qpow(ll a,ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1)res=res*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return res;
}
ll upd(ll x){return (x%mod+mod)%mod;}
int main()
{
    ll n=read(),m=read(),cnt=0;
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j)
        {
            ll val=read();
            a[++cnt]={val,i,j};
        }
    std::sort(a+1,a+cnt+1);
    ll it=1,px=read(),py=read();
    for(ll i=1;i<=cnt;++i)
    {
        while(a[it].val<a[i].val)
        {
            s2[it]=(s2[it-1]+a[it].x*a[it].x+a[it].y*a[it].y)%mod;
            sx[it]=(sx[it-1]+a[it].x)%mod;
            sy[it]=(sy[it-1]+a[it].y)%mod;
            ++it;
        }
        //printf("it=%lld\n",it-1);
        f[i]=upd(sumf[it-1]+s2[it-1] -2*a[i].x*sx[it-1]-2*a[i].y*sy[it-1]+(it-1)*(a[i].x*a[i].x+a[i].y*a[i].y))*Qpow(it-1,mod-2)%mod;
        if(a[i].x==px&&a[i].y==py){printf("%lld",f[i]);return 0;}
        sumf[i]=(sumf[i-1]+f[i])%mod;
    }
    return 0;
}