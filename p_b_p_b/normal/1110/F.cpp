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
    #define sz 505050
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
struct hh{int t;ll w;int nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t,ll w)
{
    edge[++ecnt]=(hh){t,w,head[f]};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,w,head[t]};
    head[t]=ecnt;
}
int deg[sz];

struct hhh{int l,r,id;};
vector<hhh>q[sz];
ll ans[sz];

ll mn[sz<<2],tag[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void Add(int k,ll w){tag[k]+=w;mn[k]+=w;}
void pushdown(int k){ll &t=tag[k];Add(ls,t);Add(rs,t);t=0;}
void pushup(int k){mn[k]=min(mn[ls],mn[rs]);}
void modify(int k,int l,int r,int x,ll y)
{
    if (l==r) return (void)(mn[k]=y);
    int mid=(l+r)>>1;
    pushdown(k);
    if (x<=mid) modify(lson,x,y);
    else modify(rson,x,y);
    pushup(k);
}
void modify(int k,int l,int r,int x,int y,ll w)
{
    if (x<=l&&r<=y) return Add(k,w);
    pushdown(k);
    int mid=(l+r)>>1;
    if (x<=mid) modify(lson,x,y,w);
    if (y>mid) modify(rson,x,y,w);
    pushup(k);
}
ll query(int k,int l,int r,int x,int y)
{
    if (x<=l&&r<=y) return mn[k];
    pushdown(k);
    int mid=(l+r)>>1;
    ll ret=LLONG_MAX;
    if (x<=mid) chkmin(ret,query(lson,x,y));
    if (y>mid) chkmin(ret,query(rson,x,y));
    return ret;
}

ll D[sz];
int mx[sz];
#define v edge[i].t
void dfs_(int x,int fa)
{
    modify(1,1,n,x,(deg[x]==1)?D[x]:ll(1e15));
    mx[x]=x;
    go(x) if (v!=fa) D[v]=D[x]+edge[i].w,dfs_(v,x),chkmax(mx[x],mx[v]);
}
void dfs(int x,int fa)
{
    for (auto w:q[x]) ans[w.id]=query(1,1,n,w.l,w.r);
    go(x) if (v!=fa)
    {
        ll w=edge[i].w;
        modify(1,1,n,v,mx[v],-w*2);Add(1,w);
        dfs(v,x);
        modify(1,1,n,v,mx[v],w*2);Add(1,-w);
    }
}
#undef v

int main()
{
    file();
    read(n,m);
    int x,y,z;
    rep(i,2,n) read(x,y),make_edge(x,i,y),++deg[x],++deg[i];
    rep(i,1,m) read(z,x,y),q[z].push_back((hhh){x,y,i});
    dfs_(1,0);dfs(1,0);
    rep(i,1,m) printf("%lld\n",ans[i]);
    return 0;
}