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

void MAIN() {
    scanf("%d", &N);
    vector<LL>A;
    A.reserve(N*2);
    REP (i, N*2) {
	int x;
	scanf("%d", &x);
	A.push_back(x);
    }
    sort(A.begin(), A.end());

    LL ans = 1LL<<60;
    REP (i, N+1) {
	LL x = A[i+N-1] - A[i];
	LL y_min = 1LL<<60;
	LL y_max = 0;
	if (i) {
	    amin(y_min, A[0]);
	    amax(y_max, A[i-1]);
	}
	if (i+N < 2*N) {
	    amin(y_min, A[i+N]);
	    amax(y_max, A[2*N-1]);
	}
	amin(ans, x * (y_max - y_min));
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}