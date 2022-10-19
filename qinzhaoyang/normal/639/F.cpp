#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
//#include <unordered_set>
//#include <unordered_map>
//#include <bits/stdc++.h>

#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define SIZE(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define fi first
#define se second

using namespace std;

template<typename T>inline bool upmin(T &x,T y) { return y<x?x=y,1:0; }
template<typename T>inline bool upmax(T &x,T y) { return x<y?x=y,1:0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;

const lod eps=1e-11;
const lod pi=acos(-1);
const int oo=1<<30;
const ll loo=1ll<<62;
const int mods=998244353;
const int MAXN=600005;
const int INF=0x3f3f3f3f;//1061109567
/*--------------------------------------------------------------------*/
inline int read()
{
	int f=1,x=0; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') f=-1; c=getchar(); }
	while (c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
	return x*f;
}
PR _E[MAXN],ex[MAXN];
vector<int> E[MAXN];
int nn,R=0,edgenum=1,head[MAXN],dfn[MAXN],low[MAXN],instk[MAXN],a[MAXN],b[MAXN],idnum,num,top;
int col[MAXN],colnum,DFN,_Enum,Dfn[MAXN],dep[MAXN],fa[MAXN][20],Log[MAXN],vis[MAXN],stk[MAXN],id[MAXN],N,M,n,m,Case;
struct enode{ int to,nxt; } e[MAXN];

int rotate(int element)
{
	element=(element+R)%nn;
	if (!element) element=nn;
	return element;
}
void add(int u,int v) { /*cout<<u<<"->"<<v<<endl;*/ e[++edgenum]=(enode){v,head[u]},head[u]=edgenum; }
void tarjan(int x,int lst)
{
	instk[x]=1,dfn[x]=low[x]=++DFN;
	for (int i=head[x];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if (i==lst||i==(lst^1)) continue;
//		cout<<x<<" "<<v<<endl;
		if (!dfn[v]) tarjan(v,i),upmin(low[x],low[v]);
		else if (instk[v]) upmin(low[x],dfn[v]);
	}
	for (int i=head[x];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if (i==lst||i==(lst^1)) continue;
		if (low[v]<=dfn[x]) E[x].PB(v),E[v].PB(x);
		else _E[++_Enum]=MP(x,v);
	}
	instk[x]=0;
//	cout<<x<<" "<<dfn[x]<<" "<<low[x]<<endl;
}
void dfs(int x)
{
	col[x]=colnum;
	for (auto v:E[x]) if (!col[v]) dfs(v);
}
void dfs1(int x,int father)
{
	Dfn[x]=++DFN,dep[x]=dep[father]+1,fa[x][0]=father;
	for (int i=1;i<=Log[dep[x]];i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=head[x];i;i=e[i].nxt) if (!Dfn[e[i].to]) dfs1(e[i].to,x);
}
int getlca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=Log[dep[x]];i>=0;i--)
		if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=Log[dep[x]];i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}


void Add(int u,int v) { add(u,v),add(v,u); }
void DFS(int x)
{
	vis[x]=1;
	for (auto v:E[x]) if (!vis[v]) DFS(v);
}
void solve(int T)
{
	for (int i=1;i<=M;i++) Add(ex[i].fi,ex[i].se);
	_Enum=DFN=0,tarjan(a[1],0),DFS(a[1]);
	
	int flag=1;
	for (int i=1;i<=N;i++) if (!vis[a[i]]) flag=0;
	puts(flag?"YES":"NO");
	if (flag) R=(R+T)%nn;
	edgenum=1;
	for (int i=1;i<=idnum;i++) head[id[i]]=vis[id[i]]=low[id[i]]=dfn[id[i]]=0,E[id[i]].clear();
}
void build()
{
	top=0,idnum=0;
	for (int i=1;i<=num;i++)
	{
		if (!top) { stk[top=1]=b[i],id[++idnum]=b[i]; continue; }
		int lca=getlca(stk[top],b[i]);
		if (!lca) 
		{ 
			while (top>1) Add(stk[top-1],stk[top]),top--;
			stk[top=1]=b[i],id[++idnum]=b[i]; 
			continue; 
		}
		while (top>1&&dep[stk[top-1]]>dep[lca]) Add(stk[top-1],stk[top]),top--;
		if (dep[stk[top]]>dep[lca]) Add(lca,stk[top--]);
		if (stk[top]!=lca) stk[++top]=lca,id[++idnum]=lca;
		stk[++top]=b[i],id[++idnum]=b[i];
	}
	while (top>1) Add(stk[top-1],stk[top]),top--;
}
signed main()
{
	nn=n=read(),m=read(),Case=read();
	for (int i=1;i<=m;i++) 
	{
		int u=read(),v=read();
		if (u!=v) Add(u,v);
	}
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i,0);
	for (int i=1;i<=n;i++) if (!col[i]) colnum++,dfs(i);

	edgenum=1;
	for (int i=1;i<=n;i++) head[i]=0;
	for (int i=1;i<=_Enum;i++) Add(col[_E[i].fi],col[_E[i].se]);
	n=colnum,dep[0]=-1,Log[1]=0,DFN=0;
	for (int i=2;i<=n;i++) Log[i]=Log[i>>1]+1;
	for (int i=1;i<=n;i++) if (!Dfn[i]) dfs1(i,0);

	edgenum=1;
	for (int i=1;i<=n;i++) head[i]=dfn[i]=low[i]=0,E[i].clear();
	for (int T=1;T<=Case;T++)
	{
		N=read(),M=read(),num=N;
		for (int i=1;i<=N;i++) a[i]=rotate(read());
		for (int i=1;i<=M;i++) ex[i].fi=rotate(read()),ex[i].se=rotate(read());
		for (int i=1;i<=N;i++) a[i]=b[i]=col[a[i]];
		for (int i=1;i<=M;i++) ex[i]=MP(col[ex[i].fi],col[ex[i].se]),b[++num]=ex[i].fi,b[++num]=ex[i].se;
		sort(a+1,a+N+1,[&](int x,int y){ return Dfn[x]<Dfn[y]; }),N=unique(a+1,a+N+1)-a-1;
		sort(b+1,b+num+1,[&](int x,int y){ return Dfn[x]<Dfn[y]; }),num=unique(b+1,b+num+1)-b-1;
		build(),solve(T);
	}
	return 0;
}