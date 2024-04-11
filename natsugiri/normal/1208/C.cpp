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
int A[1011][1011];

void MAIN() {
    scanf("%d", &N);
    int s = 0;
    for (int i=0; i<N; i+=4) for (int j=0; j<N; j+=4) {
	REP (y, 4) REP (x, 4) A[i+y][j+x] = s++;
    }

    REP (i, N) rprintf("%d", A[i], A[i]+N);

    REP (i, N) {
	int x = 0;
	REP (j, N) x ^= A[i][j];
	eprintf("%d ", x);
	assert(x == 0);
    }
    REP (j, N) {
	int x = 0;
	REP (i, N) x ^= A[i][j];
	eprintf("%d ", x);
	assert(x == 0);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}