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
    #define sz 101100
    #define mod 1000000007ll
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
    char __sr[1<<21],__z[20];int __C=-1,__Z=0;
    inline void __Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
    inline void print(register int x)
    {
    	if (__C>1<<20) __Ot(); if (x<0) __sr[++__C]='-',x=-x;
    	while (__z[++__Z]=x%10+48,x/=10);
    	while (__sr[++__C]=__z[__Z],--__Z);__sr[++__C]='\n';
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

int n;
struct hh{int t;ll w;int nxt;int col;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t,ll w,int col)
{
    edge[++ecnt]=(hh){t,w,head[f],col};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,w,head[t],col};
    head[t]=ecnt;
}

int T;
struct BIT
{
    ll prod[sz<<2];
    int size[sz<<2];
    int mark[sz<<2];
    void mul(int x,ll w)
    {
        x+=n*2;
        while (x<=n*4) 
        {
            if (mark[x]!=T) size[x]=0,prod[x]=1;
            ++size[x],prod[x]=prod[x]*w%mod;mark[x]=T;
            x+=(x&(-x));
        }
    }
    void query(int x,ll &w1,int &w2)
    {
        w1=1,w2=0;x+=n*2;
        while (x) 
        {
            if (mark[x]==T) w1=w1*prod[x]%mod,w2+=size[x];
            x-=(x&(-x));
        }
    }
}T1,T2;

ll ans=1;
#define v edge[i].t
bool vis[sz];
int size[sz],mn,root,tot;
void findroot(int x,int fa)
{
    size[x]=1;
    int S=-1;
    go(x) if (v!=fa&&!vis[v])
    {
        findroot(v,x);
        size[x]+=size[v];
        chkmax(S,size[v]);
    }
    chkmax(S,tot-size[x]);
    if (chkmin(mn,S)) root=x;
}
struct hhh{int aa,bb;ll w;};
hhh s[sz];int cnt;
void dfs(int x,int fa,int a,int b,ll w)
{
    s[++cnt]=(hhh){2*a-b,2*b-a,w};
    go(x) if (v!=fa&&!vis[v])
    {
        if (edge[i].col) dfs(v,x,a,b+1,w*edge[i].w%mod);
        else dfs(v,x,a+1,b,w*edge[i].w%mod);
    }
}
void calc(int x)
{
    ++T;T1.mul(0,1);T2.mul(0,1);
    go(x) if (!vis[v])
    {
        cnt=0;
        if (edge[i].col) dfs(v,0,0,1,edge[i].w);
        else dfs(v,0,1,0,edge[i].w);
        rep(i,1,cnt)
        {
            ll w1;int w2;
            T1.query(s[i].aa,w1,w2);
            ans=ans*w1%mod*ksm(s[i].w,w2)%mod;
            T2.query(-s[i].bb-1,w1,w2);
            ans=ans*inv(w1*ksm(s[i].w,w2)%mod)%mod;
        }
        rep(i,1,cnt) T1.mul(-s[i].aa,s[i].w),T2.mul(s[i].bb,s[i].w);
    }
}
void solve(int x)
{
    vis[x]=1;
    calc(x);
    int all=tot;
    go(x) if (!vis[v])
    {
        tot=size[v];if (size[v]>size[x]) tot=all-size[x];mn=1e9;
        findroot(v,0);
        solve(root);
    }
}
#undef v

int main()
{
    file();
    int x,y,z,c;
    read(n);
    rep(i,1,n-1) read(x,y,z,c),make_edge(x,y,z,c);
    tot=n;mn=1e9;findroot(1,0);
    solve(root);
    cout<<ans;
    return 0;
}