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
	#define sz 202020
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

int n,m;
struct hh
{
	int u[2],v[2],vis[2];
	pii nxt[2];
}q[sz];
map<pii,pii>lst;

int fa[sz],dep[sz];
int getfa(int x){return x==fa[x]?x:getfa(fa[x]);}
pii st[sz];int top;
void merge(int x,int y)
{
	x=getfa(x),y=getfa(y);
	if (x==y) return;
	if (dep[x]>dep[y]) swap(x,y);
	fa[x]=y;
	pii ret=MP(x,0);
	if(dep[x]==dep[y]) ++dep[y],ret.sec=1;
	st[++top]=ret;
}
void reset(int pre){pii cur;while (top>pre) cur=st[top],--top,dep[fa[cur.fir]]-=cur.sec,fa[cur.fir]=cur.fir;}

int ans;
vector<pii>V[sz<<2];
#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
void add(int k,int l,int r,int x,int y,pii e)
{
	if (x>y) return;
	if (x<=l&&r<=y) return V[k].push_back(e);
	int mid=(l+r)>>1;
	if (x<=mid) add(lson,x,y,e);
	if (y>mid) add(rson,x,y,e);
}
void solve(int k,int l,int r)
{
	int pre=top;for (auto e:V[k]) merge(e.fir,e.sec);
	if (l!=r) 
	{ 
		int mid=(l+r)>>1; 
		solve(lson);
		solve(rson); 
		reset(pre); 
		return; 
	}
	if (q[l].vis[0]==-1) putchar('0'+(ans=(getfa(q[l].u[ans])==getfa(q[l].v[ans]))));
	else 
	{
		pii nxt0=q[l].nxt[ans];
		pii nxt1=q[l].nxt[ans^1];
		if (!q[l].vis[ans]) add(1,1,m,l+1,nxt0.fir-1,MP(q[l].u[ans],q[l].v[ans])),q[nxt0.fir].vis[nxt0.sec]=1;
		if (q[l].vis[ans^1]) add(1,1,m,l+1,nxt1.fir-1,MP(q[l].u[ans^1],q[l].v[ans^1])),q[nxt1.fir].vis[nxt1.sec]=1;
	}
	reset(pre);
}

int main()
{
	file();
	read(n,m);
	int z,x,y;
	if (n==2) { int cur=0; while (m--) read(z,x,y),z==1?cur^=1:putchar('0'+cur); return 0; }
	rep(i,1,m)
	{
		read(z,x,y);int xx,yy;
		if (z==2) { rep(k,0,1) xx=(x-1+k)%n+1,yy=(y-1+k)%n+1,q[i].u[k]=xx,q[i].v[k]=yy; q[i].vis[0]=-1; }
		else rep(k,0,1) xx=(x-1+k)%n+1,yy=(y-1+k)%n+1,xx>yy?swap(xx,yy):void(),q[i].u[k]=xx,q[i].v[k]=yy;
	}
	rep(i,1,m)
	{
		if (q[i].vis[0]==-1) continue;
		rep(k,0,1)
		{
			int u=q[i].u[k],v=q[i].v[k];pii cur=lst[MP(u,v)];
			if (cur.fir) q[cur.fir].nxt[cur.sec]=MP(i,k);
			lst[MP(u,v)]=MP(i,k);
		}
	}
	rep(i,1,n) fa[i]=i;
	rep(i,1,m) rep(k,0,1) if (!q[i].nxt[k].fir) q[i].nxt[k].fir=m+1;
	solve(1,1,m);
	return 0;
}