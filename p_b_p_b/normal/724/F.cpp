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
    #define sz 1010
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
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,d;ll mod;
ll dp[sz][15][sz];
ll inv[15];

ll dfs(int i,int j,int k)
{
    k=min(k,n-1);
    if (dp[i][j][k]!=-1) return dp[i][j][k];
    if (i==1) return j==0||j==d-1;
    if (!k) return 0;
    ll ret=dfs(i,j,k-1),s=dfs(k,d-1,k-1),cur=1;
    rep(t,1,j)
    {
        if (t*k>=i) break;
        ll c=dfs(i-t*k,j-t,k-1);
        cur=cur*(s+t-1)%mod*inv[t]%mod;
        ret=(ret+c*cur%mod)%mod;
    }
    return dp[i][j][k]=ret;
}

int main()
{
    file();
    read(n,d,mod);
    if (n<=2) return puts("1"),0;
    inv[1]=1;
    rep(i,2,d) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    memset(dp,-1,sizeof(dp));
    ll ans=dfs(n,d,n/2);
    if (n%2==0)
    {
        ll s=dfs(n/2,d-1,n/2-1);
        ans=(ans-(s*(s-1)/2)%mod+mod)%mod;
    }
    cout<<ans;
}