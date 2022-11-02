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
	#define sz 1010100
	typedef long long ll;
	typedef double db;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	template<typename T>inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
	template<typename T>inline void read(T& t)
	{
		t=0;char f=0,ch=getchar();double d=0.1;
		while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
		while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
		if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
		t=(f?-t:t);
	}
	template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
	void file()
	{
		#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
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
char s[sz];

struct hh{int t,nxt;}edge[sz<<1];
int head[sz],ecnt;
void make_edge(int f,int t)
{
	edge[++ecnt]=(hh){t,head[f]};
	head[f]=ecnt;
}
struct hhh{int u,v;}e[sz];

int fa[sz];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void merge(int u,int v)
{
	u=getfa(u),v=getfa(v);
	fa[u]=v;
}

int deg[sz];
int dp[sz];
void topo()
{
	queue<int>q;
	rep(i,1,n+m) if (fa[i]==i&&!deg[i]) q.push(i),dp[i]=1;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		#define v edge[i].t
		go(x) 
		{
			--deg[v];
			dp[v]=max(dp[v],dp[x]+1);
			if (!deg[v]) q.push(v);
		}
		#undef v
	}
	rep(i,1,n+m) if (fa[i]==i&&deg[i]) exit((puts("No"),0)); 
}

int main()
{
	file();
	read(n,m);
	rep(i,1,n+m) fa[i]=i;
	int c=0;
	rep(i,1,n)
	{
		cin>>(s+1);
		rep(j,1,m)
		{
			if (s[j]=='=') merge(i,j+n);
			else if (s[j]=='<') e[++c]=(hhh){i,j+n};
			else e[++c]=(hhh){j+n,i};
		}
	}
	rep(i,1,c)
	{
		int x=e[i].u,y=e[i].v;x=getfa(x),y=getfa(y);
		if (x==y) return puts("No"),0;
		make_edge(x,y);++deg[y];
	}
	topo();
	puts("Yes");//
	rep(i,1,n) printf("%d ",dp[getfa(i)]);puts("");
	rep(i,n+1,m+n) printf("%d ",dp[getfa(i)]);
	return 0;//
}