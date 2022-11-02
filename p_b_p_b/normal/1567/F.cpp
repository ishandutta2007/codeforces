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
	#define sz 555555
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
char s[555][555];
const int fx[4][2]={{0,1},{-1,0},{0,-1},{1,0}};

vector<int>V[sz];
int col[sz];
void dfs(int x)
{
	for (auto v:V[x])
		if (col[v]==-1) col[v]=col[x]^1,dfs(v);
		else assert(col[v]==(col[x]^1));
}

int main()
{
	file();
	read(n,m);
	rep(i,1,n) cin>>(s[i]+1);
	rep(i,2,n-1) rep(j,2,m-1) if (s[i][j]=='X')
	{
		int c=0; vector<int>t;
		rep(k,0,3) if (s[i+fx[k][0]][j+fx[k][1]]=='.') ++c,t.push_back((i+fx[k][0]-1)*m+(j+fx[k][1])-1);
		if (c&1) return puts("NO"),0;
		rep(k,0,c-1) V[t[k]].push_back(t[k^1]); 
	}
	rep(i,0,n*m-1) col[i]=-1;
	rep(i,0,n*m-1) if (col[i]==-1) col[i]=0,dfs(i);
	puts("YES");
	rep(i,1,n) 
	{
		rep(j,1,m) if (s[i][j]=='X')
		{
			int c=0;
			rep(k,0,3) if (s[i+fx[k][0]][j+fx[k][1]]=='.') c+=(col[(i+fx[k][0]-1)*m+(j+fx[k][1])-1]?1:4);
			printf("%d ",c);
		} else printf("%c ","41"[col[(i-1)*m+j-1]]);
		puts("");
	}
	return 0;
}