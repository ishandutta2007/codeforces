#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
int B[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    int idx = N - 1;
    for (int i=0; i<N; i+=2) {
	B[i] = A[idx];
	idx--;
    }
    for (int i=1; i<N; i+=2) {
	B[i] = A[idx];
	idx--;
    }

    int ans = 0;
    for (int i=1; i<N-1; i++) {
	if (B[i-1] > B[i] && B[i] < B[i+1]) ans++;
    }

    printf("%d\n", ans);
    rprintf("%d", B, B+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}