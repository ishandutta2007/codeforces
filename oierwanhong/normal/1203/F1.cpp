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
#define MAXN 2011
std::vector<pll>pos,neg;
bool cmp_pos(pll a,pll b)
{
    return a.first<b.first;
}
bool cmp_neg(pll a,pll b)
{
    return a.first+a.second>b.first+b.second;
}
int main()
{
    ll n=read(),k=read();
    for(ll i=1;i<=n;++i)
    {
        ll a=read(),b=read();
        if(b<0)neg.push_back(pll(a,b));
        else pos.push_back(pll(a,b));
    }
    std::sort(pos.begin(),pos.end(),cmp_pos);std::sort(neg.begin(),neg.end(),cmp_neg);
    for(auto x:pos)
        if(k<x.first){puts("NO");return 0;}
        else k+=x.second;
    for(auto x:neg)
        if(k<x.first){puts("NO");return 0;}
        else k+=x.second;
    puts(k<0?"NO":"YES");
    return 0;
}