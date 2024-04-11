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
char S[2011];

const int ALICE = 0;
const int DRAW = 1;
const int BOB = 2;
int F(int a, int b, int z) {
    if (z == DRAW) {
	if (a < b) return ALICE;
	if (a > b) return BOB;
	return DRAW;
    }
    return z;
}
int dp[2011][2011];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    REP (i, N+1) dp[i][i] = DRAW;
    for (int i=N-2; i>=0; i--) {
	for (int j=i+2; j<=N; j+=2) {
	    int left_left = F(S[i], S[i+1], dp[i+2][j]);
	    int left_right = F(S[i], S[j-1], dp[i+1][j-1]);
	    int right_left = F(S[j-1], S[i], dp[i+1][j-1]);
	    int right_right = F(S[j-1], S[j-2], dp[i][j-2]);

	    int left = max(left_left, left_right);
	    int right = max(right_left, right_right);

	    dp[i][j] = min(left, right);
	}
    }

    if (dp[0][N] == ALICE) puts("Alice");
    else if (dp[0][N] == BOB) puts("Bob");
    else puts("Draw");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}