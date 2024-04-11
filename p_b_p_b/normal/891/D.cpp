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
	#define sz 500101
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
#define v edge[i].t

int size[sz];
int up[sz],dn[sz]; // 0:all ok; 1:root left; -1:no
void dfs1(int x,int fa)
{
	size[x]=1;
	int c=0;
	go(x) if (v!=fa) dfs1(v,x),c+=(dn[v]==-1?233:dn[v]),size[x]+=size[v];
	if (c>1) dn[x]=-1; else dn[x]=c^1;
}
void dfs2(int x,int fa)
{
	if (!fa) up[x]=1;
	int c=0;
	go(x) if (v!=fa) c+=(dn[v]==-1?233:dn[v]);
	go(x) if (v!=fa)
	{
		if (up[x]==-1) { up[v]=-1; dfs2(v,x); continue; }
		int cc=c-(dn[v]==-1?233:dn[v]);
		if (cc==0) up[v]=up[x]^1;
		else if (cc==1&&up[x]) up[v]=1;
		else up[v]=-1;
		dfs2(v,x); 
	}
}
ll F[sz][2],G[sz][2]; // 0:all clear; 1:one left
void dfs3(int x,int fa)
{
	int c=0;
	go(x) if (v!=fa) c+=(dn[v]==-1?233:dn[v]);
	go(x) if (v!=fa)
	{
		dfs3(v,x);
		int cc=c-(dn[v]==-1?233:dn[v]);
		if (cc>1) continue;
		if (cc==0) F[x][0]+=F[v][1],F[x][1]+=F[v][0];
		else F[x][0]+=F[v][0];
	}
	if (c==0) ++F[x][0];
}
ll sum[sz][4][2];
void dfs4(int x,int fa)
{
	int c=0;
	go(x) if (v!=fa) c+=(dn[v]==-1?2:dn[v]);
	if (c<=3) rep(k,0,1) sum[x][c][k]+=G[x][k];
	c+=(up[x]==-1?2:(up[x]^1));
	go(x) if (v!=fa)
	{
		int cc=c-(dn[v]==-1?2:dn[v]);
		if (cc<=3) rep(k,0,1) sum[x][cc][k]+=F[v][k];
	}
	go(x) if (v!=fa)
	{
		int cc=c-(dn[v]==-1?2:dn[v]);
		if (cc<=3) rep(k,0,1) sum[x][cc][k]+=-F[v][k];
		
		rep(c,(dn[v]==-1?2:dn[v]),3)
		{
			int cc=c-(dn[v]==-1?2:dn[v]);
			if (cc>1) continue;
			if (cc==0) G[v][0]+=sum[x][c][1],G[v][1]+=sum[x][c][0];
			else G[v][0]+=sum[x][c][0];
		}
		if (cc==0) ++G[v][0];
		dfs4(v,x);
		
		if (cc<=3) rep(k,0,1) sum[x][cc][k]+=F[v][k];
	}
}

int main()
{
	file();
	read(n);
	int x,y;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs1(1,0),dfs2(1,0);
	dfs3(1,0);dfs4(1,0);
	ll ans=0;
	rep(x,2,n) 
		if (!dn[x]&&up[x]==1) ans+=1ll*size[x]*(n-size[x]);
		else ans+=1ll*F[x][0]*G[x][0];
	cout<<ans;
	return 0;
}