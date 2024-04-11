#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
    int len;
    LL mi, ma;
    LL sum;
    Seg() : len(0), sum(-1) {}
    Seg(int v): len(1), mi(v), ma(v), sum(v)  {}

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x;
    Seg z;
    z.len = x.len + y.len;
    z.mi = min(x.mi, y.mi);
    z.ma = max(x.ma, y.ma);
    if (x.sum == -1 || y.sum == -1) z.sum = -1;
    else z.sum = x.sum + y.sum;
    return z;
};

struct Lazy {
    LL change;
    Lazy() : change(-1) {}
    Lazy(LL v) : change(v) {}

    Lazy& operator*=(const Lazy &y) {
	amax(change, y.change);
	return *this;
    }

    static const Lazy IDENTITY;
};
const Lazy Lazy::IDENTITY = Lazy();

Seg operator*(const Seg &x, const Lazy &y) {
    if (x.len == 0 || y.change <= x.mi) return x;
    Seg z = x;
    if (x.ma <= y.change) {
	z.mi = z.ma = y.change;
	z.sum = z.len * y.change;
    } else {
	amax(z.mi, y.change);
	z.sum = -1;
    }
    return z;
}

const int SIZE = 1<<18;
Seg seg[SIZE*2];
Lazy lazy[SIZE*2];

Seg eval(int k) {
    return seg[k] * lazy[k];
}

void force(int k) {
    if (k < SIZE) {
	lazy[k*2] *= lazy[k];
	lazy[k*2+1] *= lazy[k];
	seg[k] = eval(k*2) + eval(k*2+1);
	lazy[k] = Lazy::IDENTITY;
    } else {
	seg[k] = seg[k] * lazy[k];
    }
}

void add(int y, Lazy v, int l=0, int r=SIZE, int k=1) {
    if (y <= l) return;
    if (r <= y) {
	lazy[k] *= v;
	return;
    }
    add(y, v, l, (l+r)/2, k*2);
    add(y, v, (l+r)/2, r, k*2+1);
    seg[k] = eval(k*2) + eval(k*2+1);
}

LL V;
bool keep;
int find(int x, int y, int l=0, int r=SIZE, int k=1) {
    if (y <= l || r <= x) return 0;
    force(k);
    Seg s = eval(k);
    if (x <= l && r <= y) {
	if (s.sum != -1 && s.sum <= V) {
	    V -= s.sum;
	    return s.len;
	}
    }
    if (l + 1 == r) {
	return 0;
    }
    if (s.mi > V) {
	return 0;
    }

    int ret = find(x, y, l, (l+r)/2, k*2);
    ret += find(x, y, (l+r)/2, r, k*2+1);
    seg[k] = eval(k*2) + eval(k*2+1);
    return ret;
}


int N, Q;
int A[200011];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) seg[SIZE+i] = Seg(A[i]);
    for (int i=N; i<SIZE; i++) seg[SIZE+i] = Seg::IDENTITY;
    REP (i, SIZE*2) lazy[i] = Lazy::IDENTITY;

    for (int i=SIZE; --i;) seg[i] = seg[i*2] + seg[i*2+1];

    REP ($, Q) {
	int t, x, y;
	scanf("%d%d%d", &t, &x, &y);
	if (t == 1) {
	    add(x, Lazy(y));
	} else {
	    V = y;
	    keep = true;
	    int ans = find(x-1, N);
	    printf("%d\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}