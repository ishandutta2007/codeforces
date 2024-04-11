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
int A[100111];
char B[100111];
const int INF = 1e9;

bool same(char a, char b, char c, char d) {
    return a == b && b == c && c == d;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    scanf("%s", B);

    int l_lo = INF, l_hi = -INF, r_lo = INF, r_hi = -INF;
    for (int i=4; i<N; i++) {

	if (B[i-1] == '0' && B[i] == '0') {
	    if (same('0', B[i-4], B[i-3], B[i-2])) {
		amin(l_lo, *max_element(A+i-4, A+i+1));
	    }
	} else if (B[i-1] == '1' && B[i] == '1') {
	    if (same('1', B[i-4], B[i-3], B[i-2])) {
		amax(r_hi, *min_element(A+i-4, A+i+1));
	    }
	} else if (B[i-1] == '0' && B[i] == '1') {
	    for (int k=i-4; k<=i; k++) amax(l_hi, A[k]+1);
	} else {
	    for (int k=i-4; k<=i; k++) amin(r_lo, A[k]-1);
	}
    }

    printf("%d %d\n", l_hi, r_lo);
//    eprintf("%d %d\n", l_hi, r_hi);
//    eprintf("%d %d\n", l_lo, r_lo);
//
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}