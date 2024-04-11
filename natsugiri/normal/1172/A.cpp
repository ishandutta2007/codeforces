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
int A[200011];
int B[200011];
int C[200011];

int solve1() {
    int ans = 0;
    for (int i=1; i<=N; i++) {
	amax(ans, N-i+C[i]+1);
    }
    return ans;
}

int solve2() {
    int pos = -1;
    REP (i, N) if (B[i] == 1) pos = i;
    if (pos == -1) return 1<<29;
    for (int i=pos; i<N; i++) {
	if (pos - B[pos] != i - B[i]) return 1<<29;
    }
    if (pos == 0) return 0;

    int done = N - pos;
    for (int i=done+1; i<=N; i++) {
	if (C[i] > i - (done+1)) return 1<<29;
    }
    return pos;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    REP (i, N) {
	if (A[i] > 0) C[A[i]] = 0;
	if (B[i] > 0) C[B[i]] = i+1;
    }

    int ans = solve1();
    amin(ans, solve2());

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}