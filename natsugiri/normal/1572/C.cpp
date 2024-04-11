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

const int INF = 0x3f3f3f3f;

int N;
int A[3011];

int dpL[3011][3011];
int dpR[3011][3011];

VI G[3011];

int getL(int l, int r) {
    int c = A[l];
    int ret = min(dpL[l][r], dpR[l][r] + 1);
    auto it = lower_bound(G[c].begin(), G[c].end(), l);
    while (it != G[c].end() && *it <= r) {
	amin(ret, dpR[l][*it] + dpL[*it][r]);
	if (l < *it) amin(ret, dpL[l][*it-1] + dpL[*it][r]);
	it++;
    }
    return ret;
}
int getR(int l, int r) {
    int c = A[r];
    int ret = min(dpL[l][r] + 1, dpR[l][r]);
    auto it = lower_bound(G[c].begin(), G[c].end(), l);
    while (it != G[c].end() && *it <= r) {
	amin(ret, dpR[l][*it] + dpL[*it][r]);
	if (*it < r) amin(ret, dpR[l][*it] + dpR[*it+1][r]);
	it++;
    }
    return ret;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N+1) G[i].clear();
    REP (i, N) G[A[i]].push_back(i);

    REP (i, N+1) REP (j, N+1) {
	dpL[i][j] = dpR[i][j] = INF;
    }

    for (int l=N; l--;) {
	dpL[l][l] = dpR[l][l] = 0;

	for (int r=l+1; r<N; r++) {
	    amin(dpL[l][r], dpL[l+1][r] + 1);
	    amin(dpL[l][r], dpR[l+1][r] + 1);

	    amin(dpR[l][r], dpL[l][r-1] + 1);
	    amin(dpR[l][r], dpR[l][r-1] + 1);

	    amin(dpL[l][r], dpL[l][r-1] + 1);
	    amin(dpR[l][r], dpR[l+1][r] + 1);

	    if (A[l] == A[r]) {
		amin(dpL[l][r], dpR[l+1][r]);
		amin(dpR[l][r], dpL[l][r-1]);
		amin(dpL[l][r], dpL[l][r-1]);
		amin(dpR[l][r], dpR[l+1][r]);
	    }

	    amin(dpL[l][r], getL(l, r));
	    amin(dpR[l][r], getR(l, r));
	}
    }

    int ans = dpL[0][N-1];
    REP (i, N) {
	amin(ans, dpR[0][i] + dpL[i][N-1]);
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}