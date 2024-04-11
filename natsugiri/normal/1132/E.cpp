#include<bitset>
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

LL W;
LL C[9];

const int LIMIT = 1000;
const int SIZE = 2048;

bitset<2048> dp;

void MAIN() {
    scanf("%lld", &W);
    for (int i=1; i<=8; i++) scanf("%lld", C+i);

    LL Hi, Lo;
    if (W < LIMIT) {
	Hi = W;
	Lo = 0;
    } else {
	Hi = LIMIT;
	Lo = W-LIMIT;
    }
    LL B = 0;

    dp[0] = true;

    for (int i=1; i<=8; i++) {
	LL g = min(8LL, C[i]);
	C[i] -= g;
	LL t = min(C[i], (Lo-B)/i);

	B += t * i;
	C[i] -= t;

	int loop = min((LL)SIZE, g + C[i]);

	REP (k, loop) {
	    dp |= dp << i;
	}
    }

    LL ans = B;
    REP (j, SIZE) if (dp.test(j) && B + j <= W) amax(ans, B + j);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}