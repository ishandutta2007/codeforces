#include <map>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <functional>
#define meow(args...) fprintf(stderr, args)
const int N=2e5+1;
int n, q;
int head[N], next[N<<1], to[N<<1];
int deg[N], fa[N], dep[N], siz[N], prefer[N], top[N], dfcnt, dfn[N], dfo[N];
int max, mdfmark, begin[N<<1], col[N], bit[N<<1];
std::priority_queue< int, std::vector<int>, std::greater<int> > heap;
std::map<int, int> colmap[N<<1], global;
template<class Type> bool cmax(Type &a, const Type &b) {return a<b?(a=b, 1):0;}
void dfs1(int x, int f, int d)
{
	int maxsiz=0;
	fa[x]=f;
	dep[x]=d;
	siz[x]=1;
	for(int i=head[x]; i; i=next[i])
		if(to[i]!=f) {
			dfs1(to[i], x, d+1);
			siz[x]+=siz[to[i]];
			if(cmax(maxsiz, siz[to[i]])) prefer[x]=to[i];
		}
}
void dfs2(int x, int t)
{
	top[x]=t;
	dfo[dfn[x]=++dfcnt]=x;
	if(prefer[x]) dfs2(prefer[x], t);
	for(int i=head[x]; i; i=next[i]) if(to[i]!=fa[x] && to[i]!=prefer[x]) dfs2(to[i], to[i]);
}
int lca(int x, int y)
{
	while(top[x]!=top[y]) dep[top[x]]<dep[top[y]]?(y=fa[top[y]]):(x=fa[top[x]]);
	return dep[x]<dep[y]?x:y;
}
void inc(int x, int v)
{
	for(; x<=n+q; x+=x&-x) bit[x]+=v;
}
int sum(int x)
{
	int ans=0;
	for(; x; x&=x-1) ans+=bit[x];
	return ans;
}
void place(int l, int r, int c)
{
	col[l]=c;
	global.emplace(l, r);
	colmap[c].emplace(l, r);
	inc(c, r-l+1);
}
void erase(int l, int r)
{
	global.erase(l);
	colmap[col[l]].erase(l);
	inc(col[l], l-r-1);
}
void split(int x)
{
	auto it=global.upper_bound(x);
	if(it==global.begin()) return;
	--it;
	int l=it->first, r=it->second, c=col[l];
	if(l==x) return;
	erase(l, r);
	place(l, x-1, c);
	place(x, r, c);
}
void paint(int l, int r, int c)
{
	split(l);
	split(r+1);
	auto it=global.lower_bound(l);
	while(it!=global.end() && it->second<=r) {
		int ll=it->first, rr=it->second;
		++it;
		erase(ll, rr);
	}
	place(l, r, c);
}
void up(int x)
{
	int y=max;
	max=x;
	begin[++mdfmark]=y;
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) {
			paint(dfn[top[y]], dfn[y], mdfmark);
			y=fa[top[y]];
		} else {
			paint(dfn[top[x]], dfn[x], mdfmark);
			x=fa[top[x]];
		}
	}
	if(dep[x]<dep[y]) paint(dfn[x], dfn[y], mdfmark); else paint(dfn[y], dfn[x], mdfmark);
}
int when(int x)
{
	int c;
	auto it=global.upper_bound(dfn[x]);
	--it;
	c=col[it->first];
	return dep[x]+dep[begin[c]]-2*dep[lca(x, begin[c])]+1+sum(c-1);
}
int main()
{
	std::greater<int> cmp;
	scanf("%d%d", &n, &q);
	for(int i=1, j=2; i<n; ++i) {
		int v, u;
		scanf("%d%d", &v, &u);
		next[j]=head[u], to[j]=v, head[u]=j++;
		next[j]=head[v], to[j]=u, head[v]=j++;
		++deg[u], ++deg[v];
	}
	dfs1(1, 0, 0);
	dfs2(1, 1);
	for(int i=1; i<=n; ++i) if(deg[i]==1) heap.push(i);
	while(!heap.empty()) {
		int x=heap.top();
		heap.pop();
		place(dfn[x], dfn[x], ++mdfmark);
		begin[mdfmark]=x;
		for(int i=head[x]; i; i=next[i]) if(--deg[to[i]]==1) heap.push(to[i]);
	}
	max=n;
	for(int i=0; i<q; ++i) {
		char s[8];
		int u, v;
		scanf("%s%d", s, &u);
		if(s[0]=='u') up(u);
		if(s[0]=='w') printf("%d\n", when(u));
		if(s[0]=='c') {
			scanf("%d", &v);
			printf("%d\n", when(u)<when(v)?u:v);
		}
	}
	return 0;
}