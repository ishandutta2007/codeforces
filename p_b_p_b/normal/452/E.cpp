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
    #define sz 303030
    #define mod 1000000007
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
int p[sz],pos[sz];
int sum[4][sz];
char s[sz];

int rnk[sz],sa[sz],tp[sz],_rnk[sz],cnt[sz];
int h[sz];
void Sort(int m)
{
    rep(i,1,m) cnt[i]=0;
    rep(i,1,n) ++cnt[rnk[i]];
    rep(i,1,m) cnt[i]+=cnt[i-1];
    drep(i,n,1) sa[cnt[rnk[tp[i]]]--]=tp[i];
}
void init_sa()
{
    rep(i,1,n) rnk[i]=s[i],tp[i]=i;
    Sort(233);
    for (int p=0,w=1,m=233;p<n;w<<=1,m=p)
    {
        p=0;
        rep(i,n-w+1,n) tp[++p]=i;
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
        while (s[i+k]==s[j+k]) ++k;
        h[rnk[i]]=k;
    }
}
void init()
{
    init_sa();
    rep(i,1,n) sum[pos[rnk[i]]=p[i]][rnk[i]]=1;
    rep(k,1,3) rep(i,1,n) sum[k][i]+=sum[k][i-1];
}

ll ans[sz];
int fa[sz],L[sz],R[sz],mn[sz];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
ll get(int l,int r){ll ret=1;rep(i,1,3) ret=ret*(sum[i][r]-sum[i][l-1])%mod;return ret;}
void merge(int x,int y)
{
    x=getfa(x);y=getfa(y);
    (ans[h[L[y]]]+=get(L[x],R[y])-get(L[x],R[x])-get(L[y],R[y])+mod+mod)%=mod;
    R[x]=R[y];mn[x]=h[L[y]];fa[y]=x;
}

int id[sz],cc[sz];

int main()
{
    file();
    int len=1e9;
    rep(i,1,3)
    {
        cin>>(s+n+1);int m=strlen(s+1);
        rep(j,n+1,m) p[j]=i;
        chkmin(len,m-n);
        n=m+1;s[n]='z'+i;
    }
    init();
    rep(i,1,n) fa[i]=L[i]=R[i]=i,mn[i]=1e9;
    rep(i,1,n) ++cc[h[i]];
    rep(i,1,n) cc[i]+=cc[i-1];
    rep(i,1,n) id[cc[h[i]]--]=i;
    drep(i,n,1) if (id[i]!=1) merge(id[i]-1,id[i]);
    drep(i,n,1) (ans[i]+=ans[i+1])%=mod;
    rep(i,1,len) printf("%I64d ",ans[i]);
    return 0;
}