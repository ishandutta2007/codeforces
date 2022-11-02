#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
    using namespace std;
    #define pli pair<ll,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define templ template<typename T>
    #define sz 303030
    typedef long long ll;
    typedef double db;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
    templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
    templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
    templ inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
        t=(f?-t:t);
    }
    template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
    char sr[1<<21],z[20];int C=-1,Z=0;
    inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
    inline void print(register int x)
    {
    	if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
    	while(z[++Z]=x%10+48,x/=10);
    	while(sr[++C]=z[Z],--Z);sr[++C]='\n';
    }
    void file()
    {
        #ifndef ONLINE_JUDGE
        freopen("a.in","r",stdin);
        #endif
    }
    inline void chktime()
    {
        #ifndef ONLINE_JUDGE
        cout<<(clock()-t)/1000.0<<'\n';
        #endif
    }
    #ifdef mod
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
    ll inv(ll x){return ksm(x,mod-2);}
    #else
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
    #endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n,m;
int S;
struct hh{int t,nxt;}edge[sz<<1],R[sz<<1];
int head[sz],ecnt,Rh[sz],Recnt;
void make_edge(int f,int t)
{
    edge[++ecnt]=(hh){t,head[f]};
    head[f]=ecnt;
    R[++Recnt]=(hh){f,Rh[t]};
    Rh[t]=Recnt;
}

namespace build_DAG
{
    struct hh{int t,w,nxt;}edge[sz<<1];
    int head[sz],ecnt;
    void make_edge(int f,int t,int w)
    {
        edge[++ecnt]=(hh){t,w,head[f]};
        head[f]=ecnt;
        edge[++ecnt]=(hh){f,w,head[t]};
        head[t]=ecnt;
    }
    #define v edge[i].t
    ll dis[sz];
    void dijkstra()
    {
        rep(i,1,n) dis[i]=1e18;
        dis[S]=0;
        priority_queue<pli,vector<pli>,greater<pli>>q;
        q.push(MP(0,S));
        while (!q.empty())
        {
            ll d=q.top().fir;int x=q.top().sec;q.pop();
            if (d!=dis[x]) continue;
            go(x) 
                if (chkmin(dis[v],d+edge[i].w))
                    q.push(MP(dis[v],v));
        }
    }
    void init()
    {
        read(n,m,S);
        int x,y,z;
        rep(i,1,m) read(x,y,z),make_edge(x,y,z);
        dijkstra();
        rep(x,1,n)
            go(x)
                if (dis[v]==dis[x]+edge[i].w)
                    ::make_edge(x,v);
    }
    #undef v
}

int id[sz];
int deg[sz];
#define v edge[i].t
void topo()
{
    rep(x,1,n) go(x) ++deg[v];
    queue<int>q;
    int cnt=0;
    rep(i,1,n) if (!deg[i]) q.push(i);
    while (!q.empty())
    {
        int x=q.front();q.pop();
        id[++cnt]=x;
        go(x) if (!(--deg[v])) q.push(v);
    }
    assert(cnt==n); 
}
#undef v
int fa[sz][25],dep[sz];
vector<int>V[sz];
int lca(int x,int y)
{
    if (dep[x]<dep[y]) swap(x,y);
    drep(i,20,0)
        if (fa[x][i]&&dep[fa[x][i]]>=dep[y])
            x=fa[x][i];
    if (x==y) return x;
    drep(i,20,0)
        if (fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
void build()
{
    dep[S]=1;
    rep(i,2,n)
    {
        int x=id[i];
        int cur=-1;
        for (int j=Rh[x];j;j=R[j].nxt)
        {
            int v=R[j].t;
            if (cur==-1) cur=v;
            else cur=lca(cur,v);
        }
        fa[x][0]=cur;dep[x]=dep[cur]+1;V[cur].push_back(x);
        rep(i,1,20) fa[x][i]=fa[fa[x][i-1]][i-1];
    }
}
int size[sz];
void dfs(int x)
{
    size[x]=1;
    for (int v:V[x]) dfs(v),size[x]+=size[v];
}

int main()
{
    file();
    build_DAG::init();
    topo();
    build();
    dfs(S);
    int ans=0;
    rep(i,1,n) if (i!=S) chkmax(ans,size[i]);
    cout<<ans;
    return 0;
}