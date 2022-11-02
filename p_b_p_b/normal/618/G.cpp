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
	#define sz 3333
	typedef long long ll;
	typedef long double db;
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

const int m=50;

int n;db p;
db P[sz],pp[sz];

void work(db *F,db *G,int n)
{
	static db f[sz][m+5],g[sz][m+5];
	memset(f,0,sizeof(f)),memset(g,0,sizeof(g));
	rep(i,1,min(m,n+1)) f[1][i]=F[i],g[1][i]=G[i];
	rep(i,2,n) rep(j,1,min(n-i+2,m))
	{
		rep(k,j+1,m)
		{
			db w=(j==n-i+2?pp[j]:P[j]);
			if (i==n) w=(j==1?p:1-p);
			f[i][j]+=f[i-1][k]*w;
			g[i][j]+=w*(g[i-1][k]+f[i-1][k]*j);
		}
		db w;
		if (j==2) w=1-p;
		else if (j==1) w=0;
		else if (j!=n-i+2) w=pp[j];
		else w=pp[j-1]*pp[j-1];
		f[i][j]+=f[i-1][1]*w;
		g[i][j]+=w*(g[i-1][1]+f[i-1][1]*j);
	}
	db ans=0;
	rep(i,1,m) ans+=g[n][i];
	cout<<setprecision(17)<<ans<<'\n';
}

db f[sz][m+5],g[sz][m+5],tmp1[m+5],tmp2[m+5];

int main()
{
	file();
	read(n,p),p/=1e9;
	if (n==1) return cout<<setprecision(17)<<p+2*(1-p)<<'\n',0;
	P[1]=p,P[2]=1-p+p*p; rep(i,3,m) { P[i]=P[i-1]*P[i-1]; if (P[i]<1e-12) break; }
	pp[2]=1-p; rep(i,3,m) { pp[i]=pp[2]; rep(j,2,i-1) pp[i]*=P[j]; if (pp[i]<1e-12) break; }
	rep(i,1,min(m,n)) f[1][i]=P[i],g[1][i]=P[i]*i; if (n+1<=m) f[1][n+1]=pp[n+1],g[1][n+1]=pp[n+1]*(n+1);
	if (n<=2000) return work(f[1],g[1],n),0;
	rep(i,2,1500) rep(j,1,m)
	{
		rep(k,j+1,m)
		{
			db w=P[j];
			f[i][j]+=f[i-1][k]*w;
			g[i][j]+=w*(g[i-1][k]+f[i-1][k]*j);
		}
		db w=pp[j];
		f[i][j]+=f[i-1][1]*w;
		g[i][j]+=w*(g[i-1][1]+f[i-1][1]*j);
	}
	int nn=n-1500-100;
	rep(i,1,m) tmp1[i]=f[1500][i];
	rep(i,1,m) tmp2[i]=g[1500][i]+(g[1500][i]-g[1499][i])*nn;
	work(tmp1,tmp2,101);
	return 0;
}