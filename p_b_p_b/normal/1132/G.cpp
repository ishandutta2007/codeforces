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
    #define sz 1001010
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

int n,m;
int a[sz];
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
    edge[++ecnt]=(hh){t,head[f]};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,head[t]};
    head[t]=ecnt;
}

int dfn[sz],low[sz],cnt;
void dfs(int x,int fa)
{
    dfn[x]=++cnt;
    go(x) if (edge[i].t!=fa) dfs(edge[i].t,x);
    low[x]=cnt;
}

void build()
{
    stack<int>s;
    rep(i,1,n)
    {
        while (!s.empty()&&a[s.top()]<a[i]) make_edge(s.top(),i),s.pop();
        s.push(i);
    }
    while (!s.empty()) make_edge(s.top(),n+1),s.pop();
}

int mx[sz<<2];
int tag[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void Add(int k,int w){mx[k]+=w;tag[k]+=w;}
void pushdown(int k){Add(ls,tag[k]);Add(rs,tag[k]);tag[k]=0;}
void pushup(int k){mx[k]=max(mx[ls],mx[rs]);}
void add(int k,int l,int r,int x,int y)
{
    if (x<=l&&r<=y) return Add(k,1);
    int mid=(l+r)>>1;
    pushdown(k);
    if (x<=mid) add(lson,x,y);
    if (y>mid) add(rson,x,y);
    pushup(k);
}
void modify(int k,int l,int r,int x)
{
    if (l==r) return void(mx[k]=-1e9);
    int mid=(l+r)>>1;
    pushdown(k);
    if (x<=mid) modify(lson,x);
    else modify(rson,x);
    pushup(k);
}

int main()
{
    file();
    read(n,m);
    rep(i,1,n) read(a[i]);
    build();
    dfs(n+1,0);
    rep(i,1,n) --dfn[i],--low[i];
    rep(i,1,n)
    {
        add(1,1,n,dfn[i],low[i]);
        if (i>m) modify(1,1,n,dfn[i-m]);
        if (i>=m) printf("%d ",mx[1]);
    }
    return 0;
}