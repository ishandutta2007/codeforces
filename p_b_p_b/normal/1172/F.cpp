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
    #define sz 1110002
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

int n;ll P;
ll a[sz];

struct hh{ll l,b;}; // x \in [l,r], y=x+b

typedef vector<hh> func;
func tr[sz<<1];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
ll calc(const func &V,ll x)
{
	int l=0,r=(int)V.size()-1,pos=0;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (x>=V[mid].l) pos=mid,l=mid+1;
		else r=mid-1;
	}
	return x+V[pos].b;
}
func merge(func A,const func &B)
{
	int p=0;
	func ret;
    int aa=A.size(),bb=B.size();
	#define add(L,BB) ((ret.empty()||ret.back().b!=BB)?ret.push_back((hh){L,BB}),0:0)
	for (int i=0;i<=(int)A.size()-1;)
	{
		ll yl=A[i].l+A[i].b,yr;
		if (A[i].l==-1e17) yl=-1e17; 
		if (i==aa-1) yr=1e17; else yr=A[i+1].l-1+A[i].b;
		while (p&&B[p].l>yl) --p;
		while (p<bb-1&&B[p+1].l-1<yl) ++p;
		ll r;
		if (p==bb-1) r=1e17; else r=B[p+1].l-1;
		if (r<yr) add(A[i].l,A[i].b+B[p].b),A[i].l=r-A[i].b+1;
		else add(A[i].l,A[i].b+B[p].b),++i;
	}
	return ret;
	#undef add
}
void build(int k,int l,int r)
{
	if (l==r) { tr[k].push_back((hh){-(ll)1e17,a[l]}),tr[k].push_back((hh){P-a[l],a[l]-P}); return; }
	int mid=(l+r)>>1;
	build(lson),build(rson);
	tr[k]=merge(tr[ls],tr[rs]);
}
ll query(int k,int l,int r,int x,int y,ll w)
{
	if (x<=l&&r<=y) return calc(tr[k],w);
	int mid=(l+r)>>1;
	if (x<=mid) w=query(lson,x,y,w);
	if (y>mid) w=query(rson,x,y,w);
	return w;
}

int main()
{
    file();
    int Q;
	read(n,Q,P);
	rep(i,1,n) read(a[i]);
	build(1,1,n);
	int l,r;
	while (Q--) read(l,r),printf("%I64d\n",(long long)query(1,1,n,l,r,0));
	return 0;
}