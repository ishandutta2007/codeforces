#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// VEB
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
struct VEB_BASE {
    static const unsigned INVALID = ~0;

    unsigned mi, ma;

    VEB_BASE() : mi(INVALID), ma(0) { }

    inline unsigned min() const { return mi; }

    inline unsigned max() const { return ma < mi? INVALID: ma; }

    inline bool empty() const { return ma < mi; }
};

// van Emde Boas Tree 2P-bit (upper P-bit and lower P-bit, 0 ~ 2^(2P)-1);
template<const unsigned P> struct VEB_NODE : VEB_BASE { 
    typedef VEB_NODE<(P>>1)> Child;

    int ch_len;
    Child aux, *ch;

    VEB_NODE() : VEB_BASE(), ch_len(0), aux(), ch(NULL) { }

    VEB_NODE(int n_) : VEB_BASE(), ch_len(0), aux(), ch(NULL) {
	int r = n_ & ((1u<<P) - 1u);
	ch_len = (n_ >> P) + (bool)r;
	ch = new Child[ch_len];
	if (r) {
	    for (int i=0; i<ch_len-1; i++) ch[i] = Child(1u << P);
	    ch[ch_len-1] = Child(r);
	} else {
	    for (int i=0; i<ch_len; i++) ch[i] = Child(1u << P);
	}
	aux = Child(ch_len);
    }

    unsigned next(unsigned u) const {
	if (ma <= u) return INVALID;
	if (u < mi) return mi;
	unsigned hi = u >> P, lo = u & ((1u << P) - 1u);
	if (lo < ch[hi].ma) return (hi << P) | ch[hi].next(lo);
	hi = aux.next(hi);
	return (hi << P) | ch[hi].mi;
    }

    unsigned prev(unsigned u) const {
	if (u <= mi) return INVALID;
	if (ma < u) return ma;
	unsigned hi = u >> P, lo = u & ((1 << P) - 1u);
	if (ch[hi].mi < lo) return (hi << P) | ch[hi].prev(lo);
	hi = aux.prev(hi);
	return hi == INVALID? mi: (hi << P) | ch[hi].ma;
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
	    return ch[hi].insert(lo);
	}
	return false;
    }

    bool erase(unsigned u) {
	if (empty()) {
	    return false;
	} else if (mi == u) {
	    if (ma == u) {
		mi = INVALID; ma = 0;
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
	    for (int i=0; i<ch_len; i++) ch[i].clear();
	    aux.clear();
	    delete[] ch; ch = NULL;
	}
    }
};

// vEB 6-bit (0 ~ 63);
template<> struct VEB_NODE<3> : VEB_BASE {
    unsigned long long mask;

    VEB_NODE() : VEB_BASE(), mask(0) { }

    VEB_NODE(int n_) : VEB_BASE(), mask(0) { }

    static inline unsigned ctz(unsigned long long u) {
#ifdef __GNUC__
	return __builtin_ctzll(u);
#else
//	When __builtin_ctzll is not defined;
	unsigned n = 0;
	if ((u & 0x00000000FFFFFFFFULL) == 0) { u >>= 32; n += 32; }
	if ((u & 0x000000000000FFFFULL) == 0) { u >>= 16; n += 16; }
	if ((u & 0x00000000000000FFULL) == 0) { u >>=  8; n +=  8; }
	if ((u & 0x000000000000000FULL) == 0) { u >>=  4; n +=  4; }
	static const unsigned ctz_4bit[16] = { 4, 0, 1, 0, 2, 0, 1, 0, 3, 0, 1, 0, 2, 0, 1, 0, };
	return n + ctz_4bit[u & 0xFULL]; // if u == 0: return 64;
#endif
    }
    
    static inline unsigned lg(unsigned long long u) {
#ifdef __GNUC__
	return __lg(u);
#else
//	When __builtin_clzll and __lg are not defined;
	unsigned n = 0;
	if (u & 0xFFFFFFFF00000000ULL) { u >>= 32; n += 32; }
	if (u & 0x00000000FFFF0000ULL) { u >>= 16; n += 16; }
	if (u & 0x000000000000FF00ULL) { u >>=  8; n +=  8; }
	if (u & 0x00000000000000F0ULL) { u >>=  4; n +=  4; }
	static const unsigned lg_4bit[16] = { 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, };
	return n + lg_4bit[u]; // if u == 0: return 0;
#endif
    }

    unsigned next(unsigned u) const {
	if (ma <= u) return INVALID; // empty or ma <= u;
	if (u < mi) return mi;
	return ctz(mask & ~((1ULL << (u+1)) - 1));
    }

    unsigned prev(unsigned u) const {
	if (u <= mi) return INVALID; // empty or u <= mi;
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
		mi = INVALID; ma = 0;
		return true;
	    }
	    mi = ctz(mask); mask &= ~(1ULL << mi);
	    return true;
	} else if (u == ma) {
	    mask &= ~(1ULL << u);
	    if (mask) ma = lg(mask);
	    else ma = mi;
	    return true;
	} else if (mi < u) { // if mi < u < ma;
	    if (mask & (1ULL << u)) {
		mask &= ~(1ULL << u);
		return true;
	    }
	}
	return false;
    }

    void clear() { // has nothing to clear;
    }
};

// vEB 24-bit;
typedef VEB_NODE<12> VEB;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// VEB
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int N;
int A[1000111];
pair<int, int> P[1000111];

LL solve() {
    REP (i, N) P[i] = make_pair(A[i], i);
    sort(P, P+N);
    LL ret = 0;
    VEB veb(N+2);
    veb.insert(0);
    veb.insert(N+1);
    REP (i_, N) {
	int i = N-1-i_;
	int s = P[i].second + 1;
	int nxt = veb.next(s);
	int prv = veb.prev(s);
	ret += (LL) P[i].first * (nxt - s) * (s - prv);

//	eprintf("%d [%d %d %d]\n", P[i].first, prv, s, nxt);

	veb.insert(s);
    }
    return ret;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    LL ans = 0;
    ans += solve();
    REP (i, N) A[i] = -A[i];
    ans += solve();
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}