#include<bits/stdc++.h>
clock_t __t=clock();
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
	#define sz 202002
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
	inline void print(int x)
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
		#ifdef NTFOrz
		cout<<(clock()-__t)/1000.0<<'\n';
		#endif
	}
	#ifdef mod
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
	ll inv(ll x){return ksm(x,mod-2);}
	#else
	ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
	#endif
//	ll mul(ll x,ll y){ull s=1.0*x/mod*y;ll res=1ull*x*y-s*mod;return (res%mod+mod)%mod;}
}
using namespace my_std;

int n,Q;
int a[sz];
struct hh{int v,l,r;const bool operator < (const hh &x) const {return v>x.v;}hh(int V=0,int L=0,int R=0){v=V,l=L,r=R;}};
set<hh>s;

#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
ll tr[sz<<2],tag[sz<<2];
void Tag(int k,int l,int r,ll w){tr[k]+=w*(r-l+1);tag[k]+=w;}
void pushdown(int k,int l,int r){ll &w=tag[k];int mid=(l+r)>>1;Tag(lson,w),Tag(rson,w);w=0;}
void pushup(int k){tr[k]=tr[ls]+tr[rs];}
void add(int k,int l,int r,int x,int y,ll w)
{
	if (x<=l&&r<=y) return Tag(k,l,r,w);
	int mid=(l+r)>>1; pushdown(k,l,r);
	if (x<=mid) add(lson,x,y,w);
	if (y>mid) add(rson,x,y,w);
	pushup(k);
}
ll query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return tr[k];
	int mid=(l+r)>>1; ll res=0; pushdown(k,l,r);
	if (x<=mid) res+=query(lson,x,y); if (y>mid) res+=query(rson,x,y);
	return res;
}
int qq(int k,int l,int r,ll w)
{
	if (l==r) return l;
	int mid=(l+r)>>1; pushdown(k,l,r);
	if (w<tr[ls]) return qq(lson,w);
	return qq(rson,w-tr[ls]);
}

void work1(int x,int y)
{
	int R=x,ww=query(1,1,n,x,x); if (ww>=y) return;
	int L;
	auto it1=s.lower_bound(hh(y,0,0));L=it1->l;
	auto it2=s.upper_bound(hh(ww,0,0)); --it2;
	while (it1!=it2) add(1,1,n,it1->l,it1->r,y-it1->v),s.erase(it1++);
	hh w=*it2; s.erase(it2);
	add(1,1,n,w.l,x,y-w.v); s.insert(hh(y,L,R)); if (R!=w.r) s.insert(hh(w.v,R+1,w.r));
}
int work2(int x,int y)
{
	int res=0;
	while (233)
	{
		auto it=s.lower_bound(hh(y,0,0)); if (it==s.end()) return res;
		chkmax(x,it->l);
		if (y>=query(1,1,n,x,n)) return n-x+1+res;
		ll w=(x==1?0:query(1,1,n,1,x-1));
		int p=qq(1,1,n,w+y); ll ww=query(1,1,n,x,p-1);
		res+=p-x,x=p,y-=ww;
	}
}

int main()
{
	file();
	read(n,Q);
	rep(i,1,n) read(a[i]);
	for (int l=1,r;l<=n;l=r+1)
	{
		for (r=l;r!=n&&a[r+1]==a[l];++r);
		s.insert(hh(a[l],l,r)); add(1,1,n,l,r,a[l]);
	}
	while (Q--)
	{
		int tp,x,y; read(tp,x,y);
		if (tp==1) work1(x,y);
		else printf("%d\n",work2(x,y));
	}
	return 0;
}