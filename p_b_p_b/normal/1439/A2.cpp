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
	#define sz 233
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

int n,m;
int a[sz][sz];

struct hh{int x,y,a,b,c,d;hh(int X=0,int Y=0,int A=0,int B=0,int C=0,int D=0){x=X,y=Y,a=A,b=B,c=C,d=D;}}; vector<hh>ans;

void work()
{
	auto mdf=[&](int x,int y,int t,int b,int c,int d){a[x][y]^=1,a[t][b]^=1,a[c][d]^=1;ans.push_back(hh(x,y,t,b,c,d));};
	#define GG printf("%d\n",(int)ans.size()); for (auto x:ans) printf("%d %d %d %d %d %d\n",x.x+1,x.y+1,x.a+1,x.b+1,x.c+1,x.d+1); assert((int)ans.size()<=n*m); rep(i,0,n-1) rep(j,0,m-1) assert(!a[i][j]); return
	read(n,m);
	static char _[sz];
	rep(i,0,n-1) { cin>>_; rep(j,0,m-1) a[i][j]=_[j]-'0'; }
	ans.clear();
	drep(i,n-1,2) rep(j,0,m-1) if (a[i][j]) { if (j==0) mdf(i,j,i-1,j,i-1,j+1); else mdf(i,j,i-1,j,i-1,j-1); }
	drep(j,m-1,2) rep(i,0,1) if (a[i][j]) mdf(i,j,0,j-1,1,j-1);
	int c=0; rep(i,0,1) rep(j,0,1) c+=a[i][j];
	if (c==0) {GG;}
	if (c==3) { rep(i,0,1) rep(j,0,1) if (!a[i][j]) { mdf(i,j^1,i^1,j,i^1,j^1); GG; } }
	if (c==1) { rep(i,0,1) rep(j,0,1) if (a[i][j]) { mdf(i,j,i,j^1,i^1,j^1); mdf(i,j,i^1,j,i^1,j^1); mdf(i,j,i^1,j,i,j^1); GG; } }
	if (c==4)
	{
		mdf(0,0,0,1,1,0);
		rep(i,0,1) rep(j,0,1) if (a[i][j]) 
		{ mdf(i,j,i,j^1,i^1,j^1); mdf(i,j,i^1,j,i^1,j^1); mdf(i,j,i^1,j,i,j^1); GG; }
	}
	int p=0,q=0; rep(i,0,1) rep(j,0,1) if (a[i][j]) p=i,q=j;
	if (a[p^1][q^1]) { mdf(p,q,p^1,q,p,q^1); mdf(p^1,q,p,q^1,p^1,q^1); GG; }
	if (a[p^1][q]) { mdf(p,q,p,q^1,p^1,q^1); mdf(p,q^1,p^1,q,p^1,q^1); GG; }
	mdf(p,q,p^1,q,p^1,q^1);mdf(p,q^1,p^1,q,p^1,q^1); GG;
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	return 0;
}