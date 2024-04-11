#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;

const int N=3e5+5;
int n, m, pa[N], dep[N], deg[N], dfs_n, dfn[N], dfr[N], dest[N], c[N], delta[N], l[N], r[N], root[N], bit[N];
bool vis[N];
std::vector<int> e[N];
void dfs(int u) {
	dfn[u]=++dfs_n;
	for(int v: e[u]) if(v!=pa[u]) {
		pa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
	}
	dfr[u]=dfs_n;
}
void mark(int u, int d) {
	if(u!=0) {
		c[u]+=d;
		delta[u]+=d;
	}
}
void pushdown(int u) {
	mark(l[u], delta[u]);
	mark(r[u], delta[u]);
	delta[u]=0;
}
int merge(int x, int y) {
	if(x==0||y==0) return x+y;
	if(c[x]>c[y]) std::swap(x, y);
	pushdown(x);
	l[x]=merge(l[x], y);
	std::swap(l[x], r[x]);
	return x;
}
int pop(int x) {
	pushdown(x);
	return merge(l[x], r[x]);
}
int partial_sum(int x) {
	int ans=0;
	for(; x; x&=x-1) ans+=bit[x];
	return ans;
}
void increase(int x, int v) {
	for(; x<=n; x+=x&-x) bit[x]+=v;
}
int main() {
	s64 ans=0;
	std::queue<int> q;
	n=rd(), m=rd();
	for(int i=1, j=2; i<n; ++i) {
		int u=rd(), v=rd();
		e[u].push_back(v);
		e[v].push_back(u);
		++deg[u];
		++deg[v];
	}
	for(int i=1; i<=m; ++i) {
		int u=rd();
		dest[i]=rd();
		c[i]=rd();
		root[u]=merge(root[u], i);
	}
	dfs(1);
	for(int i=2; i<=n; ++i) if(deg[i]==1) q.push(i);
	while(!q.empty()) {
		int u=q.front(), v, w;
		q.pop();
		vis[u]=true;
		for(v=0; vis[e[u][v]]; ++v);
		v=e[u][v];
		if(--deg[v]==1&&v!=1) q.push(v);
		if(partial_sum(dfr[u])>partial_sum(dfn[u]-1)) {
			root[v]=merge(root[v], root[u]);
			continue;
		}
		while(root[u]&&dep[dest[root[u]]]>=dep[u]) root[u]=pop(root[u]);
		if(root[u]==0) {
			puts("-1");
			return 0;
		}
		v=dest[root[u]];
		ans+=w=c[root[u]];
		root[u]=pop(root[u]);
		mark(root[u], -w);
		root[v]=merge(root[v], root[u]);
		increase(dfn[u], 1);
		increase(dfn[v], -1);
	}
	printf("%lld\n", ans);
	return 0;
}