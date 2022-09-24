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

LL max_subarray(LL *A, int N) { // at least 1 element
    LL s, ret; s = ret = A[0];
    for (int i=1; i<N; i++) {
	s = max(A[i], s + A[i]);
	ret = max(ret, s);
    }
    return ret;
}

int N;
LL A[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    LL a = 0;
    REP (i, N) a += A[i];
    LL b = max_subarray(A, N-1);
    LL c = max_subarray(A+1, N-1);
    if (a > b && a > c) puts("YES");
    else puts("NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}