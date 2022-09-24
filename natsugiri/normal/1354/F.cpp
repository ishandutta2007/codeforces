#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

struct Data {
    LL a, b;
    int i;
    bool operator<(const Data &o) const {
	return b < o.b;
    }
};

int N, K;
Data P[77];

LL dp[77][77];

LL solve(int last) {
    P[N] = P[last];
    memset(dp, 0xc0, sizeof dp);
    dp[0][0] = 0;

    REP (i, N+1) {
	// skip;
	REP (j, K) amax(dp[i+1][j], dp[i][j]);

	if (i == last) continue;

	// take;
	REP (j, K) amax(dp[i+1][j+1], dp[i][j] + P[i].a + j * P[i].b);

	// take & destroy;
	REP (j, K) amax(dp[i+1][j], dp[i][j] + (K-1) * P[i].b);
    }

    return dp[N+1][K];
}


void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) {
	scanf("%lld%lld", &P[i].a, &P[i].b);
	P[i].i = i;
    }
    sort(P, P+N);

    pair<LL, int> best(-1, 0);
    REP (i, N) {
	LL tmp = solve(i);
	amax(best, make_pair(tmp, i));
    }

    solve(best.second);
    //eprintf("power %lld\n", best.first);

    int x = K;
    VI take;
    VI destroy;
    for (int i=N+1; i--;) {
	if (i == best.second) continue;
	
	if (x < K && dp[i+1][x] == dp[i][x]) {

	} else if (dp[i+1][x] == dp[i][x-1] + P[i].a + (x-1)*P[i].b) {
	    take.push_back(P[i].i + 1);
	    x--;
	} else if (dp[i+1][x] == dp[i][x] + (K-1)*P[i].b) {
	    destroy.push_back(P[i].i+1);
	} else {
	    assert(false);
	}
    }

    assert(x == 0);
    VI ans;
    for (int i=take.size()-1; i>0; i--) ans.push_back(take[i]);
    for (int i=destroy.size(); i--;) {
	ans.push_back(destroy[i]);
	ans.push_back(-destroy[i]);
    }
    ans.push_back(take[0]);

    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}