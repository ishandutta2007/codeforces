#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const int INF = 0x3f3f3f3f;
int N;
int A[2011], B[2011];
int dp[2011][10][10][10]; // dp[next id][to][to][to];
// 2 * 10^6;

bool ordered(int x, int y, int z) {
    return (x <= y && y <= z) || (x >= y && y >= z);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", A+i, B+i);

    memset(dp, 0x3f, sizeof dp);

    dp[0][0][0][0] = A[0] - 1;

    REP (i, N-1) REP (to2, 10) REP (to1, 10) REP (to0, 10) {
	int cur = dp[i][to2][to1][to0];
	if (cur == INF) continue;

	int pos = A[i];
	int nxt = A[i+1];
	// pos -> j -> nxt;
	for (int j=1; j<=9; j++) {
	    int mv = abs(pos - j) + abs(j - nxt);
	    int wait = 1;
	    int s2 = to2, s1 = to1, s0 = to0, sx = B[i];

	    if (ordered(pos, sx, j) || ordered(j, sx, nxt)) { wait++; sx = 0; }
	    if (ordered(pos, s0, j) || ordered(j, s0, nxt)) { wait++; s0 = sx; sx = 0; }
	    if (ordered(pos, s1, j) || ordered(j, s1, nxt)) { wait++; s1 = s0; s0 = sx; sx = 0; }
	    if (ordered(pos, s2, j) || ordered(j, s2, nxt)) { wait++; s2 = s1; s1 = s0; s0 = sx; sx = 0; }

	    if (s0 < sx) swap(s0, sx);
	    if (s1 < s0) swap(s1, s0);
	    if (s2 < s1) swap(s2, s1);

	    if (sx == 0) {
		amin(dp[i+1][s2][s1][s0], cur + mv + wait);
	    }
	}
    }


    int ans = INF;
    {
	REP (to2, 10) REP (to1, 10) REP (to0, 10) {
	    int cur = dp[N-1][to2][to1][to0];
	    if (cur == INF) continue;

	    int pos = A[N-1];
	    int tox = B[N-1];

	    // pos -> a -> b;
	    for (int a=1; a<=9; a++) for (int b=1; b<=9; b++) {
		if (to2 && !ordered(pos, to2, a) && !ordered(a, to2, b)) continue;
		if (to1 && !ordered(pos, to1, a) && !ordered(a, to1, b)) continue;
		if (to0 && !ordered(pos, to0, a) && !ordered(a, to0, b)) continue;
		if (tox && !ordered(pos, tox, a) && !ordered(a, tox, b)) continue;

		int cst = 1 + abs(pos - a) + abs(a - b) + 
		    (to2? 1: 0) +
		    (to1? 1: 0) +
		    (to0? 1: 0) +
		    (tox? 1: 0);

		amin(ans, cur + cst);
	    }
	}
    }

    printf("%d\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}