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

#ifdef LOCAL
const int MAGIC = 4000;
#else
const int MAGIC = 2000;
#endif
LL N;
int A[MAGIC+1];

void MAIN() {
    scanf("%lld", &N);

    for (LL i=MAGIC; i>=2; i--) {
	LL t = i*(i-1)/2;
	A[i] = 0;
	while (N >= t) {
	    A[i]++;
	    N -= t;
	}
    }

    putchar('1');
    int cnt = 1;
    for (int i=1; i<=MAGIC; i++) {
	putchar('3');
	cnt++;
	cnt += A[i];
	REP (j, A[i]) putchar('7');
    }
    putchar('\n');
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}