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
LL X[100011];
LL T[100011];

double ans;
vector<pair<double, int> > P;

bool ok(double mid) {
    P.clear();
    REP (i, N) {
	if (T[i] > mid) return false;
	double w = mid - T[i];
	P.emplace_back(X[i] - w, -1);
	P.emplace_back(X[i] + w, 1);
    }

    int cnt = 0;
    sort(P.begin(), P.end());
    REP (i, P.size()) {
	cnt += P[i].second;
	if (cnt == -N) {
	    ans = P[i].first;
	    return true;
	}
    }
    return false;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", X+i);
    REP (i, N) scanf("%lld", T+i);

    double lo = -1;
    double hi = 1;
    while (!ok(hi)) {
	lo = hi;
	hi += hi;
    }
    REP (t, 40) {
	double mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }
    ok(hi);
    printf("%.20f\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}