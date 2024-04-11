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
	#define sz 20202
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

int n,K;
int a[sz];

int ST[sz][25],lg2[sz];
#define cmp(x,y) (a[x]>a[y]?x:y)
void init()
{
	rep(i,1,n) ST[i][0]=i;
	rep(j,1,20) rep(i,1,n-(1<<j)+1) ST[i][j]=cmp(ST[i][j-1],ST[i+(1<<(j-1))][j-1]);
	rep(i,2,n) lg2[i]=lg2[i>>1]+1;
}
int qmax(int l,int r){int len=lg2[r-l+1];return cmp(ST[l][len],ST[r-(1<<len)+1][len]);}
#undef cmp

struct Line{ll k,b;Line(ll K=0,ll B=0){k=K,b=B;}};
namespace SegmentTree
{
	Line tr[sz<<2];
	int vis[sz<<2];
	#define ls k<<1
	#define rs k<<1|1
	#define lson ls,l,mid
	#define rson rs,mid+1,r
	void build(int k,int l,int r)
	{
		vis[k]=0;tr[k]=Line(0,0);
		if (l==r) return;
		int mid=(l+r)>>1;
		build(lson);build(rson);
	}
	void pushdown(int k,int l,int r,Line s)
	{
		if (!vis[k]) return (void)(vis[k]=1,tr[k]=s);
		ll l1=s.k*l+s.b,r1=s.k*r+s.b;
		ll l2=tr[k].k*l+tr[k].b,r2=tr[k].k*r+tr[k].b;
		if (l1<=l2&&r1<=r2) return (void)(tr[k]=s);
		if (l1>=l2&&r1>=r2) return;
		db pos=(s.b-tr[k].b)/(tr[k].k-s.k);
		int mid=(l+r)>>1;
		if (pos<=mid) pushdown(lson,r1<r2?tr[k]:s);
		else pushdown(rson,l1<l2?tr[k]:s);
		if ((pos<=mid&&r1<r2)||(pos>mid&&l1<l2)) tr[k]=s;
	}
	void insert(int k,int l,int r,int x,int y,Line s)
	{
		if (x<=l&&r<=y) return pushdown(k,l,r,s);
		int mid=(l+r)>>1;
		if (x<=mid) insert(lson,x,y,s);
		if (y>mid) insert(rson,x,y,s);
	}
	ll query(int k,int l,int r,int x)
	{
		ll ret=tr[k].k*x+tr[k].b;
		if (!vis[k]) ret=1e18;
		if (l==r) return ret;
		int mid=(l+r)>>1;
		if (x<=mid) chkmin(ret,query(lson,x));
		else chkmin(ret,query(rson,x));
		return ret;
	}
}
using SegmentTree::build;using SegmentTree::insert;using SegmentTree::query;

struct Point{ll x,y;Point(ll X=0,ll Y=0){x=X,y=Y;}};
db calcK(Point a,Point b){return 1.0*(b.y-a.y)/(b.x-a.x);}
#define Convex deque<Point>
Convex empty;
Convex tmp[sz];
int st[sz],top;
Line query(int id,ll k)
{
	if (!tmp[id].size()) return Line(0,1e9);
	while (tmp[id].size()>1&&calcK(tmp[id][0],tmp[id][1])<=k) tmp[id].pop_front();
	return Line(k,tmp[id][0].y-k*tmp[id][0].x);
}
void insertfrnt(int id,Point a)
{
	while (tmp[id].size()>1)
	{
		Point x=tmp[id][0],y=tmp[id][1];
		if (calcK(a,y)>=calcK(x,y)) tmp[id].pop_front();
		else break;
	}
	tmp[id].push_front(a);
}
void insertback(int id,Point a)
{
	while (tmp[id].size()>1)
	{
		int n=tmp[id].size();
		Point x=tmp[id][n-2],y=tmp[id][n-1];
		if (calcK(a,x)<=calcK(x,y)) tmp[id].pop_back();
		else break;
	}
	tmp[id].push_back(a);
}
ll dp[111][sz];
int cur;
int solve(int l,int r)
{
	if (l>r) return 0;
	if (l==r) { int id=st[top--]; tmp[id].push_back(Point(l,dp[cur-1][l])); return id; }
	int pos=qmax(l+1,r);
	int L=solve(l,pos-1);
	Line s=query(L,a[pos]);
	insert(1,1,n,pos,r,s);
	if (!L) L=st[top--];
	dp[cur][pos]=query(1,1,n,pos);
	int R=solve(pos,r);
	if (tmp[L].size()>=tmp[R].size())
	{
		while (tmp[R].size()) insertback(L,tmp[R][0]),tmp[R].pop_front();
		st[++top]=R;
		return L;
	}
	else 
	{
		while (tmp[L].size()) insertfrnt(R,tmp[L][(int)tmp[L].size()-1]),tmp[L].pop_back();
		st[++top]=L;
		return R;
	}
}

int main()
{
	file();
	read(n,K);
	rep(i,1,n) st[i]=i;top=n;
	rep(i,1,n) read(a[i]);
	init();
	rep(i,1,n) dp[1][i]=1ll*i*a[qmax(1,i)];
	cur=2;
	while (cur<=K) build(1,1,n),solve(cur-1,n),++cur;
	cout<<dp[K][n];
	return 0;
}
// NTF tql ddw