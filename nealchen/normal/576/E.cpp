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
const int N=5e5+1;
int n, m, k, q, a[N], b[N], color[N], last[N], e[N], c[N], pa[51][N], w[51][N], size[51][N];
std::vector<int> mod[1<<20];
std::vector<std::pair<int*, int>> history;
void mark(int o, int l, int r, int ql, int qr) {
	if(ql>r||qr<l) return;
	if(ql<=l&&qr>=r) return mod[o].push_back(ql-1);
	int mid=(l+r)/2;
	mark(o*2, l, mid, ql, qr);
	mark(o*2+1, mid+1, r, ql, qr);
}
void modify(int *p, int v) {
	history.emplace_back(p, *p);
	*p=v;
}
std::pair<int, int> find(int id, int x) {
	int re=0;
	for(; pa[id][x]!=x; x=pa[id][x]) re^=w[id][x];
	return {x, re};
}
void solve(int o, int l, int r) {
	int save=history.size();
	for(int i: mod[o]) if(c[i]) {
		std::pair<int, int> x=find(c[i], a[e[i]]), y=find(c[i], b[e[i]]);
		if(x.first==y.first) continue;
		if(size[c[i]][x.first]>size[c[i]][y.first]) std::swap(x, y);
		modify(pa[c[i]]+x.first, y.first);
		modify(w[c[i]]+x.first, x.second^y.second^1);
		modify(size[c[i]]+y.first, size[c[i]][x.first]+size[c[i]][y.first]);
	}
	if(l==r) {
		std::pair<int, int> x=find(c[l], a[e[l]]), y=find(c[l], b[e[l]]);
		if(x==y) {
			puts("NO");
			c[l]=color[e[l]];
		} else {
			puts("YES");
			color[e[l]]=c[l];
		}
	} else {
		int mid=(l+r)/2;
		solve(o*2, l, mid);
		solve(o*2+1, mid+1, r);
	}
	while(save!=history.size()) {
		auto p=history.back();
		history.pop_back();
		*p.first=p.second;
	}
}
int main() {
	n=rd(), m=rd(), k=rd(), q=rd();
	for(int i=1; i<=m; ++i) a[i]=rd(), b[i]=rd();
	for(int i=0; i<q; ++i) {
		e[i]=rd(), c[i]=rd();
		if(last[e[i]]) mark(1, 0, q-1, last[e[i]], i);
		last[e[i]]=i+1;
	}
	for(int i=1; i<=m; ++i) if(last[i]) mark(1, 0, q-1, last[i], q-1);
	for(int i=1; i<=k; ++i)
		for(int j=1; j<=n; ++j) {
			pa[i][j]=j;
			size[i][j]=1;
		}
	solve(1, 0, q-1);
	return 0;
}