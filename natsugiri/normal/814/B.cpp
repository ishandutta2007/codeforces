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
int A[1111], B[1111], P[1111];
bool C[1111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    REP (i, N) {
	memset(C, 0, sizeof C);
	REP (j, N) {
	    if (j == i) continue;
	    P[j] = A[j];
	    C[P[j]] = true;
	}
	REP (j, N) if (!C[j+1]) {
	    P[i] = j+1;
	    C[j+1] = true;
	    break;
	}

	int cntA = 0, cntB = 0;
	bool per = true;
	memset(C, 0, sizeof C);
	REP (j, N) {
	    if (A[j] == P[j]) cntA++;
	    if (B[j] == P[j]) cntB++;

	    if (C[P[j]]) per = false;
	    C[P[j]] = 1;

	}

	if (per && cntA == N-1 && cntB == N-1) {
	    rprintf("%d", P, P+N);
	    return;
	}
    }

    // never reach here;
    rprintf("%d", A, A+N);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}