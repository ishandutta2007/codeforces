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
LL A[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    puts("1 1");
    printf("%lld\n", -A[0]);
    A[0] = 0;

    if (N == 1) {
	REP (t, 2) {
	    puts("1 1");
	    puts("0");
	}
    } else {
	// n
	printf("1 %d\n", N);
	REP (i, N) {
	    LL g = A[i] * N;
	    printf("%lld%c", -g, " \n"[i==N-1]);
	    A[i] -= g;
	}

	// n-1
	printf("2 %d\n", N);
	for (int i=1; i<N; i++) {
	    assert(A[i] % (N-1) == 0);
	    printf("%lld%c", -A[i], " \n"[i==N-1]);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}