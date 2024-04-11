#include<bits/stdc++.h>
//clock_t t=clock();
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
	#define sz 101010
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
//	inline void chktime()
//	{
//		#ifndef ONLINE_JUDGE
//		cout<<(clock()-t)/1000.0<<'\n';
//		#endif
//	}
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
int a[sz];

int tr[sz<<2],tag[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void Add(int k,int w){tag[k]+=w;tr[k]+=w;}
void pushdown(int k){Add(ls,tag[k]);Add(rs,tag[k]);tag[k]=0;}
void pushup(int k){tr[k]=min(tr[ls],tr[rs]);}
void modify(int k,int l,int r,int x,int y,int w)
{
	if (x<=l&&r<=y) return Add(k,w);
	int mid=(l+r)>>1;
	pushdown(k);
	if (x<=mid) modify(lson,x,y,w);
	if (y>mid) modify(rson,x,y,w);
	pushup(k);
}
void build(int k,int l,int r)
{
	if (l==r) return void(tr[k]=a[l]);
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(k);
}

pii A[sz];
vector<pii>s[sz],t[sz];

bool vis[sz];
int cnt;

int main()
{
	file();
	read(n,m);
	rep(i,1,n) read(a[i]);
	build(1,1,n);
	rep(i,1,m) 
		read(A[i].fir,A[i].sec),
		modify(1,1,n,A[i].fir,A[i].sec,-1),
		s[A[i].fir].push_back(A[i]),t[A[i].sec].push_back(A[i]);
	int mx=-1;
	rep(i,1,n)
	{
		for (auto x:s[i]) modify(1,1,n,i,x.sec,1);
		if (chkmax(mx,a[i]-tr[1])) 
		{
			cnt=0;rep(j,1,m) vis[j]=0;
			rep(j,1,m) if (A[j].fir>i||A[j].sec<i) vis[j]=1,++cnt;
		}
		for (auto x:t[i]) modify(1,1,n,x.fir,i,-1);
	}
	printf("%d\n%d\n",mx,cnt);
	rep(i,1,m) if (vis[i]) printf("%d ",i);
	return 0;
}