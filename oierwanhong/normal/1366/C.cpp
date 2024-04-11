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
const ll INF=1ll<<58;
/**********/
#define MAXN 211
ll cnt[2][MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        memset(cnt,0,sizeof cnt);
        ll n=read(),m=read();
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=m;++j)++cnt[read()][i+j-1];
        ll ans=0;
        for(ll p=1;p<=(n+m-1)/2;++p)ans+=min(cnt[0][p]+cnt[0][n+m-p],cnt[1][p]+cnt[1][n+m-p]);
        printf("%lld\n",ans);
    }
}