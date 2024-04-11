#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize(2)
#endif
#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define templ template<typename T>
    #define sz 5101010 
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
    char __sr[1<<21],__z[20];int __C=-1,__zz=0;
    inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
    inline void print(register int x)
    {
        if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
        while(__z[++__zz]=x%10+48,x/=10);
        while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
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

int n,m,D;

struct hh{int t,nxt;}edge[sz];
int head[sz],ecnt;
void make_edge(int f,int t){edge[++ecnt]=(hh){t,head[f]};head[f]=ecnt;}

bool ok[sz];

int code(int x,int d){return D*(x-1)+d;}
pii decode(int S){int x=(S-1)/D+1,d=(S-1)%D+1;return MP(x,d);}

int dfn[sz],low[sz],cnt;
stack<int>s;
bool in[sz];
int bel[sz],sum[sz],T;
int vis[sz],c;
int OK(pii t)
{
    int x=t.fir,d=t.sec;
    if (!ok[code(x,d)]) return 0;
    int ret=(vis[x]!=c);
    vis[x]=c;
    return ret;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++cnt;s.push(x);in[x]=1;
    #define v edge[i].t
    go(x)
    {
        if (!dfn[v]) tarjan(v),chkmin(low[x],low[v]);
        else if (in[v]) chkmin(low[x],dfn[v]);
    }
    #undef v
    if (low[x]==dfn[x])
    {
        ++c;++T;
        int y;
        do
        {
            y=s.top();s.pop();in[y]=0;
            bel[y]=T;
            sum[T]+=OK(decode(y));
        }while (y!=x);
    }
}

hh e[sz];
int h[sz],ee;
int deg[sz];
void Make_Edge(int f,int t){e[++ee]=(hh){t,h[f]};h[f]=ee;++deg[t];}
#undef go
#define go(x) for (int i=h[x];i;i=e[i].nxt)
int dp[sz];
void topo()
{
    queue<int>q;
    rep(i,1,T) if (!deg[i]) q.push(i);
    while (!q.empty())
    {
        int x=q.front();q.pop();dp[x]+=sum[x];
        #define v e[i].t
        go(x) 
        {
            chkmax(dp[v],dp[x]);
            if (!--deg[v]) q.push(v);
        }
        #undef v
    }
}
#undef go
#define go(x) for (int i=head[x];i;i=edge[i].nxt)


int main()
{
    file();
    int x,y;
    read(n,m,D);
    rep(i,1,m)
    {
        read(x,y);
        rep(i,1,D-1) make_edge(code(x,i),code(y,i+1));
        make_edge(code(x,D),code(y,1));
    }
    string s;
    rep(i,1,n)
    {
        cin>>s; 
        rep(j,1,D) ok[code(i,j)]=(s[j-1]=='1');
    }
    rep(i,1,D*n) if (!dfn[i]) tarjan(i);
    #define v edge[i].t
    rep(x,1,D*n) 
        go(x) 
            if (bel[v]!=bel[x])
                Make_Edge(bel[v],bel[x]);
    #undef v
    topo();
    cout<<dp[bel[1]];
    return 0;
}