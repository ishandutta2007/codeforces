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


int N, M;
char F[2011][2011];
int dp[2011][2011];
int X[2011][2011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    memset(X, 0x3f, sizeof X);

    REP (t, 4) {
	REP (i, N) REP (j, M) {
	    int a = 0, b = 0;
	    if (i && F[i-1][j] == F[i][j]) a = dp[i-1][j];
	    if (j && F[i][j-1] == F[i][j]) b = dp[i][j-1];
	    dp[i][j] = min(a, b) + 1;
	    amin(X[i][j], dp[i][j]);
	}

	if (t == 0 || t == 2) {
	    REP (i, N) {
		reverse(F[i], F[i] + M);
		reverse(X[i], X[i] + M);
	    }
	} else {
	    REP (i, N/2) REP (j, M) {
		swap(F[i][j], F[N-1-i][j]);
		swap(X[i][j], X[N-1-i][j]);
	    }
	}
    }

    LL ans = 0;
    REP (i, N) REP (j, M) ans += X[i][j];
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}