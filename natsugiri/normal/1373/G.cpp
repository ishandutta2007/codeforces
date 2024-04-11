#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

//////////////////////////////////////////////////
// Segment Tree
//////////////////////////////////////////////////
struct Seg {
    int mi;
    int all;
    Seg() : mi(1<<29), all(0) {}
    Seg(int val_): mi(min(0, val_)), all(val_) {
    }

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    // TODO: do stuff something
    Seg z;
    z.all = x.all + y.all;
    z.mi = min(y.mi, x.mi + y.all);
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
};

int N, M, K;

void MAIN() {
    scanf("%d%d%d", &N, &K, &M);

    const int SIZE = 410000;
    SegTree X(SIZE, [](int i) {
	    return Seg(1);
	    });

    multiset<LL> se;
    multiset<int> rows;
    REP ($, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	int row = y + abs(x - K);

	LL key = ((LL)x<<32) | y;
	auto it = se.lower_bound(key);
	Seg seg = X.at(row);
	if (it != se.end() && *it == key) {
	    X.modify(row, Seg(seg.all + 1));
	    se.erase(it);
	    rows.erase(rows.find(row));
	} else {
	    X.modify(row, Seg(seg.all - 1));
	    se.insert(it, key);
	    rows.insert(row);
	}

	int ans = 0;
	if (se.empty()) {
	    ans = 0;
	} else {
	    int ma = *rows.rbegin();
	    Seg s = X.query(0, ma+1);
	    ans = max({0, ma - N, ma - s.mi - N});
	}

	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}