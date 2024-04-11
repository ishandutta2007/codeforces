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
LL P[200011];
int X, A, Y, B;
LL K;
LL D[200011];

LL sums[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", P+i);
    scanf("%d%d", &X, &A);
    scanf("%d%d", &Y, &B);
    scanf("%lld", &K);

    sort(P, P+N);
    REP (i, N) sums[i+1] = sums[i] + P[i]/100;

    if (X > Y) {
	swap(X, Y);
	swap(A, B);
    }

    int ans = -1;
    int C[4] = {};
    REP (i, N) {
	int s = 0;
	if ((i+1) % A == 0) s |= 1;
	if ((i+1) % B == 0) s |= 2;
	C[s]++;

	LL tmp = (sums[N] - sums[N-C[3]]) * (X+Y)
	    + (sums[N-C[3]] - sums[N-C[3]-C[2]]) * Y
	    + (sums[N-C[3]-C[2]] - sums[N-C[3]-C[2]-C[1]]) * X;
	if (tmp >= K) {
	    ans = i+1;
	    break;
	}
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}