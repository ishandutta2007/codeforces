#include<bitset>
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
int A[111];
typedef bitset<10240> Bits;
Bits B[111];


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    int ans = 1;

    if (N <= 2) {
	ans = N;
    } else if (count(A, A+N, A[0]) + count(A, A+N, A[N-1]) == N) {
	ans = N;
    } else {
	B[0].set(0);

	for (int i=0; i<N;) {
	    int j = i+1;
	    while (j < N && A[i] == A[j]) j++;
	    int len = j-i;

	    REP (t, len) B[t+1].reset();

	    REP (x, N) if (x < i || i+len <= x) {
		for (int t=len-1; t>=0; t--) {
		    B[t+1] |= B[t] << A[x];
		}
	    }

	    for (int c=1; c<=len; c++) {
		if (!B[c].test(c*A[i])) {
		    amax(ans, c);
		}

		for (int t=len-1; t>=0; t--) {
		    B[t+1] |= B[t] << A[i];
		}
	    }
	    
	    i = j;
	}
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}