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
    #define sz 1010101
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
char s[sz];
int sum[sz];
vector<int>v[sz];

namespace SA
{
    int sa[sz],rnk[sz],_rnk[sz],tp[sz],cnt[sz];
    int h[sz];
    void Sort(int m)
    {
        rep(i,1,m) cnt[i]=0;
        rep(i,1,n) ++cnt[rnk[i]];
        rep(i,1,m) cnt[i]+=cnt[i-1];
        drep(i,n,1) sa[cnt[rnk[tp[i]]]--]=tp[i];
    }
    void init()
    {
        rep(i,1,n) rnk[i]=s[i],tp[i]=i;
        Sort(200);
        for (int p=0,w=1,m=200;p<n;w<<=1,m=p)
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
}

int st[sz][20],lg2[sz];
void init()
{
    rep(i,1,n) st[i][0]=sum[i];
    rep(j,1,20)
        rep(i,1,n-(1<<j)+1)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    rep(i,2,n) lg2[i]=lg2[i>>1]+1;
}
int query(int l,int r){int len=lg2[r-l+1];return min(st[l][len],st[r-(1<<len)+1][len]);}

ll solve(int p)
{
    int l=p,r=n,R=-1;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (query(p,mid)>=sum[p-1]) R=mid,l=mid+1;
        else r=mid-1;
    }
    int L=p+SA::h[SA::rnk[p]];
    if (L>R) return 0;
    auto s=v[sum[p-1]].begin(),t=v[sum[p-1]].end();
    return upper_bound(s,t,R)-lower_bound(s,t,L);
}

int main()
{
    file();
    read(n);
    cin>>(s+1);
    SA::init();
    sum[0]=n;rep(i,1,n) sum[i]=sum[i-1]+(s[i]=='('?1:-1),v[sum[i]].push_back(i);
    init();
    ll ans=0;
    rep(i,1,n) ans+=solve(i);
    cout<<ans;
    return 0;
}