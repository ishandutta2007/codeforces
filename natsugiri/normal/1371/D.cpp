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

int N, K;
int R[311], C[311];
int A[311][311];

int eval(int *X) {
    int mi = *min_element(X, X+N);
    int ma = *max_element(X, X+N);
    return (ma - mi) * (ma - mi);
}

void MAIN() {
    scanf("%d%d", &N, &K);
    memset(R, 0, sizeof R);
    memset(C, 0, sizeof C);
    REP (i, N) memset(A[i], 0, sizeof (int) * N);
    
    REP (i, N) REP (j, N) if (K) {
	int k = (i+j) % N;
	R[j]++;
	C[k]++;
	A[j][k] = 1;
	K--;
    }
    assert(K == 0);

    int ans = eval(R) + eval(C);
    printf("%d\n", ans);
    REP (i, N) {
	REP (j, N) putchar('0' + A[i][j]);
	putchar('\n');
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}