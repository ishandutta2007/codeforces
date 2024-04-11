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
    #define sz 202020
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
int a[sz],aa[sz];

int h[sz];
namespace SA
{
    int sa[sz],rnk[sz],_rnk[sz],tp[sz],cnt[sz];
    int n;
    void Sort(int m)
    {
        rep(i,1,m) cnt[i]=0;
        rep(i,1,n) ++cnt[rnk[i]];
        rep(i,1,m) cnt[i]+=cnt[i-1];
        drep(i,n,1) sa[cnt[rnk[tp[i]]]--]=tp[i];
    }
    void init()
    {
        rep(i,1,n) rnk[i]=a[i],tp[i]=i;
        Sort(n+10);
        for (int p=0,w=1,m=n+10;p<n;m=p,w<<=1)
        {
            p=0;
            rep(i,1,w) tp[++p]=n-i+1;
            rep(i,1,n) if (sa[i]>w) tp[++p]=sa[i]-w;
            Sort(m);
            memcpy(_rnk,rnk,sizeof(rnk));
            rnk[sa[p=1]]=1;
            rep(i,2,n) rnk[sa[i]]=(_rnk[sa[i]]==_rnk[sa[i-1]]&&_rnk[sa[i]+w]==_rnk[sa[i-1]+w])?p:++p;
        }
        for (int i=1,k=0;i<=n;i++)
        {
            if (k) --k;
            int j=sa[rnk[i]-1];
            while (a[i+k]==a[j+k]) ++k;
            h[rnk[i]]=k;
        }
    }
}

#define Tree sz*20
int tr[Tree],ls[Tree],rs[Tree],cnt;
int root[sz];
#define lson ls[k],l,mid
#define rson rs[k],mid+1,r
void insert(int &k,int l,int r,int x,int pre)
{
    k=++cnt;tr[k]=tr[pre]+1;ls[k]=ls[pre];rs[k]=rs[pre];
    if (l==r) return;
    int mid=(l+r)>>1;
    if (x<=mid) insert(lson,x,ls[pre]);
    else insert(rson,x,rs[pre]);
}
int query(int k,int l,int r,int x,int y)
{
    if (!k||x>y) return 0;
    if (x<=l&&r<=y) return tr[k];
    int mid=(l+r)>>1,ret=0;
    if (x<=mid) ret+=query(lson,x,y);
    if (y>mid) ret+=query(rson,x,y);
    return ret;
}
int query(int rnk,int l,int r){return query(root[rnk],1,n,l,r);}
int query(int rnk1,int rnk2,int l,int r){if (rnk1>rnk2) return 0;return query(rnk2,l,r)-query(rnk1-1,l,r);}

int st[sz][25],lg2[sz];
void init()
{
    int N=n+n-1;
    rep(i,1,N) st[i][0]=h[i];
    rep(i,2,N) lg2[i]=lg2[i>>1]+1;
    rep(i,1,N) if (SA::sa[i]>n) insert(root[i],1,n,SA::sa[i]-n,root[i-1]); else root[i]=root[i-1];
    rep(j,1,20)
        rep(i,1,N-(1<<j)+1)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){if (l==r) return 1e9;if (l>r) swap(l,r);++l;int len=lg2[r-l+1];return min(st[l][len],st[r-(1<<len)+1][len]);}

int Query(int p,int len,int type)
{
    p=SA::rnk[p];
    int ret=p,l=1,r=n+n-1;
    if (type) l=p; else r=p;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (query(p,mid)>=len) ret=mid,(type?l=mid+1:r=mid-1);
        else (type?r=mid-1:l=mid+1);
    }
    return ret;
}

int main()
{
    file();
    read(n);
    rep(i,1,n) read(aa[i]);
    rep(i,1,n-1) aa[i]=aa[i+1]-aa[i],a[i]=aa[i],aa[i+n]=a[i+n]=-aa[i];
    a[n]=aa[n]=2e9;
    sort(aa+1,aa+n+n);int _=unique(aa+1,aa+n+n)-aa-1;
    rep(i,1,n+n-1) a[i]=lower_bound(aa+1,aa+_+1,a[i])-aa;
    SA::n=n+n-1;SA::init();
    init();
    int Q;read(Q);
    int x,y,l,r;
    while (Q--)
    {
        read(x,y);--y;
        if (x>y) { printf("%d\n",n-1); continue; }
        l=Query(x,y-x+1,0);
        r=Query(x,y-x+1,1);
        int ans=0,len=y-x+1,t=SA::rnk[x];
        ans+=query(l,t-1,1,x-len-1)+query(l,t-1,y+1+1,n-1);
        ans+=query(t+1,r,1,x-len-1)+query(t+1,r,y+1+1,n-1);
        printf("%d\n",ans);
    }
    return 0;
}