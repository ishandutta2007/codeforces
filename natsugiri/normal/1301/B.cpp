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
LL A[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    int c = count(A, A+N, -1);
    LL m, k;
    if (c == N) {
	m = k = 0;
    } else {
	LL ma = 0, mi = 1e9;
	REP (i, N-1) {
	    LL a = A[i], b = A[i+1];
	    if (a == -1 && b != -1) {
		amax(ma, b);
		amin(mi, b);
	    }
	    if (a != -1 && b == -1) {
		amax(ma, a);
		amin(mi, a);
	    }
	}

	k = (ma + mi) / 2;
	REP (i, N) if (A[i] == -1) A[i] = k;

	m = 0;
	REP (i, N-1) amax(m, abs(A[i] - A[i+1]));
    }

    printf("%lld %lld\n", m, k);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}