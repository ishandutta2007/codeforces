//  
#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
	using namespace std;
	#define pll pair<ll,ll>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 505050
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
		#ifdef NTFOrz
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

namespace BIT
{
	int tr[sz];
	void add(int x,int w){++x;x=n-x+2;while (x<=n+1) chkmax(tr[x],w),x+=x&-x;}
	int query(int x){++x;x=n-x+2;int res=-1e9;while (x) chkmax(res,tr[x]),x-=x&-x;return res;}
	void clear(){rep(i,1,n+1) tr[i]=-1e9;}
}

struct hh
{
	int k; ll b; int l,r;
	const int q(ll x) const {x=x*k+b;return max(1ll*l,min(x,1ll*r));}
	const hh operator + (const hh &x) const 
	{
		hh res; res.k=k*x.k,res.b=b*x.k+x.b;
		ll L=x.q(l),R=x.q(r); if (L>R) swap(L,R);
		res.l=L,res.r=R; return res;
	}
};
struct hhh
{
	hh a,b; int tp;
	const hhh operator + (const hhh &x) { return tp?(hhh){a+x.b,b+x.a,x.tp^1}:(hhh){a+x.a,b+x.b,x.tp}; }
	pll q(ll l,ll r){return tp?MP(b.q(r),a.q(l)):MP(a.q(l),b.q(r));}
};
//jmp[sz][23],_[sz];
//void init()
//{
//	rep(i,1,n) jmp[i][0]=(hhh){(hh){-1,a[i],1,a[i]+5},(hh){-1,a[i],0,a[i]-1},1};
//	rep(j,1,20) rep(i,1<<j,n) jmp[i][j]=jmp[i][j-1]+jmp[i-(1<<(j-1))][j-1];
//}
hhh tr[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void pushup(int k){tr[k]=tr[rs]+tr[ls];}
void build(int k,int l,int r)
{
	if (l==r) return tr[k]=(hhh){(hh){-1,a[l],0,a[l]-1},(hh){-1,a[l],1,a[l]},1},void();
	int mid=(l+r)>>1;
	build(lson),build(rson),pushup(k);
}
int query(int k,int l,int r,int x,ll &L,ll &R)
{
	if (r<=x)
	{
		pll xx=tr[k].q(L,R);
		if (xx.fir<=xx.sec) return tie(L,R)=xx,l;
		if (l==r) return L=R=-1,l+1;
		int mid=(l+r)>>1;
		int res=query(rson,x,L,R);
		return L==-1?res:query(lson,x,L,R);
	}
	int mid=(l+r)>>1;
	if (x<=mid) return query(lson,x,L,R);
	int res=query(rson,x,L,R); return L==-1?res:query(lson,x,L,R);
}

int qL(int x,ll l,ll r)
{
	return query(1,1,n,x,l,r);
//	--x; int c=0;
//	drep(i,20,0) if (x>=(1<<i))
//	{
//		pll p=jmp[x][i].q(l,r);
//		if (p.fir<=p.sec) c+=1<<i,x-=(1<<i),tie(l,r)=p;
//	}
//	return c;
//	drep(i,x-1,1)
//	{
//		ll L=a[i]-r,R=a[i]-l; chkmax(L,1ll),chkmin(R,a[i]-1);
//		if (L>R) return i+1;
//		l=L,r=R;
//	}
//	return 1;
}

int dp[sz];

namespace Q2
{
	ll dB; int tp;
	map<ll,int>w;
	multiset<int>s;
	void clear(){dB=0,tp=1;w.clear(),s.clear();}
	void insert(ll B,int W)
	{
		B=(B-dB)*tp;
		if (w.find(B)==w.end()) w[B]=W,s.insert(W);
		else if (w[B]<W) s.erase(s.find(w[B])),s.insert(W),w[B]=W;
	}
	void maintain(ll a)
	{
		tp*=-1,dB=a-dB;
		for (auto it=w.begin();it!=w.end();)
		{
			ll b=it->fir*tp+dB;
			if (b<1||b>=a) s.erase(s.find(it->sec)),w.erase(it++);
			else break;
		}
		int c=0;
		for (auto it=w.rbegin();it!=w.rend();)
		{
			ll b=it->fir*tp+dB;
			if (b<1||b>=a) s.erase(s.find(it->sec)),it++,c++;
			else break;
		}
		while (c--) w.erase(prev(w.end()));
	}
	void add(ll B) { B=(B-dB)*tp; auto it=w.find(B); if (it==w.end()) return; s.erase(s.find(it->sec)),s.insert(it->sec+1); ++w[B]; }
	int mx(){return s.size()?*(s.rbegin()):-1e9;}
}

void work()
{
	read(n);
	rep(i,1,n) read(a[i]);
	BIT::clear(); Q2::clear();
	BIT::add(0,0);
	build(1,1,n);
	rep(i,1,n)
	{
		int p=qL(i,1,a[i]-1); dp[i]=BIT::query(p-1)+i-1;
		Q2::maintain(a[i]);
		if (a[i]%2==0) Q2::add(a[i]/2);
		chkmax(dp[i],Q2::mx()+i-1);
		if (a[i]%2==0)
		{
			p=qL(i,a[i]/2,a[i]/2);
			int w=BIT::query(p-1)+1;
			chkmax(dp[i],w+i-1); Q2::insert(a[i]/2,w);
		}
		BIT::add(i,dp[i]-i);
	}
	print(n+n-dp[n]);
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	Ot();
	return 0;
}