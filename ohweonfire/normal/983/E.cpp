// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int maxn=200111;

//offline two dimensional counting with divide-and-conquer+BIT
namespace BIT
{
	int bit[200111],timer,mark[200111];
	void add(int x,int v){for(;x<200111;x+=x&-x){if(mark[x]!=timer){mark[x]=timer;bit[x]=0;}bit[x]+=v;}}
	int query(int x){int ret=0;for(;x;x-=x&-x)if(mark[x]==timer)ret+=bit[x];return ret;}
};
struct twod_query_v2
{
	struct query//tp=0: (l,r)+=tx   tp<0: ans[-tp]-=[0,tx][l,r]  tp>0:ans[tp]+=[0,tx][l,r]
	{
		int tp,l,r,tx;
		bool operator <(const query&b)
		{
			int ida,idb;
			if(tp)ida=tx;else ida=l;
			if(b.tp)idb=b.tx;else idb=b.l;
			if(ida!=idb)return ida<idb;
			return (!tp&&b.tp);
		}
	};
	query q[600111],tq[600111];
	int tot,ans[200111];
	twod_query_v2(){tot=0;memset(ans,0,sizeof(ans));}
	void addpoint(int x,int y,int v){q[++tot]=query{0,x,y,v};}
	void addquery(int x,int y,int xx,int yy,int id){q[++tot]=query{-id,y,yy,x-1};q[++tot]=query{id,y,yy,xx};}
	
	void solve(int l,int r)
	{
//		while(l<=r&&q[l].tp!=0)l++;
//		while(l<=r&&q[r].tp==0)r--;
		if(l>=r)return;
		int mid=(l+r)>>1;solve(l,mid);solve(mid+1,r);
		int ctot=0;
		for(int i=l;i<=mid;i++)if(!q[i].tp)tq[++ctot]=q[i];
		for(int i=mid+1;i<=r;i++)if(q[i].tp)tq[++ctot]=q[i];
		sort(tq+1,tq+ctot+1);
		BIT::timer++;
		for(int i=1;i<=ctot;i++)
		{
			if(tq[i].tp)
			{
				int v=BIT::query(tq[i].r)-BIT::query(tq[i].l-1);
				if(tq[i].tp<0)ans[-tq[i].tp]-=v;
				else ans[tq[i].tp]+=v;
			}
			else BIT::add(tq[i].r,tq[i].tx);
		}
	}
	void go()
	{
		memset(ans,0,sizeof(ans));
		solve(1,tot);
	}
}thor;

vector<int> g[maxn];
int n,dfn[maxn],edfn[maxn],fa[20][maxn],dep[maxn],seq[maxn],timer;
void dfs(int x,int f,int d)
{
	fa[0][x]=f;dep[x]=d;dfn[x]=++timer;seq[timer]=x;
	for(auto&v:g[x])if(v!=f)
		dfs(v,x,d+1);
	edfn[x]=timer;
}
int getlca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--)if(dep[x]-dep[y]>>i)x=fa[i][x];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
void prework()
{
	dfs(1,0,0);
	for(int i=1;i<20;i++)for(int j=1;j<=n;j++)fa[i][j]=fa[i-1][fa[i-1][j]];
}

int m,up[20][maxn];
pii cur[maxn];
int query(int&u,int v)
{
	int ret=0;
	for(int i=19;i>=0;i--)if(dep[up[i][u]]>dep[v])
	{
		ret|=1<<i;
		u=up[i][u];
	}
	return ret;
}

int q,ans[maxn];
bool check[maxn];

int main()
{
	get1(n);
	for(int i=2,f;i<=n;i++)
	{
		get1(f);
		g[f].pb(i);g[i].pb(f);
	}
	prework();
	get1(m);
	
	for(int i=1;i<=n;i++)cur[i]=mp(dep[i],i);
	for(int i=1,a,b,lca;i<=m;i++)
	{
		get2(a,b);if(dfn[a]>dfn[b])swap(a,b);
		lca=getlca(a,b);
		cur[a]=min(cur[a],mp(dep[lca],lca));
		cur[b]=min(cur[b],mp(dep[lca],lca));
		if(lca!=a)thor.addpoint(dfn[a],dfn[b],1);
	}
	for(int i=n;i>1;i--)cur[fa[0][seq[i]]]=min(cur[fa[0][seq[i]]],cur[seq[i]]);
	for(int i=1;i<=n;i++)up[0][i]=cur[i].ss;
	for(int i=1;i<20;i++)for(int j=1;j<=n;j++)up[i][j]=up[i-1][up[i-1][j]];
	
	get1(q);
	for(int i=1,a,b,lca;i<=q;i++)
	{
		get2(a,b);if(dfn[a]>dfn[b])swap(a,b);
		lca=getlca(a,b);
		ans[i]=query(a,lca)+query(b,lca)+1;
		if(ans[i]>n)ans[i]=-1;
		else if(lca!=a)
		{
			check[i]=1;
			thor.addquery(dfn[a],dfn[b],edfn[a],edfn[b],i);
		}
	}
	thor.go();
	for(int i=1;i<=q;i++)
	{
		if(check[i]&&!thor.ans[i])ans[i]++;
		printendl(ans[i]);
	}
	return 0;
}