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
	#define sz 505050
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
struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
int deg[sz];
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,head[t]};
	head[t]=ecnt;
}
vector<int>p,q;

set<int>S;
int fa[sz]; vector<int>V[sz];
#define PB push_back
void dfs(int x,int f)
{
	int c=0; for (auto v:V[x]) c+=(!V[v].size());
	if (!c) { if (f!=-1) p.PB(x),p.PB(f),q.PB(f),q.PB(x),f=-1; else f=x; dfs(V[x][0],f); rep(i,1,(int)V[x].size()-1) dfs(V[x][i],-1); return; }
	q.PB(x); if (f!=-1) p.PB(f),q.PB(f); for (auto v:V[x]) if (!V[v].size()) p.PB(v),q.PB(v); p.PB(x);
	for (auto v:V[x]) if (V[v].size()) dfs(v,-1);
}

void work()
{
	// CLEAR!!
	read(n,m);
	int x,y; while (m--) read(x,y),make_edge(x,y),++deg[x],++deg[y];
	rep(i,1,n) if (deg[i]==n-1) p.push_back(i),q.push_back(i);
	queue<int>qq; rep(i,1,n) if (deg[i]!=n-1) S.insert(i);
	while (233)
	{
		if (!S.size()) break; if (!qq.size()) qq.push(*(S.begin())),S.erase(S.begin());
		int x=qq.front(); qq.pop();
		static int st[sz],tp; tp=0;
		#define v edge[i].t
		go(x) if (S.count(v)) S.erase(v),st[++tp]=v;
		for (auto t:S) qq.push(t),fa[t]=x,V[x].push_back(t); S.clear(); rep(i,1,tp) S.insert(st[i]);
	}
	rep(i,1,n) if (!fa[i]&&deg[i]!=n-1) dfs(i,-1);
	static int ans1[sz],ans2[sz];
	rep(i,0,n-1) ans1[p[i]]=i+1,ans2[q[i]]=i+1;
	rep(i,1,n) printf("%d ",ans1[i]); puts("");
	rep(i,1,n) printf("%d ",ans2[i]); puts("");
	p.clear(),q.clear(); rep(i,1,n) head[i]=0,V[i].clear(),fa[i]=0,deg[i]=0; ecnt=0; S.clear();
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	return 0;
}