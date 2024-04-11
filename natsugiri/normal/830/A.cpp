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

int N, K, P;
int A[1111];
int B[2222];

void MAIN() {
    scanf("%d%d%d", &N, &K, &P);
    REP (i, N) scanf("%d", A+i);
    REP (i, K) scanf("%d", B+i);
    sort(A, A+N);
    sort(B, B+K);

    LL ans = 1LL<<60;;
    for (int d=0; d<K-N+1; d++) {
	LL ma = 0;
	REP (i, N) {
	    LL tmp = (LL)abs(A[i] - B[i+d]) + abs(B[i+d] - P);
	    amax(ma, tmp);
	}
	amin(ans, ma);
    }

    printf("%lld\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}