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
struct VEB_BASE {
    static const unsigned INF = (unsigned)-1; // Invalid value
    unsigned mi, ma;
    VEB_BASE() : mi(INF), ma(0) { }

    inline unsigned min() const { return mi; }

    inline unsigned max() const { return ma; }

    inline bool empty() const { return ma < mi; }
};

struct VEB_6 : VEB_BASE { // 2^6: 0 ~ 63 
    unsigned long long mask;

    VEB_6() : VEB_BASE(), mask(0) {
    }

    VEB_6(int n_) : VEB_BASE(), mask(0) {
    }

    static inline unsigned ctz(unsigned long long u) {
	return __builtin_ctzll(u);
//	When __builtin_ctzll is undefined.
	if (u == 0) return 64;
	unsigned x, y;
	unsigned n = 63;
	if ((y = u)) { n -= 32; x = y; } else x = u >> 32;
	if ((y = x << 16)) { n -= 16; x = y; }
	if ((y = x << 8)) { n -= 8; x = y; }
	if ((y = x << 4)) { n -= 4; x = y; }
	if ((y = x << 2)) { n -= 2; x = y; }
	return n - ((x << 1) >> 31);
    }
    
    static inline unsigned lg(unsigned long long u) {
	return __lg(u);
//	When __builtin_clzll and __lg are undefined.
	if (u == 0) return 0;
	unsigned x = u >> 32;
	unsigned n = 1;
	if (x == 0) { n += 32; x = u; }
	if ((x >> 16) == 0) { n += 16; x <<= 16; }
	if ((x >> 24) == 0) { n += 8; x <<= 8; }
	if ((x >> 28) == 0) { n += 4; x <<= 4; }
	if ((x >> 30) == 0) { n += 2; x <<= 2; }
	n -= x >> 31; // clzll
	return 63u - n;
    }

    unsigned next(unsigned u) const {
	if (ma <= u) return INF; // empty or ma <= u
	if (u < mi) return mi;
	return ctz(mask & ~((1ULL << (u+1)) - 1));
    }

    unsigned prev(unsigned u) const {
	if (u <= mi) return INF; // empty or u <= mi
	if (ma < u) return ma;
	unsigned long long k = mask & ((1ULL << u) - 1);
	return k? lg(k): mi;
    }

    bool find(unsigned u) const {
	return !empty() && (min() == u || (mask & (1ULL << u)));
    }

    bool insert(unsigned u) {
	if (empty()) {
	    mi = ma = u;
	    return true;
	}
	if (u < mi) swap(mi, u);
	if (mi < u) {
	    if (ma < u) ma = u;
	    if (mask & (1ULL << u)) return false;
	    mask |= 1ULL << u;
	    return true;
	}
	return false;
    }

    bool erase(unsigned u) {
	if (mi == u) {
	    if (ma == u) {
		mi = INF; ma = 0;
		return true;
	    }
	    mi = ctz(mask); mask &= ~(1ULL << mi);
	    return true;
	} else if (u == ma) {
	    mask &= ~(1ULL << u);
	    if (mask) ma = lg(mask);
	    else ma = mi;
	    return true;
	} else if (mi < u) { // mi < u < ma
	    if (mask & (1ULL << u)) {
		mask &= ~(1ULL << u);
		return true;
	    }
	}
	return false;
    }

    void clear() { // nothing to clear.
    }
};

