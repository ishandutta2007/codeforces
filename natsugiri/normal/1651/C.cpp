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
int A[200011];
int B[200011];
int SA[200011];
int SB[200011];

int cost(int s[], int b) {
    int k = lower_bound(s, s+N, b) - s;
    int ret = 1000000000;
    if (k < N) amin(ret, s[k] - b);
    if (k) amin(ret, b - s[k-1]);
    return ret;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    REP (i, N) {
	SA[i] = A[i];
	SB[i] = B[i];
    }
    sort(SA, SA+N);
    sort(SB, SB+N);

    int cost_a1[3] = {
	abs(A[0] - B[0]),
	abs(A[0] - B[N-1]),
	cost(SB, A[0]),
    };
    int cost_a2[3] = {
	abs(A[N-1] - B[0]),
	abs(A[N-1] - B[N-1]),
	cost(SB, A[N-1]),
    };
    int cost_b1 = cost(SA, B[0]);
    int cost_b2 = cost(SA, B[N-1]);

    LL ans = 1LL<<60;
    REP (a1, 3) REP (a2, 3) {
	LL cst = 0;
	cst += cost_a1[a1];
	cst += cost_a2[a2];
	if (a1 != 0 && a2 != 0) {
	    cst += cost_b1;
	}
	if (a1 != 1 && a2 != 1) {
	    cst += cost_b2;
	}
	amin(ans, cst);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}