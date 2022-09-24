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

int N;
int A[15];
int dp[1<<15][15][15]; // [set][index][cost] = value;
pair<int, int> prv[1<<15][15][15];

int sum[1<<15];

pair<int, int> B[15];

void MAIN() {

    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    const int size = 1<<N;
    memset(dp, -1, sizeof (dp[0]) * size);
    const int INVALID = -1;

    for (int s=1; s<(1<<N); s++) {
	sum[s] = 0;
	REP (i, N) if (s>>i&1) sum[s] += A[i];

	int k = -1;
	REP (i, N) if (s>>i&1) {
	    k = i;
	    break;
	}
	assert(k >= 0);

	int c = __builtin_popcount(s) - 1;
	dp[s][k][c] = s;
    }

    const int ALL = (1<<N)-1;
    for (int s=1; s<(1<<N); s++) {
	const int mask = ALL ^ s;

	for (int sub=mask; sub; sub=(sub-1)&mask) {
	    REP (a, N) if (s>>a&1) {
		int k = -1;
		for (int i=a+1; i<N; i++) if (sub>>i&1) {
		    k = i;
		    break;
		}
		if (k == -1) continue;

		REP (c, N) if (dp[s][a][c] != INVALID && sum[dp[s][a][c]] < sum[sub]) {
		    int cst = c + __builtin_popcount(sub) - 1;
		    if (dp[s|sub][k][cst] == INVALID || sum[dp[s|sub][k][cst]] > sum[sub]) {
			dp[s|sub][k][cst] = sub;
			prv[s|sub][k][cst] = make_pair(a, c);
		    }
		}
	    }
	}
    }

    int ans = 1<<29;
    REP (a, N) REP (c, N) if (dp[ALL][a][c] != INVALID) amin(ans, c);
    REP (a, N) REP (c, N) if (dp[ALL][a][c] != INVALID && ans == c) {
	int s = ALL;
	while (s) {
	    int sub = dp[s][a][c];
	    int na = prv[s][a][c].first;
	    int nc = prv[s][a][c].second;
	    REP (i, N) if (sub>>i&1) B[i].second = a;
	    s = s^sub;
	    a = na;
	    c = nc;
	}
	goto END;
    }

END:;
    printf("%d\n", ans);
    REP (i, N) B[i].first = i;
    int len = N;
    REP (t, ans) {
	REP (i, len) if (B[i].first != B[i].second) {
	    REP (j, len) if (B[j].first == B[i].second) {
		printf("%d %d\n", i+1, j+1);
		for (int k=i; k<len-1; k++) B[k] = B[k+1];
		len--;
		goto OUT;
	    }
	}
OUT:;
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}