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

LL N;

LL query(LL l, LL r) {
    printf("? %lld %lld\n", l, r);
    fflush(stdout);
    LL ret;
    scanf("%lld", &ret);
    return ret;
}

void MAIN() {
    scanf("%lld", &N);

    LL lo = 1, hi = N;
    while (hi - lo > 1) {
	LL mid = (lo + hi) /2;
	LL q = query(1, mid);
	if (q) hi = mid;
	else lo = mid;
    }

    LL total = query(lo, N);
    LL small = query(lo+1, N);

    LL I = lo;
    LL J = I + total - small + 1;

    lo = J;
    hi = N;
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	LL tmp = (J-I)*(J-I-1) / 2 + (mid-J+1)*(mid-J) / 2;
	if (tmp < total) lo = mid;
	else hi = mid;
    }

    LL K = hi;

    printf("! %lld %lld %lld\n", I, J, K);
    fflush(stdout);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}