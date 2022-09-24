#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

struct Seg {
    int m[3][3];
    Seg() {
	memset(m, 0x3f, sizeof m);
	REP (t, 3) m[t][t] = 0;
    }

    Seg(char c) { 
	memset(m, 0x3f, sizeof m);
	m[0][0] = 0;
	m[1][1] = 0;
	m[2][2] = 0;
	if (c == 'a') {
	    m[0][1] = 0;
	    m[0][0] = 1;
	}
	if (c == 'b') {
	    m[1][2] = 0;
	    m[1][1] = 1;
	}
	if (c == 'c') {
	    m[2][2] = 1;
	}
    }

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    memset(z.m, 0x3f, sizeof z.m);
    REP (a, 3) for (int b=a; b<3; b++) for (int c=b; c<3; c++) {
	amin(z.m[a][c], x.m[a][b] + y.m[b][c]);
    }

    return z;
};

struct SegTree {
    int m; // m = 2^k >= n;
    vector<Seg> d;

    SegTree() {}

    SegTree(int n) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
    }

    template<class T> SegTree(const vector<T> &a) {
	int n = a.size();
        if (n < 2) m = 1;
        else m = 2 << __lg(n-1);
        d.assign(m*2, Seg::IDENTITY);
        REP (i, n) d[i+m] = Seg(a[i]);
        build();
    }

    template<class Iter> SegTree(Iter begin, Iter end) {
	int n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	REP (i, n) d[i+m] = Seg(*(begin+i));
	build();
    }

    // INIT := T initializer(int);
    template<class INIT> SegTree(int n, INIT initializer) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	REP (i, n) d[i+m] = initializer(i);
	build();
    }

    void build() {
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
    }

    Seg at(int x) const {
	return d[x+m];
    }

    void modify(int x, const Seg &s) {
	x += m;
	d[x] = s;
	for (x>>=1; x; x>>=1) d[x] = d[x*2] + d[x*2+1];
    }

    Seg query(int x, int y) const {
	Seg ls = Seg::IDENTITY, rs = Seg::IDENTITY;
	for (x+=m, y+=m; x<y; x>>=1, y>>=1) {
	    if (x&1) { ls = ls + d[x]; x++; }
	    if (y&1) { y--; rs = d[y] + rs; }
	}
	return ls + rs;
    }

    Seg query2(int x, int y) const { return query2(x, y, 1, 0, m); }

    Seg query2(int x, int y, int k, int l, int r) const {
	assert(x < r || l < y); // Has intersection;
	if (x<=l && r<=y) return d[k];
	int mid = (l+r)/2;
	if (y <= mid) return query2(x, y, k*2, l, mid);
	if (mid <= x) return query2(x, y, k*2+1, mid, r);
	return query2(x, y, k*2, l, mid) + query2(x, y, k*2+1, mid, r);
    }

    // VALID := bool valid(Seg);
    // find shortest valid range [l, ret);
    // otherwise ret = -1;
    template<class VALID> int find_first(int l, VALID valid) {
	if (valid(Seg::IDENTITY)) return l;
	Seg ls = Seg::IDENTITY, tmp;
	l += m;
	for (int r=m*2; l<r; l>>=1, r>>=1) {
	    if (l&1) {
		tmp = ls + d[l];
		if (valid(tmp)) {
		    while (l < m) {
			tmp = ls + d[l*2];
			if (valid(tmp)) l = l*2;
			else { ls = tmp; l = l*2+1; }
		    }
		    return l-m+1;
		}
		ls = tmp; l++;
	    }
	}
	return -1; // not found;
    }

    // VALID := bool valid(Seg);
    // find shortest valid range [ret, r);
    // otherwise ret = -1;
    template<class VALID> int find_last(int r, VALID valid) {
	if (valid(Seg::IDENTITY)) return r;
	Seg rs = Seg::IDENTITY, tmp;
	r += m;
	for (int l=m; l<r; l>>=1, r>>=1) {
	    if (r&1) {
		tmp = d[--r] + rs;
		if (valid(tmp)) {
		    while (r < m) {
			tmp = d[r*2+1] + rs;
			if (valid(tmp)) r = r*2+1;
			else { rs = tmp; r = r*2; }
		    }
		    return r-m;
		}
		rs = tmp;
	    }
	}
	return -1; // not found;
    }
};

int N, Q;
char S[100011];

void MAIN() {
    scanf("%d%d%s", &N, &Q, S);

    SegTree tree(S, S+N);

    REP ($, Q) {
	int pos;
	char c[11];
	scanf("%d%s", &pos, c);
	pos--;

	tree.modify(pos, Seg(c[0]));

	Seg s = tree.query(0, N);
	int ans = N;
	REP (a, 3) amin(ans, s.m[0][a]);
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}