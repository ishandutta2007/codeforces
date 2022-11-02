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

int n,m;
vector<int>V[sz];

int dis[sz][sz];
void BFS(int S,int *dis)
{
	queue<int>q;
	q.push(S); rep(i,1,n) dis[i]=1e9; dis[S]=0;
	while (!q.empty())
	{
		int x=q.front(); q.pop();
		for (auto v:V[x]) if (chkmin(dis[v],dis[x]+1)) q.push(v);
	}
}

ll ans[sz][sz];
int pos[sz],dep[sz],vis[sz];

int main()
{
	file();
	read(n,m);
	int x,y;
	while (m--) read(x,y),V[x].push_back(y),V[y].push_back(x);
	rep(i,1,n) BFS(i,dis[i]);
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			if (i>j) { printf("%lld ",ans[j][i]); continue; }
			if (i==j)
			{
				ll w=1;
				rep(k,1,n) if (k!=i) { int c=0; for (auto v:V[k]) if (dis[i][v]==dis[i][k]-1) ++c; w=w*c%mod; }
				printf("%lld ",w); continue;
			}
			rep(x,0,n) vis[x]=0;
			int flg=1;
			rep(x,1,n)
			{
				dep[x]=(dis[i][x]+dis[j][x]-dis[i][j])/2,pos[x]=dis[i][x]-dep[x];
				if (dep[x]) continue;
				if (!vis[pos[x]]) vis[pos[x]]=1; else flg=0;
			}
			if (!flg) { printf("0 "); continue; }
			ll w=1;
			rep(x,1,n) if (dep[x])
			{
				int c=0;
				for (auto v:V[x]) if (dep[v]==dep[x]-1&&pos[v]==pos[x]) ++c;
				w=w*c%mod;
			}
			printf("%lld ",ans[i][j]=w);
		}
		puts("");
	}
}