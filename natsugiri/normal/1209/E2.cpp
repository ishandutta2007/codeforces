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

int N, M;
int A[12][2011];
vector<pair<int, int> > B;

LL dp[1<<12];
LL value[1<<12];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%d", &A[i][j]);

#ifdef LOCAL
    N = 12;
    M = 2000;
    REP (i, N) REP (j, M) A[i][j] = rand() % 100000;
#endif

    memset(dp, 0xc0, sizeof dp);
    dp[0] = 0;
    const int HIGH = 1<<(N-1);
    const int MASK = (1<<N)-1;

    B.clear();
    REP (j, M) {
	int ma = A[0][j];
	REP (i, N) amax(ma, A[i][j]);
	B.emplace_back(ma, j);
    }
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    REP (j_, min(N, M)) {
	int j = B[j_].second;

	for (int s=1; s<(1<<N); s++) {
	    int k = __builtin_ctz(s);
	    value[s] = value[s^(1<<k)] + A[k][j];
	}

	for (int s=HIGH; s<(1<<N); s++) {
	    int t = s;
	    REP (k, N) {
		t = (t>>1) | ((t&1)<<(N-1));
		amax(value[s], value[t]);
	    }
	}

	for (int s=1<<(N-1); s--;) {
	    int rest = MASK ^ s;
	    for (int sub=rest; sub&HIGH; sub=(sub-1)&rest) {
		amax(dp[s | sub], dp[s] + value[sub]);
	    }
	}

	for (int s=HIGH; s<(1<<N); s++) {
	    amax(dp[s], value[s]);
	    int t = s;
	    REP (k, N) {
		t = (t>>1) | ((t&1)<<(N-1));
		amax(dp[t], dp[s]);
	    }
	}
    }

    LL ans = dp[(1<<N)-1];
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}