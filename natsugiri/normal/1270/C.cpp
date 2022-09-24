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

    LL s = 0, x = 0;
    REP (i, N) {
	s += A[i];
	x ^= A[i];
    }

    LL a = 0, b = 0, c = 0;
    REP (i, 60) {
	LL p = (s+a+b+c)>>i&3;
	LL q = (2*(x^a^b^c))>>i&3;
	if ((p&1) != (q&1)) {
	    a ^= 1LL<<i;
	    if (~p&2) {
		b ^= 1LL<<i;
		c ^= 1LL<<i;
	    }
	}
    }

    puts("3");
    printf("%lld %lld %lld\n", a, b, c);
    eprintf("%llx %llx\n", s+a+b+c, (x^a^b^c)*2);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}