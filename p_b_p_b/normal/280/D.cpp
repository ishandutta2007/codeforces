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
    #define sz 101001
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

int n;
int a[sz];

struct hh
{
    int lmx,lmxid,lmn,lmnid;
    int rmx,rmxid,rmn,rmnid;
    int midmx,Lmx,Rmx;
    int midmn,Lmn,Rmn;
    int sum;
};
inline const hh operator + (const hh &a,const hh &b)
{
    hh ret;
    ret=(hh)
    {
        a.lmx,a.lmxid,a.lmn,a.lmnid ,
        b.rmx,b.rmxid,b.rmn,b.rmnid , 
        a.rmx+b.lmx,a.rmxid,b.lmxid ,
        a.rmn+b.lmn,a.rmnid,b.lmnid ,
        a.sum+b.sum
    };
    if (chkmax(ret.lmx,a.sum+b.lmx)) ret.lmxid=b.lmxid;
    if (chkmin(ret.lmn,a.sum+b.lmn)) ret.lmnid=b.lmnid;
    if (chkmax(ret.rmx,b.sum+a.rmx)) ret.rmxid=a.rmxid;
    if (chkmin(ret.rmn,b.sum+a.rmn)) ret.rmnid=a.rmnid;
    if (chkmax(ret.midmx,a.midmx)) ret.Lmx=a.Lmx,ret.Rmx=a.Rmx;
    if (chkmax(ret.midmx,b.midmx)) ret.Lmx=b.Lmx,ret.Rmx=b.Rmx;
    if (chkmin(ret.midmn,a.midmn)) ret.Lmn=a.Lmn,ret.Rmn=a.Rmn;
    if (chkmin(ret.midmn,b.midmn)) ret.Lmn=b.Lmn,ret.Rmn=b.Rmn;
    return ret;
}

hh tr[sz<<2];
int tag[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void pushup(int k){tr[k]=tr[ls]+tr[rs];}
void R(int &x){x=-x;}
void Rev(hh &a)
{
    swap(a.lmx,a.lmn),swap(a.rmx,a.rmn);
    R(a.lmx);R(a.lmn);R(a.rmx);R(a.rmn);
    swap(a.lmxid,a.lmnid);swap(a.rmxid,a.rmnid);
    swap(a.midmx,a.midmn);
    R(a.midmx);R(a.midmn);swap(a.Lmx,a.Lmn);swap(a.Rmx,a.Rmn);
    R(a.sum);
}
void pushdown(int k){if (tag[k]) tag[ls]^=1,tag[rs]^=1,Rev(tr[ls]),Rev(tr[rs]);tag[k]=0;}
void Set(hh &a,int p,int w){a=(hh){w,p,w,p,w,p,w,p,w,p,p,w,p,p,w};}
void modify(int k,int l,int r,int x,int w)
{
    if (l==r) return Set(tr[k],l,w);
    pushdown(k);
    int mid=(l+r)>>1;
    if (x<=mid) modify(lson,x,w);
    else modify(rson,x,w);
    pushup(k);
}
void reverse(int k,int l,int r,int x,int y)
{
    if (x<=l&&r<=y) return tag[k]^=1,Rev(tr[k]);
    int mid=(l+r)>>1;
    pushdown(k);
    if (x<=mid) reverse(lson,x,y);
    if (y>mid) reverse(rson,x,y);
    pushup(k);
}
hh query(int k,int l,int r,int x,int y)
{
    if (x<=l&&r<=y) return tr[k];
    pushdown(k);
    int mid=(l+r)>>1;
    if (y<=mid) return query(lson,x,y);
    if (x>mid) return query(rson,x,y);
    return query(lson,x,y)+query(rson,x,y);
}

hh q[sz];

int main()
{
    file();
    read(n);
    rep(i,1,n) read(a[i]),modify(1,1,n,i,a[i]);
    int Q;
    read(Q);
    while (Q--)
    {
        int z,x,y;
        read(z,x,y);
        if (z==0) modify(1,1,n,x,y);
        else
        {
            read(z);
            int ans=0,pos=z;
            rep(i,1,z)
            {
                q[i]=query(1,1,n,x,y);
                if (q[i].midmx<=0){pos=i-1;break;}
                ans+=q[i].midmx;
                reverse(1,1,n,q[i].Lmx,q[i].Rmx);
            }
            rep(i,1,pos) reverse(1,1,n,q[i].Lmx,q[i].Rmx);
            printf("%d\n",ans);
        }
    }
    return 0;
}