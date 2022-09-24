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

int M;
LL A[2][200011];

LL NEGA[2][200011];
LL POSI[2][200011];

void MAIN() {
    scanf("%d", &M);
    REP (i, 2) {
	REP (j, M) scanf("%lld", A[i]+j);
	reverse(A[i], A[i]+M);
    }
    A[0][M-1] = -1;

    REP (i, 2) {
	NEGA[i][0] = A[i][0];
	POSI[i][0] = A[i][0];
	for (int j=1; j<M; j++) {
	    NEGA[i][j] = max(NEGA[i][j-1], A[i][j] - j);
	    POSI[i][j] = max(POSI[i][j-1], A[i][j] + j);
	}
    }

    LL ans = 1LL<<60;
    LL max_v = 0;
    int cnt = 0;
    for (int j=M; j--;) {
	if ((M-j) % 2 == 1) {
	    LL guess = max_v + 2*M - 1;
	    amax(guess, POSI[0][j] + j + 2);
	    amax(guess, NEGA[1][j] + j + 1);
	    amin(ans, guess);

	    amax(max_v, A[0][j] - cnt + 1);
	    cnt++;
	    amax(max_v, A[1][j] - cnt + 1);
	    cnt++;
	} else {
	    LL guess = max_v + 2*M - 1;
	    amax(guess, POSI[1][j] + j + 2);
	    amax(guess, NEGA[0][j] + j + 1);
	    amin(ans, guess);

	    amax(max_v, A[1][j] - cnt + 1);
	    cnt++;
	    amax(max_v, A[0][j] - cnt + 1);
	    cnt++;
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