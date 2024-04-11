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
	#define sz 1010100
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

int n,m;

int pri[sz],npri[sz],mu[sz],dc[sz],cc;
void init()
{
	mu[1]=1,dc[1]=1;
	rep(i,2,sz-1)
	{
		if (!npri[i]) pri[++cc]=i,dc[i]=i,mu[i]=1;
		rep(j,1,cc)
		{
			int x=i*pri[j]; if (x>=sz) break;
			npri[x]=1,dc[x]=dc[i]*(i%pri[j]?pri[j]:1); if (i%pri[j]==0) break;
			mu[x]=mu[i];
		}
	}
}

int in[sz]; // 
int N; //  
int use[sz]; //  

struct Bit
{
	int b[23],u[23],vi[23],cc;
	int add(int x)
	{
		int v=1<<cc,xx=x;
		drep(i,20,0) if (x>>i&1)
		{
			if (!b[i]) return b[i]=x,u[cc]=xx,vi[i]=v,++cc,1<<(cc-1);
			x^=b[i],v^=vi[i];
		}
		return 1<<cc^v;
	}
	void work(int w)
	{
		int U=0;
		drep(i,20,0) if (w>>i&1) assert(b[i]),w^=b[i],U^=vi[i];
		rep(i,0,cc-1) if (U>>i&1) in[u[i]]=1,++N;
	}
}B[(int)(sz*0.65)];

void work(vector<int>&V,int id,int w)
{
	for (auto x:V) use[x]=B[id].add(x);
	B[id].work(w);
}

int w[sz];
vector<int>V[sz];

int main()
{
	file();
	init();
//	{
//		n=1e6,m=0;
//		rep(i,1,n) if (rnd(0,1)) ++m,w[dc[i]]^=i;
//	}
	read(n,m);
	vector<int>q;
	rep(i,1,n) if (mu[i]) q.push_back(i);
	printf("%d ",(int)q.size());
	for (auto x:q) printf("%d ",x); puts(""); fflush(stdout);
	for (auto x:q) read(w[x]);
	drep(i,n,1) if (mu[i]) for (int j=i+i;j<=n;j+=i) if (mu[j]) w[j]^=w[i];
	rep(i,1,n) if (mu[i]) for (int j=i+i;j<=n;j+=i) if (mu[j]) w[i]^=w[j];
	int Q=q.size();
	static int id[sz]; rep(i,0,Q-1) id[q[i]]=i;
	rep(i,1,n) V[id[dc[i]]].push_back(i);
	rep(i,0,Q-1) work(V[i],i,w[q[i]]);
	static int p[sz],K;
	rep(i,0,Q-1) if ((int)V[i].size()!=B[i].cc) p[++K]=i;
	while (N!=m)
	{
		int t=p[rnd(1,K)];
		int x=V[t][rnd(0,(int)V[t].size()-1)]; if ((use[x]&-use[x])==use[x]) continue;
		int _N=N;
		if (in[x]) --_N; else ++_N;
		rep(i,0,B[t].cc-1) if (use[x]>>i&1) assert(x!=B[t].u[i]),_N+=(in[B[t].u[i]]?-1:1);
		if (abs(_N-m)<abs(N-m)||(abs(_N-m)==abs(N-m)&&rnd(0,1)))
		{
			in[x]^=1;
			rep(i,0,B[t].cc-1) if (use[x]>>i&1) in[B[t].u[i]]^=1;
			N=_N;
		}
	}
	int cc=0;
	rep(i,1,n) if (in[i]) ++cc;
	assert(cc==m);
	rep(i,1,n) if (in[i]) printf("%d ",i); fflush(stdout);
	return 0;
}