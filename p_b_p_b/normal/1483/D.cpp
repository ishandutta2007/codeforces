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
	#define sz 666
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

int n,m,Q;
ll w[sz][sz],ww[sz][sz];
ll dis0[sz][sz],dis1[sz][sz];
pair<pii,ll>e[sz*sz];

int main()
{
	file();
	read(n,m);
	rep(i,1,n) rep(j,1,n) w[i][j]=(i==j?0:1e18),ww[i][j]=-1e18;
	int x,y,z;
	rep(i,1,m) read(x,y,z),w[x][y]=w[y][x]=z,e[i]=MP(MP(x,y),z);
	read(Q);
	while (Q--) read(x,y,z),ww[x][y]=ww[y][x]=z;
	rep(i,1,n) rep(j,1,n) dis0[i][j]=w[i][j];
	rep(k,1,n) rep(i,1,n) rep(j,1,n) chkmin(dis0[i][j],dis0[i][k]+dis0[k][j]);
	rep(i,1,n) rep(j,1,n) dis1[i][j]=-ww[i][j];
	rep(k,1,n) rep(i,1,n) rep(j,1,n) chkmin(dis1[i][j],min(dis1[i][k]+dis0[k][j],dis0[i][k]+dis1[k][j]));
	int ans=0;
	rep(i,1,m) if (dis1[e[i].fir.fir][e[i].fir.sec]+e[i].sec<=0) ++ans;
	cout<<ans;
	return 0;
}