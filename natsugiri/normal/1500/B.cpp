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


LL gcd(LL x_, LL y_) {
    typedef unsigned long long ULL;
    ULL x = abs(x_);
    ULL y = abs(y_);
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

LL lcm(LL x, LL y) {
    assert(x >= 1);
    assert(y >= 1);
    return x/gcd(x, y)*y;
}

// xs + yt = gcd(x, y), xu + yv = 0
// abs(s) < abs(y / gcd(x, y));
// abs(t) < abs(x / gcd(x, y));
LL extgcd(LL x, LL y, LL&s, LL&t) {
    assert(x >= 0 && y >= 0);
    for (LL u=t=1, v=s=0; x; ) {
	LL q = y / x;
	swap(s -= q * u, u);
	swap(t -= q * v, v);
	swap(y -= q * x, x);
    }
    return y;
}

int N, M;
LL K;
int A[500011];
int B[500011];
int C[1000011];
vector<pair<int, int> > P;
vector<LL> Z;

LL L;
LL G;

bool ok(LL mid) {
    LL diff = mid;
    EACH (e, Z) {
	if (*e < mid) {
	    diff -= (mid - *e - 1) / L + 1;
	    if (diff < K) return false;

	}
    }
    return diff >= K;
}

void MAIN() {
    scanf("%d%d%lld", &N, &M, &K);
    REP (i, N) scanf("%d", A+i);
    REP (i, M) scanf("%d", B+i);

    memset(C, -1, sizeof C);
    REP (i, N) C[A[i]] = i;

    REP (i, M) if (C[B[i]] != -1) {
	P.emplace_back(C[B[i]], i);
    }

    LL a, b;
    G = extgcd(N, M, a, b);
    L = N/G*M;
    // Na + Mb == G;

    EACH (e, P) {
	int i = e->first;
	int j = e->second;
	if (abs(j-i) % G == 0) {
	    LL r = (j-i) / G;

	    LL aa = a * r;
	    // LL bb = b * r;
	    // Naa + Mbb = j-i
	    // Naa + i == -Mbb + j;

	    LL h = N*aa + i;
	    h -= h / L * L;
	    while (h < 0) h += L;
	    Z.push_back(h);
	}
    }


    LL lo = 0, hi = 1;
    while (!ok(hi)) {
	lo = hi;
	hi += hi;
    }
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }
    printf("%lld\n", hi);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}