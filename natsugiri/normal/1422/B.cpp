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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M;
LL A[111][111];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%lld", &A[i][j]);

    LL ans = 0;
    REP (i, N/2) REP (j, M/2) {
	LL B[4];
	B[0] = A[i][j];
	B[1] = A[i][M-1-j];
	B[2] = A[N-1-i][M-1-j];
	B[3] = A[N-1-i][j];
	sort(B, B+4);
	REP (k, 4) ans += abs(B[1] - B[k]);
    }

    if (N % 2 == 1) {
	REP (j, M/2) {
	    LL x = A[N/2][j];
	    LL y = A[N/2][M-1-j];
	    ans += abs(x - y);
	}
    }
    if (M % 2 == 1) {
	REP (i, N/2) {
	    LL x = A[i][M/2];
	    LL y = A[N-1-i][M/2];
	    ans += abs(x - y);
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