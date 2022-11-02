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
    #define sz 1010010
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
        #ifdef NTFOrz
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
int a[sz],b[sz];
#define MX 1000000

int tag[sz<<2],tr[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void add(int k,int w){tr[k]+=w;tag[k]+=w;}
void pushdown(int k){add(ls,tag[k]);add(rs,tag[k]);tag[k]=0;}
void pushup(int k){tr[k]=max(tr[ls],tr[rs]);}
void add(int k,int l,int r,int x,int y,int w)
{
	if (x<=l&&r<=y) return add(k,w);
	int mid=(l+r)>>1;
	pushdown(k);
	if (x<=mid) add(lson,x,y,w);
	if (y>mid) add(rson,x,y,w);
	pushup(k);
}
void Add(int a,int w){add(1,1,MX,1,a,w);}
int query(int k,int l,int r)
{
	if (tr[k]<=0) return -1;
	if (l==r) return l;
	pushdown(k);
	int mid=(l+r)>>1;
	if (tr[rs]>0) return query(rson);
	return query(lson);
}

int main()
{
    file();
	read(n,m);
	rep(i,1,n) read(a[i]),Add(a[i],1);
	rep(i,1,m) read(b[i]),Add(b[i],-1);
	int Q,x,y,z;read(Q);
	while (Q--)
	{
		read(z,x,y);
		if (z==1) Add(a[x],-1),Add(a[x]=y,1);
		else Add(b[x],1),Add(b[x]=y,-1);
		printf("%d\n",query(1,1,MX));
	}
	return 0;
}