#include<bits/stdc++.h>
clock_t _t=clock();
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
    #define sz 101010
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
        cout<<(clock()-_t)/1000.0<<'\n';
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

int n;ll T;
int s[sz],t[sz];
struct hh{int t;ll w;int nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t,ll w){edge[++ecnt]=(hh){t,w,head[f]};head[f]=ecnt;}

#define Tree sz*30
ll sum[Tree],size[Tree];
int ls[Tree],rs[Tree],cnt;
int root;
#define lson ls[k],l,mid
#define rson rs[k],mid+1,r
void insert(int &k,int l,int r,int x,int y) // size:x , time:y
{
    if (!k) k=++cnt;
    sum[k]+=1ll*x*y,size[k]+=x;
    if (l==r) return;
    int mid=(l+r)>>1;
    if (y<=mid) insert(lson,x,y);
    else insert(rson,x,y);
}
ll query(int k,int l,int r,ll S)
{
    if (!k||!size[k]||!S) return 0;
    if (l==r) return min(size[k],S/(sum[k]/size[k]));
    int mid=(l+r)>>1;
    if (S>=sum[ls[k]]) return query(rson,S-sum[ls[k]])+size[ls[k]];
    else return query(lson,S);
}

ll dp[sz];
void dfs(int x,ll S)
{
    if (S<0) return;
    insert(root,1,1e6,s[x],t[x]);
    dp[x]=query(root,1,1e6,S);
    ll mx=-1,_mx=-1;
    #define v edge[i].t
    go(x)
    {
        dfs(v,S-2ll*edge[i].w);
        if (dp[v]>=mx) _mx=mx,mx=dp[v];
        else if (dp[v]>=_mx) _mx=dp[v];
    }
    #undef v
    insert(root,1,1e6,-s[x],t[x]);
    chkmax(dp[x],_mx);
    if (x==1) chkmax(dp[x],mx);
}

int main()
{
    file();
    read(n,T);
    rep(i,1,n) read(s[i]);
    rep(i,1,n) read(t[i]);
    int x,y;
    rep(i,2,n) read(x,y),make_edge(x,i,y);
    dfs(1,T);
    cout<<dp[1];
    return 0;
}