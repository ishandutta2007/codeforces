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
	#define sz 404040
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

vector<int>V[sz];
int in[sz],dfn[sz],low[sz],bel[sz],cc,T;
stack<int>st;
void dfs(int x)
{
	in[x]=1,dfn[x]=low[x]=++cc,st.push(x);
	for (auto v:V[x])
		if (!dfn[v]) dfs(v),chkmin(low[x],low[v]);
		else if (in[v]) chkmin(low[x],dfn[v]);
	if (low[x]==dfn[x])
	{
		int y; ++T;
		do y=st.top(),st.pop(),in[y]=0,bel[y]=T; while (y!=x);
	}
}

int n,m;
vector<char>mp[sz];
vector<int>sum[sz],nxt[sz],nt[sz],dn[sz],up[sz];
int a[sz];
int id(int x,int y){return (x-1)*m+y;}

int tr[sz];
void add(int x,int w){while (x) chkmin(tr[x],w),x-=x&-x;}
int query(int x){int res=1e9;while (x<=n) chkmin(res,tr[x]),x+=x&-x;return res;}

int main()
{
	file();
	read(m,n);
	rep(i,0,n+1) mp[i].resize(m+3),sum[i].resize(m+3),nxt[i].resize(m+3),dn[i].resize(m+3),up[i].resize(m+3),nt[i].resize(m+3);
	drep(i,m,1) { static char s[sz]; scanf("%s",s+1); rep(j,1,n) mp[j][i]=s[j]; }
	rep(i,1,n) read(a[i]);
	rep(i,1,n) rep(j,1,m) sum[i][j]=sum[i][j-1]+(mp[i][j]=='#'),nxt[i][j]=(mp[i][j]=='#'?j:nxt[i][j-1]);
	rep(i,1,n) drep(j,m,1) nt[i][j]=(mp[i][j+1]=='#'?j+1:nt[i][j+1]);
	
	rep(i,1,n) rep(j,1,m) if (mp[i][j]=='#')
	{
		if (nxt[i][j-1]) V[id(i,j)].push_back(id(i,nxt[i][j-1]));
		if (mp[i][j+1]=='#') V[id(i,j)].push_back(id(i,j+1));
		if (nxt[i-1][j]) V[id(i,j)].push_back(id(i-1,nxt[i-1][j]));
		if (nxt[i+1][j]) V[id(i,j)].push_back(id(i+1,nxt[i+1][j]));
	}
	rep(i,1,n) rep(j,1,m) if (!dfn[id(i,j)]) dfs(id(i,j));
	
	rep(i,0,n) drep(j,m,0) if (mp[i][j]=='#')
	{
		if (nt[i][j]&&bel[id(i,j)]==bel[id(i,nt[i][j])]) up[i][j]=up[i][nt[i][j]];
		else if (sum[i][j]<a[i]) up[i][j]=i+1;
		else up[i][j]=up[i-1][nxt[i-1][j]];
	} else up[i][j]=i+1;
	
	drep(i,n+1,1) drep(j,m,0) if (mp[i][j]=='#')
	{
		if (nt[i][j]&&bel[id(i,j)]==bel[id(i,nt[i][j])]) dn[i][j]=dn[i][nt[i][j]];
		else if (sum[i][j]<a[i]) dn[i][j]=i-1;
		else dn[i][j]=dn[i+1][nxt[i+1][j]];
	} else dn[i][j]=i-1;
	
	memset(tr,0x3f,sizeof(tr));
	rep(i,1,n)
	{
		int l=up[i][nxt[i][m]],r=dn[i][nxt[i][m]];
		if (l<=r)
		{
			int dp=1e9; if (l==1) dp=1,++l; else dp=query(l-1)+1;
			add(r,dp);
		}
		if (!a[i])
		{
			add(i,(i==1?0:query(i-1)));
		}
	}
	cout<<query(n);
	return 0;
}