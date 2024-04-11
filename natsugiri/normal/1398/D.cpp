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

void read(int n, VI &x) {
    x.clear();
    REP (j, n) {
	int t;
	scanf("%d", &t);
	x.push_back(t);
    }

    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());
}

int len[3];
VI R, G, B;

int dp[211][211][211];

void MAIN() {
    REP (i, 3) scanf("%d", len+i);
    read(len[0], R);
    read(len[1], G);
    read(len[2], B);

    memset(dp, 0xc0, sizeof dp);
    dp[0][0][0] = 0;
    int ans = 0;

    REP (r, R.size()+1u) REP (g, G.size()+1u) REP (b, B.size()+1u) if (dp[r][g][b] >= 0) {
	if (r < (int)R.size() && g < (int)G.size()) {
	    amax(dp[r+1][g+1][b], dp[r][g][b] + R[r] * G[g]);
	}
	if (r < (int)R.size() && b < (int)B.size()) {
	    amax(dp[r+1][g][b+1], dp[r][g][b] + R[r] * B[b]);
	}
	if (g < (int)G.size() && b < (int)B.size()) {
	    amax(dp[r][g+1][b+1], dp[r][g][b] + G[g] * B[b]);
	}

	amax(ans, dp[r][g][b]);
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}