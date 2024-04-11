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

int N;
pair<LL, LL> BA[100011];
LL C[100011];

bool ok(LL mid) {
    LL rest = mid;
    for (int i=N; i--;) {
	LL g = min(rest, BA[i].second);
	C[i] = g;
	rest -= g;
    }

    LL cur = mid;
    REP (i, N) if (BA[i].second > C[i]) {
	if (cur < BA[i].first) return false;
	cur += BA[i].second - C[i];
    }

    return true;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", &BA[i].second, &BA[i].first);

    sort(BA, BA+N);

    LL sum = 0;
    REP (i, N) sum += BA[i].second;

    LL lo = -1, hi = sum + 1;
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }

    printf("%lld\n", sum + hi);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}