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

int N;
char S[111];

bool dp[111][2][2];

void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    memset(dp, 0, sizeof dp);
    dp[0][0][0] = true;
    REP (i, N) {
	REP (a, 2) REP (prv, 2) if (dp[i][a][prv]) {
	    REP (nxt, 2) {
		if (nxt == 0 && a == 1 && S[i] == '0') continue;
		if (prv == 1 && nxt == 1) continue;

		if (nxt == 0) {
		    dp[i+1][S[i]-'0'][0] = true;
		} else {
		    dp[i+1][a][1] = true;
		}
	    }
	}
    }

    bool yes = false;
    REP (a, 2) REP (b, 2) if (dp[N][a][b]) yes = true;
    puts(yes? "YES": "NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}