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

int N, M, K;
LL TA, TB;
LL A[200011];
LL B[200011];

void MAIN() {
    scanf("%d%d%lld%lld%d", &N, &M, &TA, &TB, &K);
    REP (i, N) scanf("%lld", A+i), A[i] += TA;
    REP (j, M) scanf("%lld", B+j);

    LL ans = -1;
    int posB = 0;
    REP (a, N+1) {
	if (a > K) break;
	if (a == N) {
	    ans = -1;
	    break;
	}

	while (posB < M && B[posB] < A[a]) posB++;

	if (M <= posB + K - a) {
	    ans = -1;
	    break;
	}
	amax(ans, B[posB+K-a]+TB);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}