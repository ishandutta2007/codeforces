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
	#define sz 1010010
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

const int m=289,MX=28;

int pri[sz],npri[sz],pcc;
void init() { rep(i,2,sz-1) if (!npri[i]) { pri[++pcc]=i; for (int j=i+i;j<sz;j+=i) npri[j]=1; } }

map<vector<int>,int>id; vector<int>P[43333]; int cc;
int dv[sz];
void dfs(vector<int>V,int cur,int mx,int w,int d)
{
	id[V]=++cc,dv[cc]=d,P[cc]=V;
	V.push_back(0);
	rep(i,1,mx)
	{
		cur*=pri[w]; if (cur>1e6) break;
		V.back()=i; dfs(V,cur,i,w+1,d*(i+1));
	}
}
void dfs2(vector<int>V,int res,int mx,int d)
{
	if (!id.count(V)) id[V]=++cc,P[cc]=V,dv[cc]=d;
	chkmin(mx,res); V.push_back(0);
	rep(i,1,mx) V.back()=i,dfs2(V,res-i,i,d*(i+1));
}

vector<int>V[sz];
int dis[m+5][43333];
void BFS(int S,int *dis)
{
	queue<int>q; q.push(S);
	rep(i,1,cc) dis[i]=1e9; dis[S]=0;
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		for (auto v:V[x]) if (chkmin(dis[v],dis[x]+1)) q.push(v);
	}
}

int work(int x)
{
	vector<int>v;
	rep(i,1,cc) if (pri[i]*pri[i]>x) break; else if (x%pri[i]==0) { v.push_back(0); while (x%pri[i]==0) v.back()++,x/=pri[i]; }
	if (x!=1) v.push_back(1);
	sort(v.begin(),v.end(),greater<int>());
	return id[v];
}

int main()
{
	file();
	init();
	dfs({},1,100,1,1);
	dfs2({},MX,MX,1);
	rep(i,1,cc)
	{
		auto p=P[i];
		rep(k,0,(int)p.size()-1) if (k==0||p[k]<p[k-1]) { ++p[k]; if (id.count(p)) V[i].push_back(id[p]),V[id[p]].push_back(i); --p[k]; }
		p.push_back(1); if (id.count(p)) V[i].push_back(id[p]),V[id[p]].push_back(i);
	}
	static int _dv[33333]; rep(i,1,cc) _dv[i]=dv[i]; sort(_dv+1,_dv+cc+1); int K=unique(_dv+1,_dv+cc+1)-_dv-1;
	rep(i,1,cc) dv[i]=lower_bound(_dv+1,_dv+K+1,dv[i])-_dv;
	rep(i,1,m) BFS(i,dis[i]);
	static int dd[m+5][2133]; memset(dd,0x3f,sizeof(dd));
	rep(i,1,m) rep(j,1,cc) chkmin(dd[i][dv[j]],dis[i][j]);
	static int ans[m+5][m+5];
	rep(i,1,m) rep(j,1,m)
	{
		int mn=1e9;
		rep(k,1,K) chkmin(mn,dd[i][k]+dd[j][k]);
		ans[i][j]=mn;
	}
	int Q; read(Q);
	while (Q--)
	{
		int a,b; read(a,b); a=work(a),b=work(b);
		printf("%d\n",ans[a][b]);
	}
	return 0;
}