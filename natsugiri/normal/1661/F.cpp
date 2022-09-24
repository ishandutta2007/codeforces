#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<random>

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

mt19937_64 engine;

LL sq(LL x) { return x * x; }

LL F(LL w, LL s) {
    LL q = w / (s + 1);
    LL r = w % (s + 1);
    return sq(q + 1) * r + sq(q) * (s + 1 - r);
}

int N;
LL A[200011];
LL M;

LL COUNT;
LL COST;
bool ok(LL mid) {
    COUNT = 0;
    COST = 0;
    LL prv = 0;
    REP (i, N) {
	LL w = A[i] - prv;

	LL lo = 0, hi = w;
	while (hi - lo > 1) {
	    LL sep = (lo + hi) / 2;
	    if (F(w, sep-1) - F(w, sep) >= mid) {
		lo = sep;
	    } else {
		hi = sep;
	    }
	}
	COST += F(w, lo);
	COUNT += lo;
	if (COST > M) return false;

	prv = A[i];
    }
    return true;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    scanf("%lld", &M);


    LL lo = 0, hi = 1LL<<30;
    while (ok(hi)) {
	lo = hi;
	hi += hi;
	if (COUNT == 0) break;
    }

    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	(ok(mid)? lo: hi) = mid;
    }

    ok(hi);
    // printf("hi %lld, %lld %lld\n", hi, COUNT, COST);
    LL count_hi = COUNT;

    ok(lo);
    // printf("lo %lld, %lld %lld\n", lo, COUNT, COST);
    LL count_lo = COUNT;
    LL cost = COST;

    if (lo) {
	LL g = min(count_lo - count_hi, (M - cost) / lo);
	count_lo -= g;
	cost += g * hi;
    }


    printf("%lld\n", count_lo);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}