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
	#define sz 555
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
char s[sz][sz];

int fa[sz*sz];
int id(int x,int y){return x*(m-1)+y;}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}

int fx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void work()
{
	read(n,m);
	rep(i,0,n-1) { int j=0;char c=getchar();while (c!='X'&&c!='.') c=getchar();while (j<m-1) s[i][j]=c,c=getchar(),++j;s[i][m-1]=c; }
	rep(i,0,n-1) s[i][m]='\0';
	for (int i=0;i<n;i+=3) rep(j,0,m-1) s[i][j]='X';
	for (int i=0;i<n-2;i+=3)
	{
		int flg=0;
		rep(j,0,m-1) if (s[i+1][j]=='X'||s[i+2][j]=='X') { flg=1; s[i+1][j]=s[i+2][j]='X'; break; }
		if (!flg) s[i+1][0]=s[i+2][0]='X';
	}
	if ((n-1)%3==2)
	{
		rep(i,0,m-1) if (s[n-1][i]=='X') s[n-2][i]='X';
	}
//	rep(i,0,n*m-1) fa[i]=i;
//	for (int x=0;x<n;x+=2) rep(y,0,m-1) if (s[x][y]!='X')
//	{
//		vector<int>V;
//		rep(i,0,3) { int xx=x+fx[i][0],yy=y+fx[i][1]; if (xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]=='X') V.push_back(getfa(id(xx,yy))); }
//		int c=0;
//		for (auto a:V) for (auto b:V) if (a==b) ++c;
//		if (c>(int)V.size()) continue;
//		for (auto a:V) fa[getfa(a)]=getfa(id(x,y));
//		s[x][y]='X';
//	}
//	for (int x=1;x<n;x+=2) rep(y,0,m-1) if (s[x][y]!='X')
//	{
//		vector<int>V;
//		rep(i,0,3) { int xx=x+fx[i][0],yy=y+fx[i][1]; if (xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]=='X') V.push_back(getfa(id(xx,yy))); }
//		int c=0;
//		for (auto a:V) for (auto b:V) if (a==b) ++c;
//		if (c>(int)V.size()) continue;
//		for (auto a:V) fa[getfa(a)]=getfa(id(x,y));
//		s[x][y]='X';
//	}
	rep(i,0,n-1) puts(s[i]);
}

int main()
{
	file();
	int T; read(T);
	while (T--) work();
	return 0;
}