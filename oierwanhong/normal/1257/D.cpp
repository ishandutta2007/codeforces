//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1<<28;
/**********/
#define MAXN 200011
ll sufmax[MAXN],b[MAXN];
pll a[MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read(),mx=0;
        for(ll i=1;i<=n;++i)b[i]=read(),umax(mx,b[i]);
        ll m=read();
        for(ll i=1;i<=m;++i)a[i].first=read(),a[i].second=read();
        std::sort(a+1,a+m+1);
        if(mx>a[m].first){puts("-1");continue;}
        sufmax[m+1]=0;
        for(ll i=m;i;--i)sufmax[i]=max(sufmax[i+1],a[i].second);
        ll ans=1,cnt=0,maxv=0;
        for(ll i=1;i<=n;++i)
        {
            ++cnt,umax(maxv,b[i]);
            if(sufmax[std::lower_bound(a+1,a+m+1,pll(maxv,0))-a]<cnt)++ans,cnt=1,maxv=b[i];
        }
        printf("%lld\n",ans);
    }
}