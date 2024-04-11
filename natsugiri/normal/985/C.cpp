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

int N, K, L, M;
int A[100011];

void MAIN() {
    scanf("%d%d%d", &N, &K, &L);
    M = N * K;

    REP (i, M) scanf("%d", A+i);
    sort(A, A+M);

    if (N > 1 && A[N-1]-A[0] > L) {
	puts("0");
	return;
    }
    int pos = 0;
    while (pos < M-K+1 && A[pos] - A[0] <= L) pos++;

    LL ans = 0;
    int right = M - pos;
    pos--;

    REP (i, N) {
	while (1) {
	    if (right >= K-1) break;
	    right++;
	    pos--;
	}

//	eprintf("pos = %d %d\n", pos, A[pos]);
	ans += A[pos];
	pos--;
	right -= K-1;
    }


    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}