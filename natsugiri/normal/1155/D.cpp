#include<queue>
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
LL X;
LL A[300011];

void MAIN() {
    scanf("%d%lld", &N, &X);
    REP (i, N) scanf("%lld", A+i);

    LL ans = 0;
    LL s0 = 0, s1 = 0, s2 = 0;
    REP (i, N) {
	s2 = max(s2 + A[i], s1 + A[i]);
	s1 = max(s1 + A[i] * X, s0 + A[i] * X);
	s0 = max(0LL, max(s0 + A[i], A[i]));
	amax(ans, s0);
	amax(ans, s1);
	amax(ans, s2);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}