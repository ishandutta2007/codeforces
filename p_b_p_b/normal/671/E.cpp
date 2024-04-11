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
	#define sz 301001
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
		cout<<(clock()-__t)/1000.0<<'\n';
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

int n;ll K;
ll w[sz],g[sz];

ll pre[sz],suf[sz];
int nxt[sz];ll dt[sz];
struct hh{int t,nxt;}edge[sz<<1];
vector<int>V[sz];
//int head[sz],ecnt;
//void make_edge(int f,int t)
//{
//	edge[++ecnt]=(hh){t,head[f]};
//	head[f]=ecnt;
//}
//#define v edge[i].t

ll tag1[sz<<2],tag2[sz<<2]; // suf,cost
ll mn3[sz<<2]; // mn_suf
ll mn2[sz<<2]; // mn_{cost+suf}
ll mx2[sz<<2]; // mx_cost
ll R[sz<<2]; // ans of rs
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
inline void Tag1(int k,ll w){mn3[k]+=w,mn2[k]+=w,tag1[k]+=w;}
inline void Tag2(int k,ll w){mn2[k]+=w,mx2[k]+=w,R[k]+=w,tag2[k]+=w;}
inline void pushdown(int k){ll &t1=tag1[k],&t2=tag2[k];if (t1) Tag1(ls,t1),Tag1(rs,t1);if (t2) Tag2(ls,t2),Tag2(rs,t2);t1=t2=0;}
ll query(int k,int l,int r,ll w)
{
	if (l==r) return mn2[k]-w;
	pushdown(k);
	int mid=(l+r)>>1;ll ret=1e18;
	if (w<=mn3[ls]) ret=mn2[ls]-w,chkmin(ret,query(rson,w));
	else ret=R[k],chkmin(ret,query(lson,w));
	return ret;
}
inline void pushup(int k,int l,int r)
{
	mn3[k]=min(mn3[ls],mn3[rs]);
	mn2[k]=min(mn2[ls],mn2[rs]);
	mx2[k]=max(mx2[ls],mx2[rs]);
	int mid=(l+r)>>1;
	R[k]=query(rson,mn3[ls]);
}
void modify1(int k,int l,int r,int x,int y,ll w)
{
	if (x>y) return;
	if (x<=l&&r<=y) return Tag1(k,w);
	pushdown(k);
	int mid=(l+r)>>1;
	if (x<=mid) modify1(lson,x,y,w);
	if (y>mid) modify1(rson,x,y,w);
	pushup(k,l,r);
}
void modify2(int k,int l,int r,int x,int y,ll w)
{
	if (x>y) return;
	if (x<=l&&r<=y) return Tag2(k,w);
	pushdown(k);
	int mid=(l+r)>>1;
	if (x<=mid) modify2(lson,x,y,w);
	if (y>mid) modify2(rson,x,y,w);
	pushup(k,l,r);
}
int Query(int k,int l,int r,ll w)
{
	if (l==r) return (mn2[k]-w<=K)?l:-1;
	pushdown(k);
	int mid=(l+r)>>1;ll rr=query(rson,min(w,mn3[ls]));
	if (rr<=K) return Query(rson,min(w,mn3[ls]));
	return Query(lson,w);
}
void build(int k,int l,int r)
{
	if (l==r) return mn2[k]=mn3[k]=suf[l],void();
	int mid=(l+r)>>1;
	build(lson),build(rson);
	pushup(k,l,r);
}
int qq(int k,int l,int r)
{
	if (l==r) return l;
	pushdown(k);
	int mid=(l+r)>>1;
	if (mx2[ls]>K) return qq(lson); return qq(rson);
}
void debug(int k,int l,int r)
{
	if (l==r) return printf("%lld %lld\n",mn3[k],mx2[k]),void();
	pushdown(k);
	int mid=(l+r)>>1;
	debug(lson),debug(rson);
}

int ans;
void dfs(int x)
{
	if (nxt[x]!=n+1) modify2(1,1,n,nxt[x]-1,n,dt[x]),modify1(1,1,n,1,nxt[x]-2,dt[x]);
//	int l=x+1,r=n,pos=x;
//	while (l<=r)
//	{
//		int mid=(l+r)>>1;
//		if (qq(1,1,n,mid-1)<=K) pos=mid,l=mid+1;
//		else r=mid-1;
//	}
	int pos=qq(1,1,n);
	modify1(1,1,n,1,x-1,1e16);
	modify2(1,1,n,pos+1,n,1e17);
	chkmax(ans,Query(1,1,n,1e17)-x+1);
//	if (ans==8) cout<<x<<'\n';
	modify1(1,1,n,1,x-1,-1e16);
	modify2(1,1,n,pos+1,n,-1e17);
	for (auto v:V[x]) dfs(v);
//	go(x) dfs(v);
	if (nxt[x]!=n+1) modify2(1,1,n,nxt[x]-1,n,-dt[x]),modify1(1,1,n,1,nxt[x]-2,-dt[x]);
}

int main()
{
	file();
	read(n,K);
	rep(i,1,n-1) read(w[i]);
	rep(i,1,n) read(g[i]);
	rep(i,1,n-1) pre[i]=pre[i-1]+g[i]-w[i];pre[n]=-1e18;
	stack<int>st;st.push(n+1);
	drep(i,n,1)
	{
		while (pre[st.top()-1]>=pre[i-1]) st.pop();
		nxt[i]=st.top(); dt[i]=pre[i-1]-pre[st.top()-1]; st.push(i);
		V[nxt[i]].push_back(i);	
//		make_edge(nxt[i],i);
	}
	drep(i,n,2) suf[i]=suf[i+1]+g[i]-w[i-1];
	rep(i,1,n) suf[i]=suf[i+1];
	build(1,1,n);
	for (auto x:V[n+1]) dfs(x);
//	go(n+1) dfs(v);
	chktime();
	cout<<ans;
	return 0;
}