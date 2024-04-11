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
LL A[200011];
int W[200011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%lld", A+i);
    REP (i, K) scanf("%d", W+i);

    sort(A, A+N);
    sort(W, W+K);
    LL ans = 0;
    int idx = N;
    REP (i, K) if (W[i] == 1) {
	ans += A[--idx] * 2;
	W[i] = 0;
    }
    REP (i, K) if (W[i]) {
	ans += A[--idx];
	W[i]--;
    }
    REP (i, K) if (W[i]) {
	idx -= W[i];
	ans += A[idx];
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}