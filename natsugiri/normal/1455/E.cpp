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

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}


int N;
LL X[4], Y[4];
LL SX[4], SY[4];

LL dp[1<<4];

LL calc(LL lowX, LL lowY, LL w) {
    REP (i, 4) {
	SX[i] = lowX;
	SY[i] = lowY;
	if (i & 1) SX[i] += w;
	if (i & 2) SY[i] += w;
    }

    memset(dp, 0x3f, sizeof dp);

    dp[0] = 0;
    REP (s, 1<<4) {
	int pc = __builtin_popcount(s);
	REP (i, 4) if (~s>>i&1) {
	    amin(dp[s | 1<<i], dp[s] + abs(SX[pc] - X[i]) + abs(SY[pc] - Y[i]));
	}
    }

    return dp[15];
}

VI W;

void MAIN() {
    REP (i, 4) scanf("%lld%lld", X+i, Y+i);
    W.clear();
    REP (i, 4) REP (j, i) {
	W.push_back(abs(X[i] - X[j]));
	W.push_back(abs(Y[i] - Y[j]));
    }

    W.push_back(0);
    W.push_back(1);

    sort_unique(W);

    LL ans = 1LL<<60;
    REP (i, 4) REP (j, 4) {
	REP (k, W.size()) {
	    LL tmp = calc(X[i], Y[j], W[k]);
	    amin(ans, tmp);
	    tmp = calc(X[i]-W[k], Y[j], W[k]);
	    amin(ans, tmp);
	    tmp = calc(X[i]-W[k], Y[j]-W[k], W[k]);
	    amin(ans, tmp);
	    tmp = calc(X[i], Y[j]-W[k], W[k]);
	    amin(ans, tmp);
	}
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}