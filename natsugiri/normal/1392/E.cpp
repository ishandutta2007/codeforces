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

void print(int r, int c) {
    printf("%d %d\n", r+1, c+1);
    fflush(stdout);
}

int N;
LL A[111][111];

void MAIN() {
    scanf("%d", &N);

    REP (i, 100) {
	int x = i;
	REP (j, i+1) {
	    if (j % 2 == 1) A[j][x] = 1LL<<(i-1);
	    x--;
	}
    }

    REP (i, N) rprintf("%lld", A[i], A[i]+N);
    fflush(stdout);

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	LL K;
	scanf("%lld", &K);
	int y = 0, x = 0;


	print(y, x);

	REP (t, 2*N-2) {
	    bool b = K & 1;
	    if ((b && A[y][x+1]) || (!b && A[y][x+1] == 0)) {
		x++;
	    } else {
		y++;
	    }
	    print(y, x);
	    K >>= 1;
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}