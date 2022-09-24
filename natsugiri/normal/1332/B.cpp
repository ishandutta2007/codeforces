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
const int P[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int N;
int A[1011];
int use[12];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    memset(use, 0, sizeof use);
    REP (i, N) {
	REP (j, 11) if (A[i] % P[j] == 0) {
	    A[i] = j;
	    use[j] = 1;
	    break;
	}
    }

    REP (j, 11) use[j+1] += use[j];

    REP (i, N) {
	A[i] = use[A[i]];
    }
    printf("%d\n", use[11]);
    rprintf("%d", A, A+N);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}