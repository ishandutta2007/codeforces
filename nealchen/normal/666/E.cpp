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
struct Segment {
	std::pair<int, int> max;
	Segment *ch[2];
};
const int N=5e5+5, M=5e4+5, T=11e5+5;
int n, m, anc[21][T], *pa=anc[0];
char s[N], t[M];
SAM root[T], *mem=root+1, *pos[N];
Segment pool[35*M], *tot=pool, *seg[T];
std::vector<int> child[T];
SAM *extend(SAM *p, int c) {
	if(p->tr[c]) {
		SAM *q=p->tr[c], *r;
		if(q->max==p->max+1) return q;
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
Segment *make(int l, int r, int pos) {
	Segment *p=tot++;
	*p=(Segment){{1, pos}};
	if(l!=r) {
		int mid=(l+r)/2;
		if(pos<=mid)
			p->ch[0]=make(l, mid, pos);
		else
			p->ch[1]=make(mid+1, r, pos);
	}
	return p;
}
Segment *merge(Segment *p, Segment *q, int l, int r) {
	if(p==NULL) return q;
	if(q==NULL) return p;
	Segment *o=tot++;
	if(l!=r) {
		int mid=(l+r)/2;
		o->ch[0]=merge(p->ch[0], q->ch[0], l, mid);
		o->ch[1]=merge(p->ch[1], q->ch[1], mid+1, r);
		std::pair<int, int> resl, resr;
		if(o->ch[0]) resl=o->ch[0]->max;
		if(o->ch[1]) resr=o->ch[1]->max;
		o->max=resl.first>=resr.first?resl:resr;
	} else {
		*o=(Segment){{p->max.first+q->max.first, l}};
	}
	return o;
}
std::pair<int, int> query_max(Segment *p, int l, int r, int ql, int qr) {
	if(p==NULL||ql>r||qr<l) return {0, 0};
	if(ql<=l&&qr>=r) return p->max;
	int mid=(l+r)/2;
	auto resl=query_max(p->ch[0], l, mid, ql, qr), resr=query_max(p->ch[1], mid+1, r, ql, qr);
	return resl.first>=resr.first?resl:resr;
}
void dfs(int u) {
	for(int v: child[u]) {
		dfs(v);
		seg[u]=merge(seg[u], seg[v], 1, m);
	}
}
int main() {
	assert(scanf("%s%d", s+1, &m)==2);
	n=strlen(s+1);
	pos[0]=root;
	for(int i=1; i<=n; ++i) pos[i]=extend(pos[i-1], s[i]-'a');
	for(int i=1; i<=m; ++i) {
		SAM *cur=root;
		assert(scanf("%s", t)==1);
		for(int j=0; t[j]; ++j) {
			cur=extend(cur, t[j]-'a');
			int id=cur-root;
			seg[id]=merge(seg[id], make(1, m, i), 1, m);
		}
	}
	int size=mem-root, maxlevel=31-__builtin_clz(size);
	for(int i=1; i<size; ++i) {
		pa[i]=root[i].pa-root;
		child[pa[i]].push_back(i);
	}
	dfs(0);
	for(int i=1; i<=maxlevel; ++i)
		for(int j=0; j<size; ++j) anc[i][j]=anc[i-1][anc[i-1][j]];
	for(int q=rd(); q--; ) {
		int l=rd(), r=rd(), pl=rd(), pr=rd();
		pl=pr-pl+1;
		pr=pos[pr]-root;
		for(int i=maxlevel; i>=0; --i)
			if(root[anc[i][pr]].max>=pl) pr=anc[i][pr];
		auto res=query_max(seg[pr], 1, m, l, r);
		printf("%d %d\n", std::max(res.second, l), res.first);
	}
	return 0;
}