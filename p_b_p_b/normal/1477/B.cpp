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
char s[sz],t[sz];

#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
int tr[sz<<2],tag[sz<<2];
void Tag(int k,int l,int r,int w){tr[k]=(tag[k]=w)*(r-l+1);}
void pushdown(int k,int l,int r){int mid=(l+r)>>1,&t=tag[k]; if (t==-1) return; Tag(lson,t),Tag(rson,t); t=-1; }
void pushup(int k){tr[k]=tr[ls]+tr[rs];}
void build(int k,int l,int r)
{
	tag[k]=-1;
	if (l==r) return tr[k]=t[l]-'0',void();
	int mid=(l+r)>>1;
	build(lson),build(rson); pushup(k);
}
void modify(int k,int l,int r,int x,int y,int w)
{
	if (x<=l&&r<=y) return Tag(k,l,r,w);
	int mid=(l+r)>>1; pushdown(k,l,r); 
	if (x<=mid) modify(lson,x,y,w);
	if (y>mid) modify(rson,x,y,w);
	pushup(k);
}
int query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return tr[k]; 
	int mid=(l+r)>>1,res=0; pushdown(k,l,r);
	if (x<=mid) res+=query(lson,x,y);
	if (y>mid) res+=query(rson,x,y);
	return res;
}

void work()
{
	read(n,Q);
	scanf("%s\n%s",s+1,t+1);
	build(1,1,n);
	static pii q[sz];
	rep(i,1,Q) read(q[i].fir,q[i].sec);
	drep(i,Q,1)
	{
		int l,r; tie(l,r)=q[i];
		int w=query(1,1,n,l,r); if (w*2==(r-l+1)) return puts("NO"),void();
		modify(1,1,n,l,r,(w*2>r-l+1));
	}
	rep(i,1,n) if (query(1,1,n,i,i)!=s[i]-'0') return puts("NO"),void();
	puts("YES");
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	return 0;
}