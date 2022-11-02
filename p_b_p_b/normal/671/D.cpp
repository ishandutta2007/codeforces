#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
    using namespace std;
    #define pil pair<int,ll>
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
        freopen("a.txt","r",stdin);
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
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
    edge[++ecnt]=(hh){t,head[f]};
    head[f]=ecnt;
    edge[++ecnt]=(hh){f,head[t]};
    head[t]=ecnt;
}

#define Tree (sz*20)
ll tr[Tree],tag[Tree];
int ls[Tree],rs[Tree],size[Tree],cnt;
int bin[Tree],top;
void del(int k){tr[k]=1e17;tag[k]=ls[k]=rs[k]=0;if (top<Tree-1) bin[++top]=k;}
int newnode(){int k=(top?bin[top--]:++cnt);tr[k]=1e17;return k;}
#define lson ls[k],l,mid
#define rson rs[k],mid+1,r
void Add(int k,ll w){if (!k) return;tr[k]+=w;tag[k]+=w;}
void pushdown(int k){Add(ls[k],tag[k]);Add(rs[k],tag[k]);tag[k]=0;}
void ins(int &k,int l,int r,int x,ll y)
{
    if (!k) size[k=newnode()]=1;
    chkmin(tr[k],y);
    if (l==r) return;
    pushdown(k);
    int mid=(l+r)>>1;
    if (x<=mid) ins(lson,x,y);
    else ins(rson,x,y);
    size[k]=size[ls[k]]+size[rs[k]];
}
ll query(int k,int l,int r,int x,int y)
{
    if (!k) return 1e17;
    if (x<=l&&r<=y) return tr[k];
    int mid=(l+r)>>1;ll ret=1e17;
    pushdown(k);
    if (x<=mid) chkmin(ret,query(lson,x,y));
    if (y>mid) chkmin(ret,query(rson,x,y));
    return ret;
}
int root[sz];
void merge(int &k,int l,int r,int &k2)
{
    if (!k2) return;
    if (!k) size[k=newnode()]=1;
    if (size[k]<size[k2]) swap(k,k2);
    chkmin(tr[k],tr[k2]);
    if (l==r) return del(k2);
    int mid=(l+r)>>1;
    pushdown(k);pushdown(k2);
    merge(lson,ls[k2]);
    merge(rson,rs[k2]);
    del(k2);
    size[k]=size[ls[k]]+size[rs[k]];
}

vector<pil>V[sz];
int dep[sz];

void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    ins(root[x],1,n,dep[x],0);
    #define v edge[i].t
    go(x) if (v!=fa)
    {
        dfs(v,x);
        ll w1=query(root[x],1,n,1,dep[x]),w2=query(root[v],1,n,1,dep[x]);
        Add(root[x],w2);Add(root[v],w1);
        merge(root[x],1,n,root[v]);
    }
    #undef v
    ll w;
    for (auto v:V[x]) 
        w=query(root[x],1,n,1,dep[x]),ins(root[x],1,n,dep[v.fir],w+v.sec);
}

int main()
{
    file();
    int x,y,z;
    read(n,m);
    rep(i,1,n-1) read(x,y),make_edge(x,y);
    rep(i,1,m) read(x,y,z),V[x].push_back(MP(y,z));
    dfs(1,0);
    ll ans=query(root[1],1,n,1,1);
    printf("%lld",ans>=1e16||ans<0?-1ll:ans);
    return 0;
}