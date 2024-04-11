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

int N, M;
int A[1011][1011];
int ma[1011][1011];
int mi[1011][1011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, M) scanf("%d", &A[i][j]);

    const int INF = 1<<29;
    bool yes = false;
    if ((N + M) % 2 == 1) {
	REP (i, N) REP (j, M) {
	    if (i == 0 && j == 0) {
		mi[i][j] = ma[i][j] = A[i][j];
	    } else {
		mi[i][j] = INF;
		ma[i][j] = -INF;
		if (i) {
		    amin(mi[i][j], mi[i-1][j] + A[i][j]);
		    amax(ma[i][j], ma[i-1][j] + A[i][j]);
		}
		if (j) {
		    amin(mi[i][j], mi[i][j-1] + A[i][j]);
		    amax(ma[i][j], ma[i][j-1] + A[i][j]);
		}
	    }
	}
	yes = (mi[N-1][M-1] <= 0 && 0 <= ma[N-1][M-1]);
    }
    puts(yes?"YES":"NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}