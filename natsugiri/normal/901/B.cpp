#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;

struct P {
    int c[161];
    P() { memset(c, 0, sizeof c); }
    P(int a) { memset(c, 0, sizeof c); c[0] = a; }
    P(int a, int b) { memset(c, 0, sizeof c); c[0] = a; c[1] = b; }
};

P shift(const P &x, int c0, int c1) {
    P z;
    if (c0) {
	REP (i, N+1) z.c[i] += x.c[i] * c0;
    }
    if (c1) {
	REP (i, N+1) z.c[i+1] += x.c[i] * c1;
    }

    return z;
}
P add(P x, const P &y) {
    REP (i, N+1) x.c[i] += y.c[i];
    return x;
}

const int d0[] = {1, -1, 1, -1, 0, 0, 2, -2, 2, -2};
const int d1[] = {1, 1, -1, -1, 1, -1, 1, 1, -1, -1};


bool rec(int depth, P x, P y) {
    if (depth == N) {
	if (x.c[N] == -1) REP (i, N+1) x.c[i] = -x.c[i];
	printf("%d\n", N);
	rprintf("%d", x.c, x.c+N+1);
	if (y.c[N-1] == -1) REP (i, N) y.c[i] = -y.c[i];
	printf("%d\n", N-1);
	rprintf("%d", y.c, y.c+N);
	return true;
    }

    REP (d, 6) {
	P z = add(shift(x, d0[d], d1[d]), y);
	bool yes = true;
	REP (j, depth+2) if (z.c[j] < -1 || 1 < z.c[j]) { yes = false; break; }
	if (yes) {
	    if (rec(depth+1, z, x)) {
		return true;
	    }
	}
    }
    return false;
}

void MAIN() {
    scanf("%d", &N);
    P x(1), y;
    rec(0, x, y);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}