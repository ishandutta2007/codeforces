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
	#define sz 101010
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

int K;
int f[sz];
int id[sz],fa[sz],cnt;
#define v edge[i].t
void dfs(int x,int fa)
{
	::fa[x]=fa;
	go(x) if (v!=fa) dfs(v,x);
	id[++cnt]=x;
}
int check(int len)
{
	K=len;
	int ret=0;
	rep(i,1,n)
	{
		int x=id[i],mx1=0,mx2=0;
		go(x) if (v!=fa[x])
		{
			if (f[v]>mx1) mx2=mx1,mx1=f[v];
			else if (f[v]>mx2) mx2=f[v];
		}
		if (mx1+mx2+1>=K) ++ret,f[x]=0;
		else f[x]=mx1+1;
	}
	return ret;
}
#undef v

int ans[sz];

void solve(int l,int r,int L,int R)
{
	if (r<l) return;
	if (L==R) { rep(i,l,r) ans[i]=L; return; }
	int mid=(l+r)>>1,s=check(mid);
	ans[mid]=s;
	solve(l,mid-1,s,R),solve(mid+1,r,L,s);
}

int main()
{
	file();
	read(n);
	int x,y;
	rep(i,1,n-1) read(x,y),make_edge(x,y);
	dfs(1,0);
	/*
	int T=sqrt(n*log2(n));
	rep(i,1,T) ans[i]=check(i);
	int las=T;
	drep(i,n/T,0)
	{
		int l=las+1,r=n,R=-1;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (check(mid)>=i) R=mid,l=mid+1;
			else r=mid-1;
		}
		rep(j,las+1,R) ans[j]=i;
		las=max(las,R);
	}
	rep(i,1,n) printf("%d\n",ans[i]);
	*/
	solve(1,n,0,n);
	rep(i,1,n) printf("%d\n",ans[i]);
	return 0;
}