// Children are VEB_M
template<class Children, const unsigned P> struct VEB_NODE : VEB_BASE {
    int ch_len;
    Children aux, *ch;

    VEB_NODE() : VEB_BASE(), ch_len(0), aux(), ch(NULL) {
    }

    VEB_NODE(int n_) : VEB_BASE(), ch_len(0), aux(), ch(NULL) { // Ignore n_.
    }

    unsigned next(unsigned u) const {
	if (ma <= u) return INF;
	if (u < mi) return mi;
	unsigned hi = u >> P, lo = u & ((1u << P) - 1u);
	if (lo < ch[hi].ma) return (hi << P) | ch[hi].next(lo);
	hi = aux.next(hi);
	return (hi << P) | ch[hi].mi;
    }

    unsigned prev(unsigned u) const {
	if (u <= mi) return INF;
	if (ma < u) return ma;
	unsigned hi = u >> P, lo = u & ((1 << P) - 1u);
	if (ch[hi].mi < lo) return (hi << P) | ch[hi].prev(lo);
	hi = aux.prev(hi);
	return hi == INF? mi: (hi << P) | ch[hi].ma;
    }

    bool find(unsigned u) const {
	return !empty() && (u == min() || ch[u >> P].find(u & ((1u << P) - 1u)));
    }

    bool insert(unsigned u) {
	if (empty()) {
	    mi = ma = u;
	    return true;
	}
	if (u < mi) swap(mi, u);
	if (mi < u) {
	    unsigned hi = u >> P, lo = u & ((1u << P) - 1u);
	    if (ma < u) ma = u;
	    if (ch[hi].empty()) aux.insert(hi);
	    if (ch[hi].insert(lo)) return true;
	    else return false;
	}
	return false;
    }

    bool erase(unsigned u) {
	if (empty()) {
	    return false;
	} else if (mi == u) {
	    if (ma == u) {
		mi = INF; ma = 0;
		return true;
	    } else {
		mi = u = (aux.mi << P) | ch[aux.mi].mi;
	    }
	}
	if (ch[u >> P].erase(u & ((1u << P) - 1u))) {
	    if (ch[u >> P].empty()) aux.erase(u >> P);
	    if (ma == u) {
		if (aux.empty()) ma = mi;
		else ma = (aux.ma << P) | ch[aux.ma].ma;
	    }
	    return true;
	} else {
	    return false;
	}
    }

    void clear() {
	if (ch) {
	    REP (i, ch_len) ch[i].clear();
	    aux.clear();
	    delete[] ch; ch = NULL;
	}
    }
};

struct VEB_12 : VEB_NODE<VEB_6, 6> { // n_ <= 1<<12
    typedef VEB_NODE<VEB_6, 6> S;
    VEB_12() : S() { 
    }

    VEB_12(unsigned n_) : S() {
	ch_len = (n_ + (1u<<6) - 1u) >> 6;
	ch = new VEB_6[ch_len];
	REP (i, ch_len) ch[i] = VEB_6(1u << 6);
	aux = VEB_6(ch_len);
    }
};

struct VEB : VEB_NODE<VEB_12, 12> { // n_ <= 1<<24
    typedef VEB_NODE<VEB_12, 12> S;
    VEB() : S() { }

    VEB(unsigned n_) : S() {
	unsigned r = n_ & ((1u<<12) - 1u);
	ch_len = (n_ + (1u<<12) - 1u) >> 12;
	ch = new VEB_12[ch_len];
	if (r) {
	    REP (i, ch_len-1) ch[i] = VEB_12(1u << 12);
	    ch[ch_len-1] = VEB_12(r);
	} else {
	    REP (i, ch_len) ch[i] = VEB_12(1u << 12);
	}
	aux = VEB_12(ch_len);
    }

    ~VEB() { if (ch) clear(); }
};

int N;
char S[1000011];
int nxt[1000011][2];

VI Z[1000011];
int ans[1000011];
VEB veb(1<<24);

void MAIN() {
    scanf("%d%s", &N, S);
#ifdef LOCAL
    N = 1000000;
    REP (i, N) S[i] = '?';
    REP (i, N) if (N % 1000 == 0) S[i] = rand() % 2 + '0';
#endif


    REP (b, 2) nxt[N][b] = N;
    for (int i=N; i--;) {
	REP (b, 2) nxt[i][b] = nxt[i+1][b];
	if (S[i] == '0') nxt[i][0] = i;
	if (S[i] == '1') nxt[i][1] = i;
    }

    REP (i, N) {
	int m = max(nxt[i][0], nxt[i][1]);
	Z[m-i].push_back(i);
    }

    veb.insert(N);

    for (int x=N; x>=1; x--) {
	EACH (e, Z[x]) veb.insert(*e);
	int cnt = 0;
	int i = veb.min();
	while (i < N) {
	    int right = max(nxt[i][0], nxt[i][1]);
	    int m = (right - i) / x;
	    assert(m);
	    cnt += m;
	    int j = i + m * x;
	    i = (veb.find(j)? j: veb.next(j));
	}
	ans[x] = cnt;
    }

    rprintf("%d", ans+1, ans+N+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}