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
char S[200011];

int dp[200011][3][3];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    memset(dp, 0x3f, sizeof (int) * 3 * 3 * (N+1));
    dp[0][0][0] = 0;

    REP (i, N) {
	REP (a, 3) REP (b, 3) {
	    amin(dp[i+1][a][b], dp[i][a][b] + 1);

	    int na, nb;
	    if (S[i] == "one"[a]) na = a+1;
	    else if (S[i] == 'o') na = 1;
	    else na = 0;

	    if (S[i] == "two"[b]) nb = b+1;
	    else if (S[i] == 't') nb = 1;
	    else nb = 0;

	    if (na < 3 && nb < 3) {
		amin(dp[i+1][na][nb], dp[i][a][b]);
	    }
	}
    }

    int best = N+N;
    VI ans;
    REP (c, 3) REP (d, 3) amin(best, dp[N][c][d]);

    REP (c, 3) REP (d, 3) if (best == dp[N][c][d]) {
	int i = N-1;
	while (i >= 0) {
	    if (dp[i+1][c][d] == dp[i][c][d] + 1) {
		ans.push_back(i+1);
	    } else {
		REP (a, 3) REP (b, 3) {
		    int na, nb;
		    if (S[i] == "one"[a]) na = a+1;
		    else if (S[i] == 'o') na = 1;
		    else na = 0;

		    if (S[i] == "two"[b]) nb = b+1;
		    else if (S[i] == 't') nb = 1;
		    else nb = 0;

		    if (na == c && nb == d && dp[i+1][c][d] == dp[i][a][b]) {
			c = a;
			d = b;
			goto OUT;
		    }
		}
OUT:;
	    }

	    i--;
	}
	goto END;
    }
END:;

    printf("%d\n", (int)ans.size());
    reverse(ans.begin(), ans.end());
    rprintf("%d", ans.begin(), ans.end());
}


int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}