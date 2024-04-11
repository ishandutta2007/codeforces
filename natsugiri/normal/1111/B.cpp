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

int N, K, M;
int A[100011];

void MAIN() {
    scanf("%d%d%d", &N, &K, &M);
    REP (i, N) scanf("%d", A+i);

    sort(A, A+N);

    LL sum = 0;
    REP (i, N) sum += A[i];

    double ans = 0;

    REP (i, N) {
	if (i <= M) {
	    LL g = min((LL)(N-i)*K, (LL)M-i);
	    amax(ans, (double)(sum+g) / (N-i));
	}
	sum -= A[i];
    }

    printf("%.20f\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}