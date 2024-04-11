#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

struct ByFirst {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
	return x.first < y.first;
    }
} byFirst;

int N, M;
int A[200011];

vector<pair<int, int> > B[200011];
const LL INF = 1LL<<60;

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    REP (i, N+1) B[i].clear();

    REP (i, M) {
	int l, r;
	scanf("%d%d", &l, &r);
	int k = lower_bound(A, A+N, l) - A;
	if (k < N && A[k] <= r) {
	    // skip;
	} else {
	    B[k].emplace_back(l, r);
	}
    }
    M = -1;

    REP (i, N+1) sort(B[i].begin(), B[i].end());

    vector<pair<LL, LL> > cur, nxt;
    cur.emplace_back(-INF, 0);

    REP (i, N) {
	// B[i], A[i], B[i+1];
	multiset<int> se;
	EACH (e, B[i]) se.insert(e->second);

	se.insert(A[i]);

	LL lcost1 = INF;
	LL lcost2 = INF;

	int k = 0;
	EACH (e, cur) {
	    while (k < (int)B[i].size() && B[i][k].first <= e->first) {
		se.erase(se.find(B[i][k].second));
		k++;
	    }

	    amin(lcost1, e->second + 1LL*(A[i] - (LL)*se.begin()));
	    amin(lcost2, e->second + 2LL*(A[i] - (LL)*se.begin()));
	}

	nxt.clear();
	nxt.emplace_back(A[i], lcost1);

	EACH (e, B[i+1]) {
	    assert(e->first > A[i]);
	    nxt.emplace_back(e->first, lcost1 + 2LL*(e->first - A[i]));
	    nxt.emplace_back(e->first, lcost2 + 1LL*(e->first - A[i]));
	}
	sort(nxt.begin(), nxt.end());
	cur.clear();
	EACH (e, nxt) {
	    if (cur.empty() || cur.back().first != e->first) cur.push_back(*e);
	}
    }

    LL ans = cur.back().second;
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}