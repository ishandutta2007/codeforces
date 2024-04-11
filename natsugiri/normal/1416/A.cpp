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
const int INF = 1<<29;

int N;
int last[300011];
int W[300011];
int ans[300011];

void MAIN() {
    scanf("%d", &N);

    REP (i, N) {
	last[i] = -1;
	W[i] = 0;
    }

    REP (i, N) {
	int a;
	scanf("%d", &a);
	a--;
	amax(W[a], i-last[a]);
	last[a] = i;
    }

    REP (i, N) amax(W[i], N-last[i]);


    REP (i, N+1) ans[i] = INF;

    REP (i, N) amin(ans[W[i]], i+1);
    REP (i, N+1) amin(ans[i+1], ans[i]);
    REP (i, N+1) if (ans[i] == INF) ans[i] = -1;
    rprintf("%d", ans+1, ans+1+N);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}