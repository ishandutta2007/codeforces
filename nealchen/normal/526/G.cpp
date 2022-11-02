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

const int N=1e5+1;

struct Tree {
	int *pa, anc[17][N], dep[N], prefer[N], bot[N], top[N], len[N], nleaf, leaf[N], sum[N], *rank, min[17][N];
	int mea(int);
	void dec(int);
	void init(int);
	int query(int, int);
};
int n, lv, head[N], next[2*N], to[2*N], l[N], dis[N], queue[N];
Tree ta, tb;
int bfs(int u) {
	int *h=queue, *t=queue;
	memset(dis+1, -1, n*sizeof(int));
	dis[*t++=u]=0;
	while(h!=t) {
		u=*h++;
		for(int i=head[u]; i; i=next[i])
			if(dis[to[i]]==-1) dis[*t++=to[i]]=dis[u]+l[i/2];
	}
	for(int i=1, max=0; i<=n; ++i) if(cmax(max, dis[i])) u=i;
	return u;
}
int Tree::mea(int u) {
	int height=0;
	for(int i=head[u]; i; i=next[i])
		if(to[i]!=pa[u]) {
			pa[to[i]]=u;
			dep[to[i]]=dep[u]+l[i/2];
			if(cmax(height, mea(to[i])+l[i/2])) prefer[u]=to[i];
		}
	return height;
}
void Tree::dec(int u) {
	if(prefer[u]==0) {
		bot[u]=u;
		leaf[nleaf++]=u;
		len[u]=dep[u]-dep[pa[top[u]]];
	} else {
		top[prefer[u]]=top[u];
		dec(prefer[u]);
		bot[u]=bot[prefer[u]];
	}
	for(int i=head[u]; i; i=next[i])
		if(to[i]!=pa[u]&&to[i]!=prefer[u]) {
			top[to[i]]=to[i];
			dec(to[i]);
		}
}
void Tree::init(int r) {
	pa=anc[0];
	rank=min[0];
	pa[r]=r;
	mea(r);
	top[r]=r;
	dec(r);
	std::sort(leaf, leaf+nleaf, [this](int u, int v) {return len[u]>len[v];});
	for(int i=0; i<nleaf; ++i) {
		rank[leaf[i]]=i;
		sum[i+1]=sum[i]+len[leaf[i]];
	}
	for(int i=1; i<=n; ++i) rank[i]=rank[bot[i]];
	for(int i=1; i<=lv; ++i)
		for(int j=1; j<=n; ++j) {
			anc[i][j]=anc[i-1][anc[i-1][j]];
			min[i][j]=std::min(min[i-1][j], min[i-1][anc[i-1][j]]);
		}
}
int Tree::query(int x, int y) {
	y=2*y-1;
	if(rank[bot[x]]<y) return sum[std::min(nleaf, y)];
	int p=x;
	for(int i=lv; i>=0; --i) if(min[i][p]>=y) p=anc[i][p];
	return std::max(sum[y-1]+dep[bot[x]]-dep[p], sum[y]-dep[bot[p]]+dep[bot[x]]);
}
int main() {
	int q, a, b;
	n=rd(), q=rd();
	lv=31-__builtin_clz(n);
	for(int i=1, j=2; i<n; ++i) {
		int u=rd(), v=rd();
		l[i]=rd();
		to[j]=v, next[j]=head[u], head[u]=j++;
		to[j]=u, next[j]=head[v], head[v]=j++;
	}
	a=bfs(1);
	b=bfs(a);
	ta.init(a);
	tb.init(b);
	for(int ans=0; q--; ) {
		int x=(rd()+ans-1)%n+1, y=(rd()+ans-1)%n+1;
		ans=(ta.dep[x]>tb.dep[x]?ta:tb).query(x, y);
		printf("%d\n", ans);
	}
	return 0;
}