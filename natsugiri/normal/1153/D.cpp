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

const int MAXN = 300011;
int N;
int O[MAXN];
VI G[MAXN];
int sz[MAXN];
int dp[MAXN];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", O+i);
    REP (i, N-1) {
	int f;
	scanf("%d", &f);
	f--;
	G[f].push_back(i+1);
    }

    VI ord;
    ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) {
	    ord.push_back(*e);
	}
    }

    REP (i_, N) {
	int v = ord[N-1-i_];
	sz[v] = 0;
	EACH (e, G[v]) sz[v] += sz[*e];

	if (G[v].empty()) {
	    dp[v] = 0;
	    sz[v] = 1;
	} else if (O[v] == 0) {// min;
	    EACH (e, G[v]) {
		dp[v] += dp[*e];
	    }
	} else { // max;
	    EACH (e, G[v]) {
		amax(dp[v], sz[v] - sz[*e] + dp[*e]);
	    }
	}
    }

    printf("%d\n", dp[0] + 1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}