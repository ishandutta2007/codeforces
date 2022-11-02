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
	#define sz 1100000
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
int ppc[sz],to[sz];
int mat[sz],inR[sz];
int ans;

int in[sz]; vector<int>V2;
int mx[sz],pre[sz];
void dfs(int x)
{
	if (mat[x]==-1) return;
	rep(i,0,n-1) if (in[1<<i^mat[x]]&&chkmax(mx[1<<i^mat[x]],mx[x])) pre[1<<i^mat[x]]=x,dfs(1<<i^mat[x]);
}

int work(int _w)
{
	for (auto x:V2) mx[x]=-1e7,pre[x]=-1;
	for (auto x:V2) rep(i,0,n-1) if (!inR[1<<i^x]&&chkmax(mx[x],a[1<<i^x])) pre[x]=1<<i^x;
	sort(V2.begin(),V2.end(),[](int x,int y){return mx[x]>mx[y];});
	for (auto x:V2) dfs(x);
	int _mx=-1,X=-1; for (auto x:V2) if (mat[x]==-1&&chkmax(_mx,a[x]+mx[x])) X=x;
	if (_mx<=_w) return 0;
	ans+=_mx;
	while (ppc[pre[X]]&1) mat[X]=mat[pre[X]],X=pre[X];
	inR[pre[X]]=1,mat[X]=pre[X]; rep(i,0,n-1) if (chkmax(in[1<<i^mat[X]],1)) V2.push_back(1<<i^mat[X]);
	return 1;
}

void Assert(int x)
{
	static int ti; ++ti;
	if (!x) exit((cout<<ti,0));
}

int main()
{
	file();
	read(n,K);
	rep(i,0,(1<<n)-1) read(a[i]),ppc[i]=__builtin_popcount(i);
	priority_queue<pii>q; 
	rep(x,0,(1<<n)-1) if (ppc[x]&1) { int mx=-1; rep(i,0,n-1) if (chkmax(mx,a[1<<i^x])) to[x]=1<<i^x; q.push(MP(mx+a[x],x)); }
	memset(mat,-1,sizeof(mat)); chkmin(K,1<<(n-1));
	rep(_,1,K)
	{
		int mx=-1;
		while (q.size()&&in[q.top().sec]) q.pop();
		if (q.size()) mx=q.top().fir;
		if (!work(mx)) 
		{
			ans+=mx;
			int x=q.top().sec,y=to[x];
			mat[x]=y,inR[y]=1;
			rep(i,0,n-1) if (chkmax(in[1<<i^y],1)) V2.push_back(1<<i^y);
		}
	}
	int c=0; ll sum=0;
	static int ti[sz];
	rep(i,0,(1<<n)-1) if ((ppc[i]&1)&&mat[i]!=-1) ++c,++ti[mat[i]],Assert(inR[mat[i]]),Assert(in[i]),Assert(ti[mat[i]]==1),Assert(ppc[i^mat[i]]==1),sum+=a[i]+a[mat[i]];
	Assert(c==K),Assert(sum==ans);
	cout<<ans;
	return 0;
}