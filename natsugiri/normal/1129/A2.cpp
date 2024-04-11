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

int C[5011];
int X[5011];
LL ans[5011];

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, N) X[i] = N;

    REP (i, M) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	C[a]++;
	amin(X[a], (b-a+N) % N);
    }

    REP (s, N) {
	REP (i, N) {
	    int v = (s+i)%N;
	    if (C[v]) {
		amax(ans[s], (LL)(C[v]-1)*N + X[v] + i);
	    }
	}
    }
    rprintf("%lld", ans, ans+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}