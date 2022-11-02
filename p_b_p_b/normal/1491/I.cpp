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
	#define sz 16666
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
int p[sz]; // p[i]: i  
struct hh{int a[3];}w[sz];
int cur,str; ll tot;
void Run()
{
	int nxt=(cur+1)%n;
	if (w[p[cur]].a[str]>w[p[nxt]].a[0]) ++str,swap(p[cur],p[nxt]),cur=nxt;
	else str=1,cur=nxt;
	++tot;
	if (str==3) exit(printf("%d %lld\n",p[cur],tot)&0);
}

int main()
{
	file();
	read(n);
	rep(i,0,n-1) p[i]=i;
	rep(i,0,n-1) rep(j,0,2) read(w[i].a[j]);
	rep(i,1,5) Run(); if (str==2) Run();
	static int vis[sz],pre[sz];
	static pii st[sz]; int tp,cnt;
	auto GO=[&](int tp){int t=n*n*2;while (t--) Run();cout<<tp<<'\n';assert(0);exit(0);};
	auto work=[&]()
	{
		rep(i,0,n-1) p[i+n]=p[i];
		rep(i,0,n*2-1) vis[i]=0;
		int lst=cur; rep(i,cur+1,cur+n-1) if (w[p[i]].a[0]<w[p[lst]].a[1]) vis[i%n]=1; else lst=i;
		rep(i,0,n-1) vis[i]=vis[i+n]=vis[i]|vis[i+n];
//		rep(i,0,n+2) if (w[p[i]].a[1]>w[p[i+1]].a[0]) vis[i+1]=1; vis[0]=vis[n];
		rep(i,0,n-1) if (vis[i]&&vis[i+1]) GO(1);
		rep(i,0,n-1) if (!vis[i]) { int j=i+1; if (!vis[j]) continue; j++; if (w[p[i]].a[2]>w[p[j]].a[0]) GO(2); }
		tp=0,cnt=-1;
		rep(i,0,n+n-1) if (vis[i])
		{
			int k=lower_bound(st+1,st+tp+1,MP(w[p[i]].a[0],0))-st-1;
			if (!k) pre[i]=-1; else pre[i]=st[k].sec;
		} 
		else { ++cnt; while (tp&&st[tp].fir>w[p[i]].a[1]) --tp; st[++tp]=MP(w[p[i]].a[1],cnt); }
	};
	while (233)
	{
		work();
		static int sta[sz],m,nxt[sz]; //  
		static int id[sz]; //  
		for (int cc=-1,i=0;i<n+n;i++) { if (!vis[i]) ++cc; id[i]=cc; }
		m=0; rep(i,0,n-1) if (!vis[i]) sta[m]=i,nxt[m]=(vis[i+1]?(i+1)%n:-1),++m;
		if (m==n) return puts("-1 -1"),0;
		int curr=id[cur];
		if (w[p[cur]].a[0]<w[p[sta[(curr-1+m)%m]]].a[1]) GO(3); // 1
		int mn=1e9; rep(i,0,n-1) if (vis[i]&&pre[i+n]!=-1) chkmin(mn,(id[i]-pre[i+n]%m+m)%m);
		int mnn=1e9,nxx=1e9;
		drep(i,n+n-2,0) if (!vis[i]) // 2.1
		{
			int j=i+1; if (vis[j]) ++j; if (j>=n+n) continue;
			if (w[p[i]].a[2]>w[p[j]].a[0]) chkmin(mnn,nxx-id[i]);
		} else nxx=id[i];
		if (mn>n) { int t=2*n*n; while (t--) Run(); break; }
		if (mnn<mn) GO(4);
		auto RESET=[&](int t)
		{
			int nn=0; static int pp[sz];
			int real=-1;
			rep(i,0,m-1) { pp[nn++]=p[sta[i]]; if (sta[i]==cur) real=nn-1; if (nxt[(i+t)%m]!=-1) pp[nn++]=p[nxt[(i+t)%m]]; }
			assert(real!=-1);
			cur=real,str=1; rep(i,0,n-1) p[i]=p[i+n]=pp[i];
		};
		rep(t,0,mn-1)
		{
			if (nxt[(curr+t)%m]!=-1)
			{
				assert(w[p[sta[curr]]].a[1]>w[p[nxt[(curr+t)%m]]].a[0]);
				assert(w[p[sta[curr]]].a[2]<w[p[sta[(curr+1)%m]]].a[0]);
				int t1=nxt[(curr+t)%m],t2=nxt[(curr+t-1+m)%m];
				if (t2!=-1&&w[p[t1]].a[0]<w[p[t2]].a[1]) RESET(t),GO(6);
			}
			tot+=n-1; curr=(curr-1+m)%m;
			cur=sta[curr];
		}
		RESET(mn);
	}
	puts("-1 -1");
	return 0;
}