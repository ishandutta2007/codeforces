#include<cassert>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

// typedef long long LL;
typedef unsigned long long ULL;

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

int N, M;
int A[100111];
int B[100111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    REP (i, M) scanf("%d", B+i);

//    N = M = 100000;
//    REP (i, N) A[i] = B[i] = 1e9;

    sort(A, A+N);
    sort(B, B+M);

    ULL ans = -1ULL;

    ULL sumA = 0, sumB = 0, cnt = 0;
    REP (i, N) sumA += A[i];
    REP (i, M) sumB += B[i];
    for (int i=N; i--;) {
	cnt++;
	sumA -= A[i];
	amin(ans, sumA + sumB * cnt);
    }

    sumA = 0; sumB = 0; cnt = 0;
    REP (i, N) sumA += A[i];
    REP (i, M) sumB += B[i];
    for (int i=M; i--;) {
	cnt++;
	sumB -= B[i];
	amin(ans, sumB + sumA * cnt);
    }

    printf("%llu\n", ans);
    return 0;
}