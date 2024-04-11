#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

struct BySecond {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
	return x.second < y.second;
    }
} bySecond;

int N;
int A[200011];
int B[200011];

LL solve() {
    LL base = 0;
    REP (i, N) {
	base += abs((LL)A[i] - B[i]);
    }

    vector<pair<int, int> > high, low;
    REP (i, N) {
	if (A[i] > B[i]) high.emplace_back(A[i], B[i]);
	if (A[i] < B[i]) low.emplace_back(A[i], B[i]);
    }

    if (high.empty()) return base;
    if (low.empty()) return base;

    LL ret = base;

    sort(high.begin(), high.end(), bySecond);
    sort(low.begin(), low.end());
    set<int> se;

    int k = 0;

    EACH (e, high) {
	int a = e->first;
	int b = e->second;
	while (k < (int)low.size() && low[k].first <= b) {
	    se.insert(low[k].second);
	    k++;
	}

	auto it = se.upper_bound(a);

	if (it != se.begin()) {
	    auto prv = prev(it);
	    if (b <= *prv && *prv <= a) {
		amin(ret, base - 2LL*((LL)*prv - b));
	    }
	}

	it = se.lower_bound(a);
	if (it != se.end()) {
	    amin(ret, base - 2LL*((LL)a-b));
	}
    }

    return ret;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    LL ans = 1LL<<60;

    REP (a, 2) {
	REP (b, 2) {
	    LL tmp = solve();
	    amin(ans, tmp);

	    REP (i, N) swap(A[i], B[i]);
	}

	REP (i, N) {
	    A[i] = -A[i];
	    B[i] = -B[i];
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}