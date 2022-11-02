#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)

struct Query {int x, t, *ans;};
struct Segment {int l, r, max, tid;};

const int N=2e5+1;

int n, m, p[N], prefer[N], size[N], dep[N], dfn[N], top[N], ans[N];
Query q[N];
Segment seg[1<<19];
std::vector<int> ch[N], dfo, tag;

template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}

void dfs_init(int x, int d) {
	int max=0;
	dep[x]=d;
	size[x]=1;
	for(int i: ch[x]) {
		dfs_init(i, d+1);
		if(cmax(max, size[i])) prefer[x]=i;
		size[x]+=size[i];
	}
}
void dfs_make(int x, int t) {
	top[x]=t;
	dfn[x]=dfo.size();
	dfo.push_back(x);
	if(prefer[x]) dfs_make(prefer[x], t);
	for(int i: ch[x]) if(i!=prefer[x]) dfs_make(i, i);
}

void build(int i, int l, int r) {
	seg[i]=(Segment){l, r, 0, -1};
	if(l!=r) {
		int mid=(l+r)/2;
		build(i<<1, l, mid);
		build(i<<1|1, mid+1, r);
	}
}
void do_cover(int i, int t) {
	if(cmax(seg[i].tid, t)) seg[i].max=tag[t]+2*dep[dfo[seg[i].r]];
}
void pushdown(int i) {
	if(seg[i].tid!=-1) {
		do_cover(i<<1, seg[i].tid);
		do_cover(i<<1|1, seg[i].tid);
		seg[i].tid=-1;
	}
}
int find_last_greater(int i, int qr, int qv) {
	if(qr<seg[i].l||seg[i].max<=qv) return -1;
	if(seg[i].l==seg[i].r) return seg[i].l;
	pushdown(i);
	int rans=find_last_greater(i<<1|1, qr, qv);
	return rans==-1?find_last_greater(i<<1, qr, qv):rans;
}
void cover(int i, int ql, int qr, int qv) {
	if(ql>seg[i].r||qr<seg[i].l) return;
	if(ql<=seg[i].l&&seg[i].r<=qr) return do_cover(i, qv);
	pushdown(i);
	cover(i<<1, ql, qr, qv);
	cover(i<<1|1, ql, qr, qv);
	seg[i].max=std::max(seg[i<<1].max, seg[i<<1|1].max);
}
int main() {
	int (*rd)()=read<int>;
	n=rd(), m=rd();
	for(int i=1; i<=n; ++i) ch[p[i]=rd()].push_back(i);
	dfs_init(0, 0);
	dfs_make(0, 0);
	for(int i=0; i<m; ++i) {
		int x=rd(), t=dep[x]+rd();
		q[i]=(Query){x, t, ans+i};
	}
	std::sort(q, q+m, [](const Query &a, const Query &b) {return a.t<b.t||a.t==b.t&&a.x<b.x;});
	build(1, 0, n);
	for(int i=0; i<m; ++i) {
		int x, v;
		for(x=q[i].x; x; x=p[top[x]]) {
			v=find_last_greater(1, dfn[x], q[i].t);
			if(v>=dfn[top[x]]) break;
		}
		if(x==0) v=0; else v=dfo[v];
		int vtick=q[i].t-dep[v];
		*q[i].ans=vtick+dep[q[i].x]-dep[v];
		for(x=q[i].x; top[x]!=top[v]; x=p[top[x]]) {
			tag.push_back(vtick-dep[v]);
			cover(1, dfn[top[x]], dfn[x], tag.size()-1);
		}
		if(v!=x) {
			tag.push_back(vtick-dep[v]);
			cover(1, dfn[v]+1, dfn[x], tag.size()-1);
		}
	}
	for(int i=0; i<m; ++i) printf("%d ", ans[i]);
	puts("");
	return 0;
}