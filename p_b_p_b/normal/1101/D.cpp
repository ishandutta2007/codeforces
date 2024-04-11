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
    #define sz 202020
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

int n;
int a[sz];
map<int,int>dp[sz];
int ans;

struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
    edge[++ecnt]=(hh){t,head[f]};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,head[t]};
    head[t]=ecnt;
}

int pri[sz],cnt;
bool npri[sz];
void init()
{
    #define xx (i*pri[j])
    npri[1]=1;
    rep(i,2,sz-1)
    {
        if (!npri[i]) pri[++cnt]=i;
        rep(j,1,cnt)
        {
            if (xx>=sz) break;
            npri[xx]=1;
            if (i%pri[j]==0) break;
        }
    }
}

#define v edge[i].t
void dfs(int x,int fa)
{
    go(x) if (v!=fa)
    {
        dfs(v,x);
        for (auto j=dp[x].begin();j!=dp[x].end();j++)
            ans=max(ans,j->sec+dp[v][j->fir]),j->sec=max(j->sec,dp[v][j->fir]+1);
    }
}
#undef v

int main()
{
    file();
    int x,y;
    init();
    read(n);
    rep(i,1,n)
    {
        read(x);
        for (int j=1,p;p=pri[j],p*p<=x;j++) if (x%p==0)
        {
            dp[i][p]=1;
            if (!npri[x/p]) dp[i][x/p]=1;
        }
        if (!npri[x]) dp[i][x]=1;
        if (x!=1) ans=1;
    }
    rep(i,1,n-1) read(x,y),make_edge(x,y);
    dfs(1,0);
    cout<<ans;
    return 0;
}