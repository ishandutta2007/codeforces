#include<bits/stdc++.h>
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
	#define sz 300303
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
		cerr<<clock()/1000.0<<'\n';
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
int p[sz];
ll b[sz];

pii st[sz][23];
int lg2[sz];
void init()
{
	rep(i,1,n) st[i][0]=MP(p[i],i);
	rep(j,1,20) rep(i,1,n-(1<<j)+1) st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	rep(i,2,n) lg2[i]=lg2[i>>1]+1;
}
pii query(int l,int r){int len=lg2[r-l+1];return min(st[l][len],st[r-(1<<len)+1][len]);}

ll tr[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
ll query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return tr[k];
	int mid=(l+r)>>1; ll res=-1e18;
	if (x<=mid) chkmax(res,query(lson,x,y));
	if (y>mid) chkmax(res,query(rson,x,y));
	return res;
}
void modify(int k,int l,int r,int x,ll w)
{
	if (l==r) return tr[k]=w,void();
	int mid=(l+r)>>1;
	if (x<=mid) modify(lson,x,w);
	else modify(rson,x,w);
	tr[k]=max(tr[ls],tr[rs]);
}

ll dp[sz];
void work(int l,int r,ll w)
{
	if (l>r) return;
	pii p=query(l,r);
	work(l,p.sec-1,w);
	int x=p.sec;
	chkmax(w,b[x]+query(1,0,n,l-1,x-1)); dp[x]=w; modify(1,0,n,x,w);
//	chkmax(w,pre[p.sec-1]+b[p.sec]); dp[p.sec]=w,pre[p.sec]=max(pre[p.sec-1],dp[p.sec]);
	work(p.sec+1,r,w);
}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(p[i]);
	rep(i,1,n) read(b[i]);
	init();
	memset(tr,~0x3f,sizeof(tr)); modify(1,0,n,0,0);
	work(1,n,-1e18);
	cout<<dp[n];
	return 0;
}