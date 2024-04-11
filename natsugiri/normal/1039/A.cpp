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

const int MAXN = 200011;
int N;
LL T;
LL A[MAXN];
LL B[MAXN];
int X[MAXN];
int MI[MAXN];

const LL INF = 3e18;

void MAIN() {
    scanf("%d%lld", &N, &T);
    REP (i, N) scanf("%lld", A+i);
    REP (i, N) scanf("%d", X+i), X[i]--;

    REP (i, N) {
	B[i] = A[i+1]+T;
	MI[i] = N;
    }
    REP (i, N) amin(MI[X[i]], i);
    B[N-1] = INF;

    REP (i, N) {
	if (X[i] < N-1) {
	    amin(B[X[i]], A[X[i]+1]+T-1);
	}
    }

    bool yes = true;
    int mi = N;
    for (int i=N-1; i>=0; i--) {
	if (X[i] < i) yes = false;

	if (i<N-1 && B[i] < A[i+1] + T && mi <= i) {
	    yes = false;
	}

	if (i<N-1 && B[i] >= B[i+1]) {
	    yes = false;
	}
	amin(mi, MI[i]);
    }
    if (B[0] < 1) yes = false;

    if (yes) {
	puts("Yes");
	rprintf("%lld", B, B+N);
    } else {
	puts("No");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}