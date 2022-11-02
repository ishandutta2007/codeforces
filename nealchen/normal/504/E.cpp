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

struct SAM {
	int max;
	SAM *pa, *tr[26];
};
struct Frame {
	int v, side, len;
};
const int N=3e5+5;
int n, pa[N], dep[N], size[N], prefer[N], top[N], order[N], real[N], eul[4*N], st[22][8*N];
SAM pool[4*N], *root=pool, *mem=pool+1, *end[N], *beg[N];
char s[N];
std::vector<int> edge[N], child[4*N];
SAM *extend(SAM *p, int c) {
	if(p->tr[c]) {
		SAM *q=p->tr[c], *r;
		if(p->max+1==q->max) return q;
		r=mem++;
		*r=*q;
		r->max=p->max+1;
		q->pa=r;
		for(; p&&p->tr[c]==q; p=p->pa) p->tr[c]=r;
		return r;
	} else {
		SAM *i=mem++;
		i->max=p->max+1;
		for(; p&&p->tr[c]==NULL; p=p->pa) p->tr[c]=i;
		i->pa=p?extend(p, c):root;
		return i;
	}
}
void dfs1(int u) {
	int maxsize=0;
	size[u]=1;
	for(int v: edge[u])
		if(v!=pa[u]) {
			pa[v]=u;
			dep[v]=dep[u]+1;
			dfs1(v);
			size[u]+=size[v];
			if(cmax(maxsize, size[v])) prefer[u]=v;
		}
}
void dfs2(int u) {
	static int tot=0;
	SAM *head;
	std::vector<int> path;
	for(int i=u; i; i=prefer[i]) {
		top[i]=u;
		path.push_back(i);
		for(int v: edge[i]) if(v!=pa[i]&&v!=prefer[i]) dfs2(v);
	}
	for(int v: path) real[order[v]=++tot]=v;
	head=root;
	for(int v: path) end[v]=head=extend(head, s[v]-'a');
	std::reverse(path.begin(), path.end());
	head=root;
	for(int v: path) beg[v]=head=extend(head, s[v]-'a');
}
std::vector<Frame> extract(int u, int v) {
	std::vector<Frame> fir, las;
	while(top[u]!=top[v]) {
		if(dep[top[u]]>dep[top[v]]) {
			fir.push_back({u, -1, dep[u]-dep[top[u]]+1});
			u=pa[top[u]];
		} else {
			las.push_back({top[v], 1, dep[v]-dep[top[v]]+1});
			v=pa[top[v]];
		}
	}
	if(dep[u]>=dep[v]) {
		fir.push_back({u, -1, dep[u]-dep[v]+1});
	} else {
		las.push_back({u, 1, dep[v]-dep[u]+1});
	}
	for(; !las.empty(); las.pop_back()) fir.push_back(las.back());
	return fir;
}
void dfs3(int u) {
	static int eu_n=0;
	st[0][eul[u]=++eu_n]=pool[u].max;
	for(int v: child[u]) {
		dfs3(v);
		st[0][++eu_n]=pool[u].max;
	}
}
int lca_max(int u, int v) {
	u=eul[u], v=eul[v];
	if(u>v) std::swap(u, v);
	++v;
	int lv=31-__builtin_clz(v-u);
	return std::min(st[lv][u], st[lv][v-(1<<lv)]);
}
int main() {
	assert(scanf("%d%s", &n, s+1)==2);
	for(int i=1; i<n; ++i) {
		int u=rd(), v=rd();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs1(1);
	dfs2(1);
	int tot=mem-pool;
	for(int i=1; i<tot; ++i) child[pool[i].pa-pool].push_back(i);
	dfs3(0);
	for(int i=1; 1<<i<2*tot; ++i)
		for(int j=1; (1<<i)+j<=2*tot; ++j)
			st[i][j]=std::min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
	int m=rd();
	while(m--) {
		int a=rd(), b=rd(), c=rd(), d=rd(), i, j, ans=0;
		auto p=extract(a, b), q=extract(c, d);
		for(i=j=0; i<p.size()&&j<q.size(); ) {
			int len=lca_max(p[i].v[p[i].side==1?beg:end]-pool, q[j].v[q[j].side==1?beg:end]-pool);
			cmin(len, std::min(p[i].len, q[j].len));
			p[i].len-=len, q[j].len-=len, ans+=len;
			if(p[i].len>0&&q[j].len>0) break;
			if(p[i].len==0) ++i; else p[i].v=real[order[p[i].v]+p[i].side*len];
			if(q[j].len==0) ++j; else q[j].v=real[order[q[j].v]+q[j].side*len];
		}
		printf("%d\n", ans);
	}
	return 0;
}