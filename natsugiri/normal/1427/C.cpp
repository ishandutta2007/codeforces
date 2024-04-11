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

int N;
int T[100011];
int X[100011];
int Y[100011];
int val[100011];


void MAIN() {
    int R;
    scanf("%d%d", &R, &N);
    REP (i, N) scanf("%d%d%d", T+i, X+i, Y+i);

    const int INF = 1<<29;
    REP (i, N) {
	val[i] = -INF;
	if (X[i] + Y[i] - 2 <= T[i]) val[i] = 1;

	for (int j=i-1; j>=0; j--) {
	    if (abs(X[i]-X[j]) + abs(Y[i]-Y[j]) <= T[i]-T[j]) {
		amax(val[i], val[j] + 1);
	    }
	    if (T[i]-T[j] > 2000) break;
	}
    }

    int ans = 0;
    REP (i, N) amax(ans, val[i]);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}