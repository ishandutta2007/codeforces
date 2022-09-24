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
int A[500111];
LL solve(int k) {
    LL ret = 0;
    REP (i, N) {
	if (i < k) ret -= A[i];
	else ret += A[i];
    }
    return ret;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    if (N == 1) {
	printf("%d\n", A[0]);
    } else {
	LL ans;
	ans = solve(1);
	amax(ans, solve(N-1));
	int k = lower_bound(A, A+N, 0) - A;
	if (0 < k && k < N) amax(ans, solve(k));
	printf("%lld\n", ans);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}