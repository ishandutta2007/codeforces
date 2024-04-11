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
	#define sz 555
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

int n,K;
int a[sz];

int Xor(int l,int r)
{
	printf("? ");
	if (r-l+1==K) { rep(i,l,r) a[i]^=1,printf("%d ",i); }
	else rep(i,1,n) if (i<l||i>r) a[i]^=1,printf("%d ",i);
	puts(""); fflush(stdout);
	int x; read(x); return x;
}
int Xor_res()
{
	int c=0; printf("? "); rep(i,1,n) if (!a[i]) printf("%d ",i),++c; puts("");
	fflush(stdout); assert(c==K);
	int x; read(x); return x;
}

void work(int K)
{
	int r=n,ans=0;
	while (r>=2*K) ans^=Xor(r-K+1,r),r-=K;
	if (r==K) ans^=Xor(1,r);
	else if (r%2==0)
	{
		int t=K-(r-K); t/=2;
		ans^=Xor(r-K+1+t,r+t);
		ans^=Xor_res();
	}
	else
	{
		ans^=Xor(r-K+1,r); r-=K;
		ans^=Xor(r/2+1,r/2+K);
		ans^=Xor_res();
	}
	printf("! %d\n",ans); fflush(stdout);
}

int main()
{
	read(n,K);
	if (K%2==0&&n%2==1) return puts("-1"),0; 
	if (K==n)
	{
		int x=Xor(1,n);
		printf("! %d\n",x); fflush(stdout);
		return 0;
	}
	if (K*2>n&&K%2==n%2)
	{
		int ans=0; int k=n-K;
		ans^=Xor(1,k),ans^=Xor(k/2+1,k/2*3);
		ans^=Xor_res();
		printf("! %d\n",ans); fflush(stdout);
		return 0;
	}
	if (K*2>n) work(n-K); else work(K);
	return 0;
}