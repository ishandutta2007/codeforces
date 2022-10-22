//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 1011
#define MAXR 30011
std::vector<pll>pos,neg;
bool cmp_pos(pll a,pll b)
{
    return a.first<b.first;
}
bool cmp_neg(pll a,pll b)
{
    return a.first+a.second>b.first+b.second;
}
ll f[MAXN][MAXR];
int main()
{
    ll n=read(),k=read(),cnt=0;
    for(ll i=1;i<=n;++i)
    {
        ll a=read(),b=read();
        if(b<0)neg.push_back(pll(max(a,-b),b));
        else pos.push_back(pll(a,b));
    }
    std::sort(pos.begin(),pos.end(),cmp_pos);std::sort(neg.begin(),neg.end(),cmp_neg);
    for(auto x:pos)
        if(k>=x.first)k+=x.second,++cnt;
    f[0][k]=cnt;
    for(ll i=0;i<ll(neg.size());++i)
        for(ll j=0;j<=k;++j)
        {
            if(j>=neg[i].first&&j+neg[i].second>=0)umax(f[i+1][j+neg[i].second],f[i][j]+1);
            umax(f[i+1][j],f[i][j]);
        }
    ll ans=0;
    for(ll i=0;i<=k;++i)umax(ans,f[neg.size()][i]);
    printf("%lld",ans);
    return 0;
}