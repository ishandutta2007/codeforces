//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXM 2011
struct one
{
    ll a[5],maxv;
    ll f(ll n,ll s)
    {
        ll sum=0;
        for(ll j=0;j<n;++j)
            if(s&(1<<j))sum+=a[j+1];
        return sum;
    }
    void shift(ll n)
    {
        ll t=a[1];
        for(ll i=1;i<n;++i)a[i]=a[i+1];
        a[n]=t;
    }
    bool operator <(const one& t)const
    {
        return maxv>t.maxv;
    }
}a[MAXM];
ll f[MAXM][1<<12],g[MAXM][1<<12];
int main()
{
    ll task=read();
    while(task--)
    {
        memset(f,0,sizeof f);
        memset(a,0,sizeof a);
        ll n=read(),m=read();
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=m;++j)a[j].a[i]=read(),umax(a[j].maxv,a[j].a[i]);
        std::sort(a+1,a+m+1);
        umin(m,n);
        ll all=(1<<n)-1;
        for(ll i=1;i<=m;++i)
        {
            for(ll s=0;s<=all;++s)
            {
                g[i][s]=0;
                for(ll x=0;x<n;++x)umax(g[i][s],a[i].f(n,s)),a[i].shift(n);
            }
            for(ll s=0;s<=all;++s)
                for(ll t=s;;t=(t-1)&s)
                {
                    umax(f[i][s],f[i-1][t]+g[i][s^t]);
                    if(!t)break;
                }
        }
        printf("%lld\n",f[m][all]);
    }
}