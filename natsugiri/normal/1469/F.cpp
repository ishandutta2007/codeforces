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
    LL sum;
    int len;
    Seg() : sum(0), len(0) {}
    Seg(LL val_): sum(val_), len(1) {}

    static const Seg IDENTITY;
};
const Seg Seg::IDENTITY = Seg();

Seg operator+(const Seg &x, const Seg &y) {
    //if (x.len == 0) return y;
    //if (y.len == 0) return x;
    Seg z;
    z.sum = x.sum + y.sum;
    z.len = x.len + y.len;
    return z;
};

const LL INVALID = 1LL<<60;
struct Lazy {
    LL add;
    Lazy() : add(0) {}
    Lazy(LL val_) : add(val_) {}

    Lazy& operator*=(const Lazy &y) {
	add += y.add;
	return *this;
    }

    static const Lazy IDENTITY;
};
const Lazy Lazy::IDENTITY = Lazy();

Seg operator*(const Seg &x, const Lazy &y) {
    if (x.len == 0 || y.add == 0) return x;
    Seg z = x;
    z.sum += z.len * y.add;
    return z;
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

    int find(LL val) { return find(val, 1, 0, m).first; }

    // (idx, rest);
    pair<int, LL> find(LL val, int k, int l, int r) {
	force(k);
	LL s = eval(k).sum;
	if (s < val) return make_pair(-1, val - s);
	if (l + 1 == r && s >= val) return make_pair(l, 0);
	pair<int, LL> left = find(val, k*2, l, (l+r)/2);
	if (left.first != -1) return left;
	return find(left.second, k*2+1, (l+r)/2, r);

	//if (x<=l && r<=y) return eval(k);
	//Seg left = query_template(x, y, val, k*2, l, (l+r)/2);
	//Seg right = query_template(x, y, val, k*2+1, (l+r)/2, r);
	//return left + right;
    }
};


int N;
LL K;
int A[200011];

void MAIN() {
    scanf("%d%lld", &N, &K);
    REP (i, N) scanf("%d", A+i);
#ifdef MYTESTX
    N = 200000;
    K = 1000000000;
    REP (i, N) A[i] = 200000;
#endif
    sort(A, A+N);

    VI tmp(500111, 0);
    SegTreeLazy tree(tmp.begin(), tmp.end());
    tree.add(0, 1, 1);
    LL cnt = 1;
    int idx = 0;
    int ans = -1;

    for (int i=N-1; i>=-1; i--) {
	//eprintf("%lld %lld\n", cnt, tree.query(0, 500111).sum);
	assert(cnt == tree.query(0, 500111).sum);
	if (cnt >= K) {
	    int guess = tree.find(K);
	    assert(guess != -1);
	    if (ans == -1 || ans > guess) ans = guess;
	}

	if (i < 0) break;

	while (tree.query(idx, idx+1).sum == 0) {
	    idx++;
	}

	tree.add(idx, idx+1, -1);
	cnt += A[i] - 2;
	int L = (A[i]-1) / 2;
	int R = A[i]-1-L;
	assert(idx+2+L < 500111);
	assert(idx+2+R < 500111);
	tree.add(idx+2, idx+2+L, 1);
	tree.add(idx+2, idx+2+R, 1);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}