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
	#define sz 603030
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
int a[sz],mx;
int ok[sz];

struct hh{int t,l,r;};
vector<hh>V[sz];
void dfs(int x)
{
	for (auto p:V[x])
	{
		int y=p.t; if (ok[y]) continue;
		ok[y]=1;
		int l=p.l,r=p.r;
		if (a[l-1]==y) a[l]=y; else assert(a[r+1]==y),a[r]=y;
		dfs(y);
	}
}
int fa[sz];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}

int e[666][666];
namespace Blossom
{
int n;
int fa[sz];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int pre[sz],match[sz],tp[sz];
queue<int>q;
int vis[sz],T;
int lca(int x,int y) { for (++T;;swap(x,y)) if (x) { x=getfa(x); if (vis[x]==T) return x; vis[x]=T,x=pre[match[x]]; } }
void shrink(int x,int y,int l)
{
	while (getfa(x)!=l)
	{
		pre[x]=y,y=match[x];
		if (tp[y]==2) tp[y]=1,q.push(y);
		if (x==fa[x]) fa[x]=l;
		if (y==fa[y]) fa[y]=l;
		x=pre[y]; 
	}
}
int work(int s)
{
	while (q.size()) q.pop(); q.push(s);
	rep(i,1,n) fa[i]=i,pre[i]=0,tp[i]=0;
	tp[s]=1;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		rep(v,1,n) if (e[x][v])
		{
			if (getfa(x)==getfa(v)||tp[v]==2) continue;
			if (!tp[v])
			{
				pre[v]=x;
				if (!match[v])
				{
					for (int cur=v;cur;swap(cur,match[pre[cur]])) match[cur]=pre[cur];
					match[0]=0;
					return 1;
				}
				tp[v]=2,tp[match[v]]=1,q.push(match[v]);
			}
			else { int l=lca(x,v); shrink(x,v,l),shrink(v,x,l); }
		}
	}
	return 0;
}
void main()
{
	rep(i,1,n) rep(j,i+1,n) if (!match[i]&&!match[j]&&e[i][j]) match[i]=j,match[j]=i;
	rep(i,1,n) if (!match[i]) work(i);
}
}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(a[i]),chkmax(mx,a[i]);
	if (mx==0) { rep(i,1,n) printf("%d ",(i+1)/2); return 0; }
	rep(i,1,n) 
		if (a[i]) { if (i%2==0) a[i-1]=a[i]; break; }
		else a[i]=mx+1,mx+=(i%2==0);
	drep(i,n,1)
		if (a[i]) { if ((n-i+1)%2==0) a[i+1]=a[i]; break; }
		else a[i]=mx+1,mx+=((n-i+1)%2==0);
	rep(i,2,n) if (a[i]&&a[i]==a[i-1]&&a[i]<=600) ok[a[i]]=1;
	rep(i,1,600) fa[i]=i;
	for (int l=1,r;l<=n;l=r+1)
	{
		if (a[l]) { r=l; continue; }
		for (r=l;r<n&&!a[r+1];++r);
		if ((r-l+1)%2==0) continue;
		if (a[l-1]>600||a[r+1]>600)
		{
			if (a[l-1]<=600&&!ok[a[l-1]]) a[l]=a[l-1],ok[a[l-1]]=1,dfs(a[l-1]);
			else if (a[r+1]<=600&&!ok[a[r+1]]) a[r]=a[r+1],ok[a[r+1]]=1,dfs(a[r+1]);
			continue;
		}
		int x=getfa(a[l-1]),y=getfa(a[r+1]);
		if (ok[x]&&ok[y]) continue;
		else if (ok[x]) a[r]=a[r+1],ok[a[r+1]]=1,dfs(a[r+1]);
		else if (ok[y]) a[l]=a[l-1],ok[a[l-1]]=1,dfs(a[l-1]);
		else if (x==y) a[r]=a[r+1],ok[a[r+1]]=1,dfs(a[r+1]);
		else fa[x]=y,V[a[l-1]].push_back((hh){a[r+1],l,r}),V[a[r+1]].push_back((hh){a[l-1],l,r});
	}
	static int id[sz],pre[sz]; int m=0;
	rep(i,1,600) if (fa[i]==i&&!ok[i]) id[i]=++m,pre[m]=i;
	Blossom::n=m;
	for (int l=1,r;l<=n;l=r+1)
	{
		if (a[l]) { r=l; continue; }
		for (r=l;r<n&&!a[r+1];++r);
		if ((r-l+1)%2==1) continue;
		if (ok[a[l-1]]||ok[a[r+1]]) continue;
		int x=id[getfa(a[l-1])],y=id[getfa(a[r+1])];
		e[x][y]=e[y][x]=1;
	}
	Blossom::main();
	static int mat[666][666];
	rep(i,1,m) if (Blossom::match[i]) mat[pre[i]][pre[Blossom::match[i]]]=1;
	for (int l=1,r;l<=n;l=r+1)
	{
		if (a[l]) { r=l; continue; }
		for (r=l;r<n&&!a[r+1];++r);
		if ((r-l+1)%2==1) continue;
		if (ok[a[l-1]]||ok[a[r+1]]) continue;
		int x=getfa(a[l-1]),y=getfa(a[r+1]);
		if (mat[x][y]&&!ok[x]) a[l]=a[l-1],ok[a[l-1]]=1,a[r]=a[r+1],ok[a[r+1]]=1,dfs(a[l]),dfs(a[r]);
	}
	rep(i,1,600) if (fa[i]==i&&!ok[i]) ok[i]=1,dfs(i);
	rep(i,2,n) if (!a[i-1]&&!a[i]) a[i-1]=a[i]=++mx;
	rep(i,1,n) if (!a[i]) a[i]=++mx;
	static int vis[sz],p[sz]; int K=0;
	rep(i,1,n) vis[a[i]]=1;
	rep(i,1,n) if (!vis[i]) ++K,p[n+K]=i;
	rep(i,1,n) p[i]=i;
	rep(i,1,n) printf("%d ",p[a[i]]);
	return 0;
}