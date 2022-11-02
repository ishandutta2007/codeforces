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
	#define sz 808080
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

struct hh{int x,y;hh(int X=0,int Y=0){x=X,y=Y;}const bool operator < (const hh &a) const {return x==a.x?y<a.y:x<a.x;}}p[sz],P[sz]; int n;
hh jmp(hh a,int len)
{
	int x=a.x,y=a.y;
	while (len>(x&-x)) len-=x&-x,y&=~(x&-x),x^=x&-x;
	if (y&(x&-x)) y-=len; x-=len; return hh(x,y);
}
hh lca(hh a,hh b)
{
	if (a.x<b.x) swap(a,b); a=jmp(a,a.x-b.x);
	int t=a.y^b.y,c=0; for (int tt=t;tt;tt>>=1,++c);
	int tt=(1<<c)-1; a.x-=tt&a.x,a.y-=tt&a.y; return a;
}
bool cmp(hh a,hh b){int tp=-1;if (a.x>b.x) a=jmp(a,a.x-b.x),tp=0; else b=jmp(b,b.x-a.x),tp=1;if (a.y!=b.y) return a.y<b.y;return tp==1;} 

map<hh,int>id;
int w[sz];

set<int>S;
void add(int x){if (!x) return;if (S.count(x)) S.erase(x);else S.insert(x);}
vector<int>V[sz]; int fa[sz];
void dfs(int x)
{
	for (auto v:V[x]) dfs(v),w[x]+=w[v];
	int dx=P[x].x+1,df=P[fa[x]].x+2; if (!fa[x]) df=1;
	if (w[x]) add(dx),add(df-1);
}

int main()
{
	file();
	int m; read(m);
	auto add=[&](hh a){if (!id.count(a)) p[++n]=a,id[a]=n;};
	while (m--)
	{
		int x1,y1,x2,y2; read(x1,y1,x2,y2); hh a(x1+y1,x1),b(x2+y2,x2);
		add(a),add(b);
		hh l=lca(a,b); add(l); 
		if (l.x||l.y) add(jmp(l,1));
		++w[id[a]],++w[id[b]],--w[id[l]]; if (l.x||l.y) --w[id[jmp(l,1)]];
	}
	add(hh(0,0));
	sort(p+1,p+n+1,cmp); int _n=n; rep(i,2,_n) add(lca(p[i-1],p[i])); sort(p+1,p+n+1,cmp); rep(i,2,n) fa[id[p[i]]]=id[lca(p[i-1],p[i])];
	rep(i,1,n) P[id[p[i]]]=p[i];
	int rt=0;
	rep(i,1,n) if (fa[i]) V[fa[i]].push_back(i); else rt=i;
	dfs(rt);
	cout<<S.size();
	return 0;
}