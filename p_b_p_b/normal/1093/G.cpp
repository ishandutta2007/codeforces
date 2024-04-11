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
    #define S 35
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

int n,K,KK,Q;
int a[S];

int mx[sz<<2][S];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r

void pushup(int k){rep(i,0,KK) mx[k][i]=max(mx[ls][i],mx[rs][i]);}
void modify(int k,int l,int r,int pos)
{
    if (l==r)
    {
        rep(i,0,K-1) read(a[i]);
        rep(i,0,KK) mx[k][i]=0;
        rep(i,0,KK) 
            rep(j,0,K-1) 
                mx[k][i]+=(((i>>j)&1)?-a[j]:a[j]);
        return;
    }
    int mid=(l+r)>>1;
    if (pos<=mid) modify(lson,pos);
    else modify(rson,pos);
    pushup(k);
}
int ans[S];
void query(int k,int l,int r,int x,int y)
{
    if (x<=l&&r<=y)
    {
        rep(i,0,KK) chkmax(ans[i],mx[k][i]);
        return;
    }
    int mid=(l+r)>>1;
    if (x<=mid) query(lson,x,y);
    if (y>mid) query(rson,x,y);
}
int query(int l,int r)
{
    rep(i,0,KK) ans[i]=INT_MIN;
    int ret=0;
    query(1,1,n,l,r);
    rep(i,0,KK) chkmax(ret,ans[i]+ans[KK-i]);
    return ret;
}

int main()
{
    file();
    read(n,K);KK=(1<<K)-1;
    rep(i,1,n) modify(1,1,n,i);
    read(Q);
    int x,y,z;
    while (Q--)
    {
        read(z);
        if (z==1) read(x),modify(1,1,n,x);
        else read(x,y),printf("%d\n",query(x,y));
    }
    return 0;
}