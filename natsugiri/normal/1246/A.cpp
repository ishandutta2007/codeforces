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

LL N, P;

void MAIN() {
    scanf("%lld%lld", &N, &P);
    LL ans = 1LL<<60;

    for (int i=1; i*P <= N && i < ans && i < 1000; i++) {
	LL rest = N - i*P;
	LL mi = 0, ma = 0;
	for (int j=0; (1LL<<j) <= rest; j++) {
	    if (rest >> j & 1) {
		mi++;
		ma += 1LL<<j;
	    }
	}
	if (mi <= i && i <= ma) {
	    amin(ans, (LL)i);
	}
    }

    if (ans == (1LL<<60)) {
	puts("-1");
    } else {
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}