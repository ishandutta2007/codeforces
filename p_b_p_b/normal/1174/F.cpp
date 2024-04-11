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
	#define sz 202020
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

int n;
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}

int askd(int x){printf("d %d\n",x);fflush(stdout);int ret;read(ret);if (ret==-1) exit(0);return ret;}
int asks(int x){printf("s %d\n",x);fflush(stdout);int ret;read(ret);if (ret==-1) exit(0);return ret;}

vector<int>V[sz];
void dfs(int x,int fa){go(x) if (edge[i].t!=fa) dfs(edge[i].t,x),V[x].push_back(edge[i].t);}

int sum,size[sz],dep[sz],mn,rt;
int del[sz];
void getroot(int x)
{
	size[x]=1;
	int S=-1;
	for (int v:V[x]) if (!del[v])
	{
		dep[v]=dep[x]+1;getroot(v);
		chkmax(S,size[v]);size[x]+=size[v];
	}
	chkmax(S,sum-size[x]);
	if (chkmin(mn,S)) rt=x;
}

int getrt(int x,int siz){dep[x]=0;sum=siz,mn=1e9,getroot(x);return rt;}
void solve(int rt,int len,int siz)
{
	if (len==0) return (void)(printf("! %d\n",rt),fflush(stdout));
	int r=getrt(rt,siz);
	int d,x; if (r==rt) d=len; else d=askd(r);
	if (!d) return (void)(printf("! %d\n",r),fflush(stdout));
	if (d+dep[r]==len) x=asks(r),solve(x,d-1,size[x]);
	else del[r]=1,solve(rt,len,siz-size[r]);
}

int main()
{
//	file();
	read(n);
	int x,y;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs(1,0);
	int d=askd(1);solve(1,d,n);
	return 0;
}