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
int A[100011];

bool ok() {
    if (N == 1 && A[0] == 0) return true;

    if (count(A, A+N, 0) == 0) return false;

    REP (i, N-1) if (A[i] >= 0 && A[i+1] >= 0) return true;

    REP (i, N) if (A[i] == 0) A[i] = 1;

    REP (t, 2) {
	int cur = 0;
	REP (i, N) {
	    if (i && cur + A[i] > 0) return true;

	    amax(cur, 0);
	    cur += A[i];
	}
	reverse(A, A+N);
    }

    return false;
}

void MAIN() {
    int K;
    scanf("%d%d", &N, &K);
    REP (i, N) {
	int a;
	scanf("%d", &a);

	if (a == K) A[i] = 0;
	else if (a < K) A[i] = -1;
	else A[i] = 1;
    }

    puts(ok()? "yes": "no");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}