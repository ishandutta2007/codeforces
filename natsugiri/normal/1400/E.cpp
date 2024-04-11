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
int A[5011];

int rec(int L, int R, int target) {
    int n = R - L;
    if (n <= 0) return 0;

    int s = L;
    for (int i=L; i<R; i++) {
	if (A[s] > A[i]) s = i;
    }

    int lp = rec(L, s, A[s]);
    int rp = rec(s+1, R, A[s]);
    LL cst = n;
    amin(cst, (LL)lp + rp + A[s] - target);

    return cst;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    int ans = rec(0, N, 0);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}