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

#ifdef LOCAL
const int SIZE = 8;
#else
const int SIZE = 1<<20;
#endif
const int INF = 1<<29;

struct Seg {
    int len;
    int mi, ma;
    Seg(): len(0), mi(INF), ma(-INF) {}
    Seg(int c): len(0), mi(c), ma(c) {}

    bool same() const {
	return mi == ma;
    }

} seg[SIZE*2];
const Seg IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    if (x.len == 0) return y;
    if (y.len == 0) return x;
    Seg z;
    z.len = x.len + y.len;
    z.mi = min(x.mi, y.mi);
    z.ma = max(x.ma, y.ma);
    return z;
}

struct Lazy {
    LL add;
    int color;

    Lazy(): add(0), color(0) {}

    Lazy& operator*=(const Lazy &y) {
	add += y.add;
	if (y.color) color = y.color;
	return *this;
    }
} lazy[SIZE*2];

Seg operator*(const Seg &x, const Lazy &y) {
    if (x.len == 0) return IDENTITY;
    Seg z;
    z.len = x.len;
    if (y.color) {
	z.mi = z.ma = y.color;
    } else {
	z.mi = x.mi;
	z.ma = x.ma;
    }
    return z;
}

void force(int k) {
    if (k < SIZE) {
	lazy[k*2] *= lazy[k];
	lazy[k*2+1] *= lazy[k];
	lazy[k] = Lazy();
    }
}
Seg eval(int k) {
    return seg[k] * lazy[k];
}

LL val[SIZE];
int LEFT, RIGHT, COLOR;
void add(int l, int r, int k) {
    if (r <= LEFT || RIGHT <= l) return;
    Seg s = eval(k);
    if (LEFT <= l && r <= RIGHT && s.same()) {
	lazy[k].add += val[s.mi] - val[COLOR];
	lazy[k].color = COLOR;
	return;
    }
    force(k);
    add(l, (l+r)/2, k*2);
    add((l+r)/2, r, k*2+1);
    seg[k] = eval(k*2) + eval(k*2+1);
}

LL find(int i) {
    int color = 1;
    LL ret = 0;
    i += SIZE;
    while (i) {
	ret += lazy[i].add;
	if (lazy[i].color != 0) color = lazy[i].color;
	i /= 2;
    }
    return ret + val[color];
}

int N;
int Q;

void MAIN() {
    scanf("%d%d", &N, &Q);

    REP (i, SIZE) {
	if (i < N) {
	    seg[SIZE+i].len = 1;
	    seg[SIZE+i].mi = 1;
	    seg[SIZE+i].ma = 1;
	} else {
	    seg[SIZE+i] = IDENTITY;
	}
    }
    for (int i=SIZE; --i; ) seg[i] = seg[i*2] + seg[i*2+1];

    REP ($, Q) {
	static char op[11];
	scanf("%s", op);
	if (*op == 'C') {
	    scanf("%d%d%d", &LEFT, &RIGHT, &COLOR);
	    LEFT--;
	    add(0, SIZE, 1);
	} else if (*op == 'A') {
	    int c, x;
	    scanf("%d%d", &c, &x);
	    val[c] += x;
	} else {
	    int i;
	    scanf("%d", &i);
	    i--;
	    LL ans = find(i);
	    printf("%lld\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}