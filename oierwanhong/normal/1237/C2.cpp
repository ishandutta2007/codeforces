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
const ll INF=1ll<<58;
/**********/
#define MAXN 200011
struct point
{
    ll x,y,z,dex;
    bool operator <(const point& t)const
    {
        if(x==t.x)
            return y<t.y;
        return x<t.x;
    }
}a[MAXN];
ll d[MAXN],len=0;
ll place(ll val){return std::lower_bound(d+1,d+len+1,val)-d;}
std::vector<point>b[MAXN];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)
    {
        a[i].x=read(),a[i].y=read(),a[i].z=read(),a[i].dex=i;
        d[++len]=a[i].z;
    }
    std::sort(d+1,d+len+1),len=std::unique(d+1,d+len+1)-d-1;
    for(ll i=1;i<=n;++i)b[place(a[i].z)].push_back(a[i]);
    ll pre=0;
    for(ll i=1;i<=len;++i)
    {
        std::sort(b[i].begin(),b[i].end());
        std::map<ll,ll>p;
        for(auto val:b[i])
            if(p.count(val.x))printf("%lld %lld\n",p[val.x],val.dex),p.erase(val.x);
            else p[val.x]=val.dex;
        ll tmp=0;
        for(auto x:p)
            if(tmp)printf("%lld %lld\n",tmp,x.second),tmp=0;
            else tmp=x.second;
        if(!tmp)continue;
        if(pre)
            printf("%lld %lld\n",pre,tmp),pre=0;
        else pre=tmp;
    }
    return 0;
}