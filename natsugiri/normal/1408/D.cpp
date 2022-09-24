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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M;
struct Point {
    int x, y;
};
Point P[2011];
Point S[2011];

const int LIMIT = 1000010;
int High[LIMIT+11];
int Cost[LIMIT+11];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d%d", &P[i].x, &P[i].y);
    REP (i, M) scanf("%d%d", &S[i].x, &S[i].y);

    memset(High, -1, sizeof High);
    REP (i, M) {
	amax(High[S[i].x], S[i].y);
    }

    for (int x=LIMIT-1; x>=0; x--) amax(High[x], High[x+1]);

    VI Xs;
    REP (x, LIMIT-1) if (High[x] > High[x+1]) {
	Xs.push_back(x);
    }

    REP (i, N) {
	int x = P[i].x, y = P[i].y;
	if (High[x] < y) continue;

	amax(Cost[0], High[x] - y + 1);

	REP (j, Xs.size()) {
	    if (x <= Xs[j]) {
		amax(Cost[Xs[j] - x], High[Xs[j]] - y + 1);
	    }
	}
    }

    for (int x=LIMIT-1; x>=0; x--) amax(Cost[x], Cost[x+1]);

    int ans = LIMIT * 2;
    REP (x, LIMIT) amin(ans, x + Cost[x]);
    printf("%d\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}