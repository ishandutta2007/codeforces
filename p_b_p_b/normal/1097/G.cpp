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
    #define sz 101010
    typedef long long ll;
    typedef double db;
    const ll mod=1e9+7;
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

int n,K;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
    edge[++ecnt]=(hh){t,head[f]};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,head[t]};
    head[t]=ecnt;
}
inline ll add(ll x,ll y){x+=y;if (x>=mod) x-=mod;return x;}

ll dp[sz][233],f[sz],ans[233];
int size[sz];
#define v edge[i].t
void dfs(int x,int fa)
{
    size[x]=1;dp[x][0]=2;
    go(x) if (v!=fa)
    {
        dfs(v,x);
        rep(i,0,K) f[i]=0;
        rep(j,0,min(K,size[x]))
            rep(k,0,min(K-j,size[v]))
                f[j+k]=add(f[j+k],dp[x][j]*dp[v][k]%mod);
        rep(j,0,K) dp[x][j]=f[j];
        rep(j,0,K) ans[j]=add(ans[j],mod-dp[v][j]);
        size[x]+=size[v];
    }
    rep(i,0,K) ans[i]=add(ans[i],dp[x][i]);
    drep(i,K,1) dp[x][i]=add(dp[x][i],dp[x][i-1]);
    dp[x][1]=add(dp[x][1],mod-1);
}
#undef v
void solve(){dfs(1,0);}

ll S[233][233];

int main()
{
    file();
    int x,y;
    read(n,K);
    rep(i,1,n-1) read(x,y),make_edge(x,y);
    S[1][1]=1;
    rep(i,2,K)
        rep(j,1,K)
            S[i][j]=add(S[i-1][j-1],S[i-1][j]*j%mod);
    int fac=1,Ans=0;
    solve();
    rep(i,1,K)
    {
        fac=1ll*fac*i%mod;
        Ans=add(Ans,1ll*fac*S[K][i]%mod*ans[i]%mod);
    }
    cout<<Ans;
    return 0;
}