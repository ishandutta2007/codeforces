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
char F[21][21];
LL dp[1<<14][14][1<<6];
LL ans[1<<13];

int MASK;

void reset(VI &as, int s) {
    as.clear();
    REP (i, N) if (s>>i&1) as.push_back(i);
}

int rev[1<<7];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%s", F[i]);

#ifdef MYTEST
    N = 2;
    REP (i, N) REP (j ,N) F[i][j] = '1';
#endif

    const int half = (N+1)/2;
    MASK = (1<<N)-1;

    REP (a, N) {
	dp[1<<a][a][0] = 1;
    }

    VI as, bs;
    as.reserve(N);
    bs.reserve(N);
    REP (s, 1<<N) {
	int pc = __builtin_popcount(s);

	if (pc >= half) continue;
	if (pc == 0) continue;

	reset(as, s);
	reset(bs, MASK^s);

	EACH (e, as) REP (t, 1<<6) {
	    int a = *e;
	    if (dp[s][a][t]) {
		EACH (f, bs) {
		    int b = *f;
		    int bit = (F[a][b] == '1'? 1: 0);
		    dp[s|(1<<b)][b][t*2+bit] += dp[s][a][t];
		}
	    }
	}
    }

    int len = N-half-1;
    REP (s, 1<<len) {
	int t = 0;
	REP (i, len) if (s>>i&1) t |= 1<<(len-1-i);
	rev[s] = t;
    }

    REP (s, 1<<N) {
	int pc = __builtin_popcount(s);
	if (pc != half) continue;

	reset(as, s);
	reset(bs, MASK^s);
	//eprintf("%d %d %d\n", half, (int)as.size(), (int)bs.size());
	EACH (e, as) REP (t, 1<<6) {
	    int a = *e;
	    if (!dp[s][a][t]) continue;
	    EACH (f, bs) REP (u, 1<<6) {
		int b = *f;
		if (!dp[MASK^s][b][u]) continue;

		int val = t;
		if (F[a][b] == '1') val = val*2+1;
		else val = val*2;
		val = (val<<(bs.size()-1u)) | rev[u];

		ans[val] += dp[s][a][t] * dp[MASK^s][b][u];
	    }
	}
    }

    rprintf("%lld", ans, ans+(1<<(N-1)));
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}