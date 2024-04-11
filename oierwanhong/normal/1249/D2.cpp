//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
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
#define MAXN 500011
std::vector<pll>a[MAXN];
std::priority_queue<pll>q;
ll c[MAXN];
bool del[MAXN];
bool cmp(pll a,pll b){return a.first>b.first;}
int main()
{
    ll n=read(),k=read();
    for(ll i=1;i<=n;++i)
    {
        ll l=read(),r=read();
        if(l>r)std::swap(l,r);
        a[l].push_back(pll(r,i));
    }
    ll ans=0,cur=0;
    for(ll i=1;i<=ll(2e5);++i)
    {
        cur+=c[i];
        for(auto x:a[i])
            q.push(x),--c[x.first+1],++cur;
        while(cur>k)
        {
            del[q.top().second]=1;++c[q.top().first+1];
            q.pop();--cur;
        }
    }
    for(ll i=1;i<=n;++i)ans+=del[i];
    printf("%lld\n",ans);
    for(ll i=1;i<=n;++i)
        if(del[i])printf("%lld ",i);
}