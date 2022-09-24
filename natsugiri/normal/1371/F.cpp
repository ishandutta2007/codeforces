#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}


struct Seg {
    int len;
    int __L, __R, __LR, __RL;
    int L__, R__, LR__, RL__;
    int top, bottom;

    Seg() : len(0) {}

    Seg(char c) {
	len = 1;
	top = bottom = 1;
	__LR = __RL = 1;
	LR__ = RL__ = 1;
	if (c == '<') {
	    __L = L__ = 1;
	    __R = R__ = 0;
	} else if (c == '>') {
	    __L = L__ = 0;
	    __R = R__ = 1;
	} else {
	    len = 0;
	}
    }

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x;
    // TODO: do stuff something
    Seg z;
    z.len = x.len + y.len;
    z.__L = (x.__L == x.len? x.len + y.__L: x.__L);
    z.__R = (x.__R == x.len? x.len + y.__R: x.__R);

    z.__LR = x.__LR;
    if (x.__LR == x.len) amax(z.__LR, x.len + y.__R);
    if (x.__L == x.len) amax(z.__LR, x.len + y.__LR);

    z.__RL = x.__RL;
    if (x.__RL == x.len) amax(z.__RL, x.len + y.__L);
    if (x.__R == x.len) amax(z.__RL, x.len + y.__RL);

    z.L__ = (y.L__ == y.len? x.L__ + y.len: y.L__);
    z.R__ = (y.R__ == y.len? x.R__ + y.len: y.R__);

    z.LR__ = y.LR__;
    if (y.LR__ == y.len) amax(z.LR__, x.L__ + y.len);
    if (y.R__ == y.len) amax(z.LR__, x.LR__ + y.len);

    z.RL__ = y.RL__;
    if (y.RL__ == y.len) amax(z.RL__, x.R__ + y.len);
    if (y.L__ == y.len) amax(z.RL__, x.RL__ + y.len);

    z.top = max({x.top, y.top, x.LR__ + y.__R, x.L__ + y.__LR});
    z.bottom = max({x.bottom, y.bottom, x.RL__ + y.__L, x.R__ + y.__RL});
    return z;
};

struct Lazy {
    bool flip;
    Lazy() : flip(0) {}
    Lazy(bool flip_) : flip(flip_) {}

    Lazy& operator*=(const Lazy &y) {
	if (y.flip) flip = !flip;
	return *this;
    }

    static const Lazy IDENTITY;
};
const Lazy Lazy::IDENTITY = Lazy();

Seg operator*(Seg x, const Lazy &y) {
    if (y.flip) {
	swap(x.__L, x.__R);
	swap(x.L__, x.R__);
	swap(x.__LR, x.__RL);
	swap(x.LR__, x.RL__);
	swap(x.top, x.bottom);
    }
    return x;
}

struct SegTreeLazy {
    int m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegTreeLazy(int n=1) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    template<class Iter> SegTreeLazy(Iter begin, Iter end) {
	int n = end - begin;
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, Seg::IDENTITY);
	REP (i, n) d[i+m] = *(begin+i);
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
	lazy.assign(m*2, Lazy::IDENTITY);
    }

    void force_down(int x) {
	x += m;
	for (int i=__lg(x); i>=1; i--) {
	    int k = x >> i;
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    inline Seg eval(int k) {
	return d[k] * lazy[k];
    }

    Seg at(int x) {
	x += m;
	Seg s = d[x];
	for (; x; x>>=1) s = s * lazy[x];
	return s;
    }

    void modify(int x, const Seg &s) {
	force_down(x);
	x += m;
	d[x] = s;
	lazy[x] = Lazy::IDENTITY;
	for (x>>=1; x; x>>=1) d[x] = eval(x*2) + eval(x*2+1);
    }

    Seg query(int x, int y) {
	if (x >= y) return Seg::IDENTITY;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	x += m; y += m;
	Seg ls = Seg::IDENTITY, rs = Seg::IDENTITY;
	for (; x < y; x>>=1, y>>=1) {
	    if (y & 1) rs = eval(--y) + rs;
	    if (x & 1) ls = ls + eval(x++);
	}
	return ls + rs;
    }

    void add(const int x, const int y, const Lazy &v) {
	if (x >= y) return;
	force_down(x);
	if (x+1 < y) force_down(y-1);
	int x0 = x + m, y0 = y + m;
	for (; x0 < y0; x0>>=1, y0>>=1) {
	    if (y0 & 1) lazy[--y0] *= v;
	    if (x0 & 1) lazy[x0++] *= v;
	}
	for (x0=(x+m)>>1; x0; x0>>=1)
	    d[x0] = eval(x0*2) + eval(x0*2+1);
	if (x+1 < y)
	    for (y0=(y+m-1)>>1; y0; y0>>=1)
		d[y0] = eval(y0*2) + eval(y0*2+1);
    }

    inline void force(int k) {
	if (k < m) { // Lazy down
	    lazy[k*2] *= lazy[k];
	    lazy[k*2+1] *= lazy[k];
	    d[k] = eval(k*2) + eval(k*2+1);
	    lazy[k] = Lazy::IDENTITY;
	}
    }

    Seg query_template(int x, int y) { return query_template(x, y, 1, 0, m); }

    Seg query_template(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return Seg::IDENTITY;
	if (x<=l && r<=y) return eval(k);
	Seg left = query_template(x, y, k*2, l, (l+r)/2);
	Seg right = query_template(x, y, k*2+1, (l+r)/2, r);
	return left + right;
    }
};


int N, Q;
char S[500011];

void MAIN() {
    scanf("%d%d%s", &N, &Q, S);
    SegTreeLazy X(S, S+N);
    REP ($, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	X.add(l, r, Lazy(true));
	Seg s = X.query(l, r);
	printf("%d\n", s.bottom);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}