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
ll a[1011][1011];
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<=n;++i)
    {
        ll x=read();
        for(ll j=1;j<=x;++j)a[i][j]=1;
        a[i][x+1]=-1;
    }

    for(ll i=1;i<=m;++i)
    {
        ll x=read();
        for(ll j=1;j<=x;++j)
            if(a[j][i]==-1){return puts("0")&0;}
            else a[j][i]=1;
        if(a[x+1][i]==1){return puts("0")&0;}
        else a[x+1][i]=-1;
    }
    ll ans=1,mod=ll(1e9+7);
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=m;++j)
            if(!a[i][j])ans=(ans<<1)%mod;
    printf("%lld",ans);
}