#include<bits/stdc++.h>
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define sz 233
    #define mod (ll(1e9+7))
    typedef long long ll;
    typedef double db;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    template<typename T>inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
    template<typename T>inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
        t=(f?-t:t);
    }
    template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
    void file()
    {
        #ifndef ONLINE_JUDGE
        freopen("a.txt","r",stdin);
        #endif
    }
    #ifdef mod
    ll ksm(ll x,int y){ll ret=1;if (y<=0) return 1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
    ll inv(ll x){return ksm(x,mod-2);}
    #else
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
    #endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,p;
int a[sz];
ll dp[sz][2][2][2];

template<typename T>inline void add(T &x,T y){(x+=y)%=mod;}

int main()
{
    file();
    read(n,p);
    rep(i,1,n) read(a[i]);
    dp[0][0][0][0]=1;
    rep(i,1,n) rep(t,0,1) rep(j,0,1) rep(k,0,1) // dp[i-1][t][j][k]->dp[i][?][?][?]
    {
        ll cur=dp[i-1][t][j][k];
        if (a[i]!=1)
        {
            if (k) add(dp[i][t][j][k],cur*ksm(2,i-2)%mod),add(dp[i][t^1][j|1][k],cur*ksm(2,i-2)%mod);
            else add(dp[i][t^1][j|1][k],cur*ksm(2,i-1)%mod);
        }
        if (a[i]!=0)
        {
            if (j) add(dp[i][t][j][k],cur*ksm(2,i-2)%mod),add(dp[i][t^1][j][k|1],cur*ksm(2,i-2)%mod);
            else add(dp[i][t^1][j][k|1],cur*ksm(2,i-1)%mod);
        }
    }
    ll ans=0;
    rep(i,0,1) rep(j,0,1) add(ans,dp[n][p][i][j]);
    cout<<ans;
    return 0;
}