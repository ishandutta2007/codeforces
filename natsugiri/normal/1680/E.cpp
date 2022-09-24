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
char F[2][2000111];
int cur[2], nxt[2];


void MAIN() {
    scanf("%d%s%s", &N, F[0], F[1]);

    VI X;
    REP (j, N) if (F[0][j] == '*' || F[1][j] == '*') {
	X.push_back(j);
    }

    REP (i, X.size()) {
	if (i == 0) {
	    cur[0] = cur[1] = 1;
	    if (F[1][X[i]] == '.') cur[0] = 0;
	    if (F[0][X[i]] == '.') cur[1] = 0;
	} else {
	    int d = X[i] - X[i-1];
	    nxt[0] = nxt[1] = min(cur[0], cur[1]) + 1 + d;

	    if (F[1][X[i]] == '.') amin(nxt[0], cur[0] + d);
	    if (F[0][X[i]] == '.') amin(nxt[1], cur[1] + d);

	    cur[0] = nxt[0];
	    cur[1] = nxt[1];
	}
    }

    int ans = min(cur[0], cur[1]);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}