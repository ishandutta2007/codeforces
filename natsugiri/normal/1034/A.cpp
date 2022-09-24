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

unsigned gcd(unsigned x, unsigned y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}
int N;
int A[300011];
const int SIZE = 15000001;
int C[SIZE]; // 60MB
bool nonP[SIZE];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    if (*max_element(A, A+N) == *min_element(A, A+N)) {
	puts("-1");
	return;
    }

//    N = 300000;
//    REP (i, N) A[i] = 15000000;
//    A[0]--;

//    REP (i, N) {
//	for (int t=1; t*t<=A[i]; t++) {
//	    if (A[i] % t == 0) {
//		C[t]++;
//		if (t*t < A[i]) C[A[i]/t]++;
//	    }
//	}
//    }
    unsigned g = A[0];
    REP (i, N) g = gcd(g, A[i]);
    REP (i, N) A[i] /= g;

    int ans = N;
    REP (i, N) C[A[i]]++;
    C[1] = N;
    for (int p=2; p<SIZE; p++) if (!nonP[p]) {
	int cnt = C[p];
	for (int i=p+p; i<SIZE; i+=p) {
	    cnt += C[i];
	    nonP[i] = true;
	}
	amin(ans, N-cnt);
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}