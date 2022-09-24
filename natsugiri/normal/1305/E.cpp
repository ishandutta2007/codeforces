#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int M;
int A[5011];

void MAIN() {
    scanf("%d%d", &N, &M);

    int limit = 0;
    REP (i, N) limit += i/2;

    if (limit >= M) {
	int sub = limit - M;
	for (int i=N-1; i>=0; i--) {
	    int b = i/2;
	    int g = min(b, sub);
	    if (g == 0) {
		A[i] = i+1;
	    } else if (g == b) {
		A[i] = 100000000 + 10000 * (i+1);
	    } else {
		A[i] = i+1+g*2;
	    }
	    sub -= g;
	}
	assert(sub == 0);
	rprintf("%d", A, A+N);

//#ifdef MYTEST
//	int cnt = 0;
//	REP (i, N) {
//	    int j = i+1, k = j+1;
//	    for (; j<N; j++) {
//		while (k < N && A[i]+A[j] > A[k]) k++;
//		if (k >= N) break;
//		if (A[i]+A[j] == A[k]) cnt++;
//	    }
//	}
//	eprintf("%d\n", cnt);
//	assert(cnt == M);
//#endif
    } else {
	puts("-1");
	return;
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}