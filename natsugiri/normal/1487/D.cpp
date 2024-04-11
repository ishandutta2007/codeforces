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

LL N;
bool ok(LL mid) {
    assert(mid >= 1);
    LL A = 2*mid+1;
    if (A > N) return false;
    LL B = (A*A-1) / 2;
    if (B > N) return false;
    if (A*A + B*B > N*N) return false;
    return true;
}

void MAIN() {
    scanf("%lld", &N);

    LL lo = 0, hi = 1000000;
    assert(!ok(hi));
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
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