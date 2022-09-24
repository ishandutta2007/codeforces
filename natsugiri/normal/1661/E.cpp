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

int idx;
struct Seg {
    int cnt;
    int left[3], right[3];
    Seg() {
	cnt = -1;
    }

    Seg(const string &s) {
	cnt = 0;
	REP (i, 3) left[i] = right[i] = -1;

	REP (i, 3) if (s[i] == '1') {
	    left[i] = right[i] = ++idx;
	    cnt++;
	}

	REP (i, 2) {
	    if (s[i] == '1' && s[i+1] == '1') {
		left[i+1] = right[i+1] = left[i];
		cnt--;
	    }
	}
    }

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

void rewrite(int &v, int from, int to) {
    if (v == from) v = to;
}

Seg operator+(const Seg &x, const Seg &y) {
    if (x.cnt == -1) return y;
    if (y.cnt == -1) return x;
    Seg z;
    Seg cpyX = x, cpyY = y;

    z.cnt = x.cnt + y.cnt;

    REP (i, 3) {
	if (cpyX.right[i] != -1 && cpyY.left[i] != -1 && cpyX.right[i] != cpyY.left[i]) {
	    int from = cpyY.left[i];
	    int to = cpyX.right[i];
	    REP (j, 3) {
		rewrite(cpyX.left[j], from, to);
		rewrite(cpyX.right[j], from, to);
		rewrite(cpyY.left[j], from, to);
		rewrite(cpyY.right[j], from, to);
	    }
	    z.cnt--;
	}
    }

    REP (i, 3) {
	z.left[i] = cpyX.left[i];
	z.right[i] = cpyY.right[i];
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

};


int N;
char buf[500011];
string S[500011];

void MAIN() {
    scanf("%d", &N);
    REP (i, 3) {
	scanf("%s", buf);
	REP (j, N) S[j].push_back(buf[j]);
    }

    SegTree tree(S, S+N);

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	Seg s = tree.query(l, r);
	printf("%d\n", s.cnt);
//	rprintf("%d", s.left, s.left + 3);
//	rprintf("%d", s.right, s.right + 3);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}