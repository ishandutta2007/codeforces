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
	#define sz 101001
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

int n;
vector<int>V[sz];

int dp[sz],pos[sz],up[sz],_fa[sz];
void dfs1(int x,int fa)
{
	_fa[x]=fa;
	for (auto v:V[x]) if (v!=fa) dfs1(v,x);
	if ((int)V[x].size()==1&&fa) return dp[x]=1,pos[x]=x,void();
	vector<pii>W; for (auto v:V[x]) if (v!=fa) W.push_back(MP(dp[v],v));
	sort(W.begin(),W.end()); reverse(W.begin(),W.end());
	pos[x]=pos[W[0].sec];
	int mx=0; rep(i,0,(int)W.size()-1) chkmax(mx,W[i].fir+i);
	dp[x]=mx;
}
void dfs2(int x,int fa)
{
	if ((int)V[x].size()==1&&fa) return;
	vector<pii>W;
	for (auto v:V[x]) if (v!=fa) W.push_back(MP(dp[v],v)); if (fa) W.push_back(MP(up[x],fa));
	sort(W.begin(),W.end()),reverse(W.begin(),W.end()); vector<int>suf; suf.resize(V[x].size());
	suf.back()=W.back().fir+W.size()-1; drep(i,(int)W.size()-2,0) suf[i]=max(suf[i+1],W[i].fir+i);
	int mx=1;
	rep(i,0,(int)W.size()-1) if (W[i].sec!=fa)
	{
		int v=W[i].sec; 
		up[v]=max(mx,((i==(int)W.size()-1)?0:suf[i+1]-1));
		dfs2(v,x); chkmax(mx,W[i].fir);
	}
}
int work(int x)
{
	vector<int>W,suf; for (auto v:V[x]) if (v!=_fa[x]) W.push_back(dp[v]);
	if (x!=1) W.push_back(up[x]);
	sort(W.begin(),W.end()),reverse(W.begin(),W.end());
	suf.resize(W.size()); suf.back()=W.back();
	drep(i,(int)W.size()-2,0) suf[i]=max(suf[i+1]+1,W[i]);
	int mx=0; rep(i,0,(int)W.size()-2) chkmax(mx,W[i]+i+suf[i+1]); chkmax(mx,W.back()+(int)W.size()-1);
	return mx;
}

int query(int x){printf("? %d\n",x);fflush(stdout);return read(x),x;}
int getans(int x)
{
	vector<pii>W; for (auto v:V[x]) if (v!=_fa[x]) W.push_back(MP(dp[v],v));
	sort(W.begin(),W.end()),reverse(W.begin(),W.end());
	rep(i,1,(int)W.size()-1)
	{
		int t=query(pos[W[i].sec]); if (t==x) continue;
		return getans(t);
	}
	return x;
}
void solve(int rt)
{
	memset(dp,0,sizeof(dp)),memset(pos,0,sizeof(pos)),memset(_fa,0,sizeof(_fa));
	dfs1(rt,0);
	vector<pii>W; for (auto v:V[rt]) W.push_back(MP(dp[v],v));
	sort(W.begin(),W.end()),reverse(W.begin(),W.end());
	int A=-1,B=-1;
	rep(i,0,(int)W.size()-1)
	{
		int t=query(pos[W[i].sec]); if (t==rt) continue;
		A=getans(t);
		rep(j,i+1,(int)W.size()-1)
		{
			t=query(pos[W[j].sec]); if (t==rt) continue;
			B=getans(t); break;
		}
		break;
	}
	if (A==-1) A=B=rt; else if (B==-1) B=rt;
	printf("! %d %d\n",A,B); fflush(stdout);
}

int main()
{
//	file();
	read(n);
	int x,y;
	rep(i,1,n-1) read(x,y),V[x].push_back(y),V[y].push_back(x);
	if (n==1) { puts("0"); fflush(stdout); printf("! 1 1"); fflush(stdout); return 0; }
	dfs1(1,0);
	dfs2(1,0);
	int K=0; rep(i,1,n) chkmax(K,work(i));
	printf("%d\n",K); fflush(stdout);
	int rt; read(rt);
	solve(rt);
	return 0;
}