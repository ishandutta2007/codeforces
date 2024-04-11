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
int A[511];

LL calc(LL k) {
    if (k == 0) return 1LL<<60;

    LL tmp = 0;
    REP (i, N) {
	LL z = (A[i] + k) / (k + 1);
	if (z * k <= A[i] && A[i] <= z * (k+1)) {
	    tmp += z;
	} else {
	    return 1LL<<60;
	}
    }
    return tmp;
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    LL ans = 1LL<<60;
    for (int k=1; k <= 34000; k++) {
	amin(ans, calc(k));
	if (k <= A[0]) {
	    amin(ans, calc(A[0] / k));
	    amin(ans, calc(A[0] / k - 1));
	}
    }
    printf("%lld\n", ans);

    return 0;
}