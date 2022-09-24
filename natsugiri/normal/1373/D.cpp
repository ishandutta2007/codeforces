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
int A[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);


    LL total = 0;
    REP (i, N) {
	if (i % 2 == 0) total += A[i];
    }

    LL ans = total;

    for (int s=0; s<2; s++) {
	int sgn = (s? -1: 1);
	LL cur = 0;
	LL ma = 0;
	for (int i=s; i+1<N; i+=2) {
	    cur += A[i] * sgn;
	    cur -= A[i+1] * sgn;
	    amax(ans, total - cur + ma);
	    amax(ma, cur);
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}