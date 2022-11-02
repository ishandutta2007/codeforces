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
    #define sz 603030
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

int n;
int N=3e5;
pii a[sz];int cnt;
int L[sz],R[sz];
map<pii,int>m;

vector<pii>p[sz<<1];
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r
void insert(int k,int l,int r,int x,int y,pii t)
{
    if (x<=l&&r<=y) return void(p[k].push_back(t));
    int mid=(l+r)>>1;
    if (x<=mid) insert(lson,x,y,t);
    if (y>mid) insert(rson,x,y,t);
}
int fa[sz],dep[sz],size1[sz],size2[sz];
ll ans;
int getfa(int x){return fa[x]==x?x:getfa(fa[x]);}
struct hh{int x,y,t;/*fa[x]=y,dep[y]+=t*/};
void reset(hh s)
{
    fa[s.x]=s.x;dep[s.y]-=s.t;
    ans-=1ll*size1[s.y]*size2[s.y];
    size1[s.y]-=size1[s.x];size2[s.y]-=size2[s.x];
    ans+=1ll*size1[s.x]*size2[s.x]+1ll*size1[s.y]*size2[s.y];
}
void Reset(stack<hh>s){while (!s.empty()) reset(s.top()),s.pop();}
hh merge(int x,int y)
{
    if (dep[x]>dep[y]) swap(x,y);
    fa[x]=y;
    ans-=1ll*size1[x]*size2[x]+1ll*size1[y]*size2[y];
    size1[y]+=size1[x];size2[y]+=size2[x];
    ans+=1ll*size1[y]*size2[y];
    hh ret=(hh){x,y,0};
    if (dep[x]==dep[y]) ++dep[y],ret.t=1;
    return ret;
}
void work(int k,int l,int r)
{
    stack<hh>s;
    for (pii e:p[k])
    {
        int x=e.fir,y=e.sec;
        x=getfa(x);y=getfa(y);
        if (x==y) continue;
        s.push(merge(x,y));
    }
    if (l==r) return printf("%lld ",ans),Reset(s);
    int mid=(l+r)>>1;
    work(lson);work(rson);
    Reset(s);
}

int main()
{
    file();
    rep(i,1,N) fa[i]=i,size1[i]=1;
    rep(i,N+1,N+N) fa[i]=i,size2[i]=1;
    read(n);
    int x,y,z;
    rep(i,1,n)
    {
        read(x,y);
        if ((z=m[MP(x,y)])) R[z]=i,m.erase(MP(x,y));
        else m[MP(x,y)]=++cnt,L[cnt]=i,a[cnt]=MP(x,y+N);
    }
    rep(i,1,cnt) if (!R[i]) R[i]=n+1;
    rep(i,1,cnt) insert(1,1,n,L[i],R[i]-1,a[i]);
    work(1,1,n);
    return 0;
}