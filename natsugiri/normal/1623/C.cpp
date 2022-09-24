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

int N;
LL H[200011];
LL A[200011];

bool ok(LL mid) {
    REP (i, N) A[i] = 0;

    for (int i=N-1; i>=2; i--) {
	if (A[i] + H[i] < mid) return false;

	LL g = min(H[i], A[i] + H[i] - mid);

	LL d = g/3;
	A[i-1] += d;
	A[i-2] += d*2;
    }

    if (A[0] + H[0] < mid) return false;
    if (A[1] + H[1] < mid) return false;
    return true;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", H+i);
    
    LL lo = 0, hi = 1;
    while (ok(hi)) {
	lo = hi;
	hi += hi;
    }
    while (hi - lo > 1) {
	LL mid = (lo+hi) / 2;
	(ok(mid)? lo: hi) = mid;
    }

    printf("%lld\n", lo);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}