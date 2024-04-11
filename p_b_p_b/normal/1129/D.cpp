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
    #define sz 201010
    #define S 320
    #define mod 998244353ll
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

int n,K;
int a[sz];
int lst[sz],pre[sz];

int cnt[sz]; // cnt[i]+tag[bel[i]]cnt 
int tag[S]; //  
int W[sz]; //  
int sum[S][sz]; // cntcnt
int SS[S]; // cntcnt<=K 
int L[S],R[S],bel[sz];
int blo;
void init()
{
    blo=sqrt(n);
    rep(i,1,n)
    {
        int t=bel[i]=(i-1)/blo+1;
        if (!L[t]) L[t]=i;
        R[t]=i;
    }
}
bool ok(int c,int id){return c+tag[id]<=K;}
void add1(int id,int w)
{
    if (w==1) (SS[id]-=sum[id][K-tag[id]+n])%=mod;
    else (SS[id]+=sum[id][K-tag[id]+1+n])%=mod;
    tag[id]+=w;
}
void add2(int l,int r,int w)
{
    rep(i,l,r) 
    {
        (sum[bel[i]][cnt[i]+n]-=W[i])%=mod;
        if (ok(cnt[i],bel[i])) (SS[bel[i]]-=W[i])%=mod;
        cnt[i]+=w;
        (sum[bel[i]][cnt[i]+n]+=W[i])%=mod;
        if (ok(cnt[i],bel[i])) (SS[bel[i]]+=W[i])%=mod;
    }
}
void add(int l,int r,int w)
{
    if (l>r) return;
    if (bel[r]-bel[l]<=1) return add2(l,r,w);
    add2(l,R[bel[l]],w);add2(L[bel[r]],r,w);
    rep(i,bel[l]+1,bel[r]-1) add1(i,w);
}
ll query1(int id){return SS[id];} // K
ll query2(int l,int r){ll ret=0;rep(i,l,r) if (cnt[i]+tag[bel[i]]<=K) (ret+=W[i])%=mod;return ret;}
ll query(int l,int r)
{
    if (bel[r]-bel[l]<=1) return query2(l,r);
    ll ret=0;
    ret=query2(l,R[bel[l]])+query2(L[bel[r]],r);
    rep(i,bel[l]+1,bel[r]-1) (ret+=query1(i))%=mod;
    return ret;
}
void insert(int p,ll w){cnt[p]=-tag[bel[p]];(sum[bel[p]][cnt[p]+n]+=w)%=mod;(SS[bel[p]]+=w)%=mod;}

int dp[sz];

int main()
{
    file();
    read(n,K);
    rep(i,1,n) read(a[i]),pre[i]=lst[a[i]],lst[a[i]]=i;
    init();
    dp[0]=1;insert(1,W[1]=dp[0]);
    rep(i,1,n)
    {
        add(pre[i]+1,i,1);
        add(pre[pre[i]]+1,pre[i],-1);
        dp[i]=query(1,i);
        if (i!=n) insert(i+1,W[i+1]=dp[i]);
    }
    cout<<(dp[n]+mod)%mod;
    return 0; // good bye ~
}