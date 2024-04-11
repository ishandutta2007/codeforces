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
	SAM *tr[26], *pa;
};
const int N=5e5+10;
int n, q, tot, pa[N], off, tree[1<<20], ans[N], l[N], r[N];
char s[N];
SAM root[N], *end[N];
std::vector<int> on[N], child[N], query[N];
SAM *extend(SAM *p, int c) {
	if(p->tr[c]) {
		SAM *q=p->tr[c], *r;
		if(q->max==p->max+1) return q;
		r=root+(++tot);
		*r=*q;
		r->max=p->max+1;
		q->pa=r;
		for(; p&&p->tr[c]==q; p=p->pa) p->tr[c]=r;
		return r;
	} else {
		SAM *i=root+(++tot);
		i->max=p->max+1;
		for(; p&&p->tr[c]==NULL; p=p->pa) p->tr[c]=i;
		i->pa=p?extend(p, c):root;
		return i;
	}
}
void insert(int x) {
	for(x|=off; x; x/=2) ++tree[x];
}
int sum(int l, int r) {
	int ans=0;
	for(l+=off-1, r+=off+1; l^r^1; l/=2, r/=2) {
		if(~l&1) ans+=tree[l+1];
		if( r&1) ans+=tree[r-1];
	}
	return ans;
}
void dfs(int u) {
	for(int i: query[u]) ans[i]-=sum(l[i], r[i]);
	for(int i: on[u]) insert(i);
	for(int v: child[u]) dfs(v);
	for(int i: query[u]) ans[i]+=sum(l[i], r[i]);
}
int main() {
	n=rd(), q=rd();
	for(int i=1; i<=n; ++i) {
		end[i]=root;
		assert(scanf("%s", s)==1);
		for(int j=0; s[j]; ++j) {
			end[i]=extend(end[i], s[j]-'a');
			on[end[i]-root].push_back(i);
		}
	}
	for(int i=1; i<=tot; ++i) {
		pa[i]=root[i].pa-root;
		child[pa[i]].push_back(i);
	}
	for(int i=0; i<q; ++i) {
		l[i]=rd();
		r[i]=rd();
		query[end[rd()]-root].push_back(i);
	}
	for(off=1; off<n+2; off*=2);
	dfs(0);
	for(int i=0; i<q; ++i) printf("%d\n", ans[i]);
	return 0;
}