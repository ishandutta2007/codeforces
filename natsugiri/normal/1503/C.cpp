#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>
#include<queue>

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
pair<LL, LL> P[100011];
LL sums[100011];
LL dp[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", &P[i].first, &P[i].second);
    sort(P, P+N);

    REP (i, N) sums[i+1] = sums[i] + P[i].second;

    memset(dp, 0x3f, sizeof dp);

    priority_queue<pair<LL, int> > Q; // (-key, idx);
    multiset<LL> se; // val;
    {
	LL key = P[0].first + P[0].second;
	dp[0] = 0;
	Q.emplace(-key, 0);
	se.insert(0);
    }

    LL best = 1LL<<60;


    for (int i=1; i<N; i++) {
	while (!Q.empty() && -Q.top().first <= P[i].first) {
	    LL key = -Q.top().first;
	    int idx = Q.top().second;
	    LL val = dp[idx] - sums[idx];

	    auto it = se.find(val);
	    assert(it != se.end());
	    se.erase(it);

	    amin(best, dp[idx] - sums[idx+1] - P[idx].first);

	    Q.pop();
	}

	if (se.size()) {
	    LL val = *se.begin();
	    amin(dp[i], val + sums[i]);
	}

	amin(dp[i], best + sums[i] + P[i].first);

	LL key = P[i].first + P[i].second;
	LL val = dp[i] - sums[i];

	Q.emplace(-key, i);
	se.insert(val);
    }

    LL ans = dp[N-1] + P[N-1].second;

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}