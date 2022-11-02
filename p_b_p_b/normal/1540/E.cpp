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
	#define sz 333
	#define mod 1000000007ll
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
ll a[sz]; int d[sz];
vector<int>E[sz];

ll A[sz][sz],V[sz][sz],C[sz][sz];
// A: 
// V[i]:  i 
// C[i]: \sum C[i][j]*V[j] = e[i] 

void init()
{
	rep(i,1,n) A[i][i]=i;
	rep(i,1,n) for (auto v:E[i]) A[i][v]=v;
	rep(i,1,n)
	{
		V[i][i]=1;
		drep(j,i,1) { if (j!=i) V[i][j]=mod-V[i][j]*inv(i-j)%mod; drep(k,j-1,1) (V[i][k]+=mod-V[i][j]*A[k][j]%mod)%=mod; }
	}
	rep(i,1,n)
	{
		C[i][i]=1;
		drep(j,i,1) drep(k,j-1,1) (C[i][k]+=mod-C[i][j]*V[j][k]%mod)%=mod;
	}
	rep(i,1,n) rep(j,1,n) (V[i][j]+=V[i][j-1])%=mod;
}
int id[sz],pos[sz],D[sz]; ll val[sz][sz];
ll tr[sz][sz];
void add(ll *tr,int x,ll w){assert(w>=0);while (x<=n) (tr[x]+=w)%=mod,x+=x&-x;}
ll query(ll *tr,int x){ll res=0;while (x) res+=tr[x],x-=x&-x;assert(res>=0);return res%mod;}
void rebuild()
{
	drep(i,n,1) if (a[i]>0) d[i]=0; else { d[i]=1e9; for (auto v:E[i]) chkmin(d[i],d[v]+1); }
	rep(i,1,n) id[i]=i; sort(id+1,id+n+1,[](int x,int y){return d[x]<d[y];}); rep(i,1,n) D[i]=d[id[i]],pos[id[i]]=i;
	rep(j,1,n) rep(i,1,n) val[j][i]=C[i][j]*ksm(j,mod-1-d[i])%mod,tr[j][i]=0;
	rep(j,1,n) rep(i,1,n) add(tr[j],pos[i],(a[i]+mod)*val[j][i]%mod);
}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(a[i]);
	rep(i,1,n) { int c,x; read(c); while (c--) read(x),E[i].push_back(x); }
	init(); rebuild();
	int Q; read(Q);
	while (Q--)
	{
		int tp,x,y,z; read(tp,x,y);
		if (tp==1)
		{
			read(z);
			int p=lower_bound(D+1,D+n+1,x)-D-1; ll ans=0;
			rep(j,1,n) (ans+=(V[j][z]-V[j][y-1]+mod)*ksm(j,x)%mod*query(tr[j],p)%mod)%=mod;
			rep(i,y,z) if (d[i]>=x) (ans+=a[i]+mod)%=mod;
			printf("%lld\n",ans);
		}
		else { ll t=a[x]; a[x]+=y; if (t<=0&&a[x]>0) rebuild(); else rep(j,1,n) add(tr[j],pos[x],val[j][x]*y%mod); }
	}
	return 0;
}