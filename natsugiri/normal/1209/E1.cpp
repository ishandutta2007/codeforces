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

LL dp[1<<12];
LL value[1<<12];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%d", &A[i][j]);

    memset(dp, 0xc0, sizeof dp);
    dp[0] = 0;

    REP (j, M) {
	for (int s=1; s<(1<<N); s++) {
	    int k = __builtin_ctz(s);
	    value[s] = value[s^(1<<k)] + A[k][j];
	}
	REP (s, 1<<N) {
	    int t = s;
	    REP (k, N) {
		t = (t>>1) | ((t&1)<<(N-1));
		amax(value[t], value[s]);
	    }
	}

	for (int s=1<<N; s--;) {
	    int rest = ((1<<N)-1) ^ s;
	    for (int sub=rest; sub; sub=(sub-1)&rest) {
		amax(dp[s | sub], dp[s] + value[sub]);
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