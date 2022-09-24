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

int dp[511][511][2][2];

void init() {
    memset(dp, 0x3f, sizeof dp);

    REP (a, 505) REP (b, 505) REP (c, 2) REP (p, 2) {
	if (a == 0 && b == 0 && c == 0) {
	    dp[a][b][c][p] = 0;
	} else {
	    if (p == 1 && b > 0) {
		amin(dp[a][b][c][p], -dp[a][b][c][0]);
	    }
	    if (b > 0) {
		amin(dp[a][b][c][p], 1 - dp[a][b-1][c][1]);
	    }
	    if (a > 0) {
		amin(dp[a][b][c][p], 1 - dp[a-1][b+1][c][1]);
	    }
	    if (c == 1) {
		amin(dp[a][b][c][p], 1 - dp[a][b][0][1]);
	    }
	}
    }
}

int N;
char S[100011];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);

    int a = 0, b = 0, c;

    if (N % 2 == 1 && S[N/2] == '0') c = 1;
    else c = 0;

    REP (i, N/2) {
	if (S[i] == '0' && S[N-1-i] == '0') a++;
	else if (S[i] != S[N-1-i]) b++;
    }

    int d = dp[a][b][c][1];
    //eprintf("d = %d\n", d);
    if (d == 0) {
	puts("DRAW");
    } else if (d > 0) {
	puts("BOB");
    } else {
	puts("ALICE");
    }
}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}