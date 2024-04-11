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

int R, C;
int A[555][555];

void MAIN() {
    scanf("%d%d", &R, &C);

    if (R == 1 && C == 1) {
	A[0][0] = 0;
    } else if (R == 1) {
	REP (j, C) A[0][j] = j+2;
    } else if (C == 1) {
	REP (i, R) A[i][0] = i+2;
    } else {
	REP (i, R) REP (j, C) {
	    A[i][j] = (i+C+1) * (j+1);
	}
    }

    REP (i, R) rprintf("%d", A[i], A[i]+C);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}