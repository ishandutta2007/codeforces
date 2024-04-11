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
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<28;
/**********/
#define MAXN 300011
std::vector<ll>a[MAXN];
ll fx[MAXN],len;
ll place(ll val){return std::lower_bound(fx+1,fx+len+1,val)-fx;}
void solve()
{
	len=0;
    ll n=read(),ans=n;
    for(ll i=1;i<=n;++i)
    {
        ll x=read();
        fx[++len]=x;
        a[x].push_back(i);
    }
    std::sort(fx+1,fx+len+1),len=std::unique(fx+1,fx+len+1)-fx-1;
    ll pos=n+1,cur=0;
    for(ll i=n;i;--i)
    {
        if(!a[i].size())continue;
        if(a[i].back()<pos)++cur;
        else cur=1;
        pos=a[i].front();
        umin(ans,len-cur);
        a[i].clear();
    }
    std::cout<<ans<<'\n';
}
int main()
{
    ll task=read();
    while(task--)solve();
}