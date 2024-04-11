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
	#define sz 255
	#define mod 998244353ll
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
int p[sz],q[sz];
int pre[sz],nxt[sz];

ll s[sz][sz];
ll fac[sz],_fac[sz];
void init(){_fac[0]=fac[0]=1;rep(i,1,sz-1) _fac[i]=inv(fac[i]=fac[i-1]*i%mod);}
ll C(int n,int m){if (n==-1&&m==-1) return 1;return n>=m&&m>=0?fac[n]*_fac[m]%mod*_fac[n-m]%mod:0;}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(p[i]);
	rep(i,1,n) read(q[i]);
	rep(i,1,n) pre[i]=nxt[i]=-1;
	rep(i,1,n) { if (p[i]) nxt[p[i]]=q[i]; if (q[i]) pre[q[i]]=p[i]; }
	static int vis[sz];
	int m=0;
	rep(i,1,n) if (!vis[i])
	{
		vis[i]=1;
		int x=nxt[i]; while (x>0&&!vis[x]) vis[x]=1,x=nxt[x];
		if (x==i) ++m;
	}
	int a=0,b=0,c=0;
	rep(i,1,n) if (pre[i]<=0)
	{
		int x=i; while (nxt[x]>0) x=nxt[x];
		if (pre[i]==-1&&nxt[x]==-1) ++c;
		else if (pre[i]==-1&&nxt[x]==0) ++a;
		else if (pre[i]==0&&nxt[x]==-1) ++b;
	}
	s[0][0]=1;
	rep(i,1,n) rep(j,1,i) s[i][j]=(s[i-1][j]*(i-1)+s[i-1][j-1])%mod;
	init();
	static ll f[sz],g[sz],h[sz],ans[sz];
	rep(i,0,a) rep(j,0,i) (f[j]+=C(a,i)*s[i][j]%mod*C(c+a-i-1,c-1)%mod*fac[a-i]%mod)%=mod;
	rep(i,0,b) rep(j,0,i) (g[j]+=C(b,i)*s[i][j]%mod*C(c+b-i-1,c-1)%mod*fac[b-i]%mod)%=mod;
	rep(i,0,c) h[i]=s[c][i];
	rep(i,0,a) rep(j,0,b) rep(k,0,c) (ans[i+j+k+m]+=f[i]*g[j]%mod*h[k]%mod*fac[c]%mod)%=mod;
	drep(i,n,1) printf("%lld ",ans[i]);
	return 0;
}