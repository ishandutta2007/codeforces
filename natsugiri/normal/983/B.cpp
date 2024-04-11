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
int A[5011];
int F[5011][5011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) F[i][i+1] = A[i];
    for (int i=N-1; i>=0; i--) for (int len=2; i+len<=N; len++) {
	F[i][i+len] = F[i][i+len-1] ^ F[i+1][i+len];
    }
    for (int i=N-1; i>=0; i--) for (int len=2; i+len<=N; len++) {
	amax(F[i][i+len], F[i][i+len-1]);
	amax(F[i][i+len], F[i+1][i+len]);
    }

    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;
	printf("%d\n", F[l][r]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}