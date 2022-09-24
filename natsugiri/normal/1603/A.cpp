#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

LL gcd(LL x_, LL y_) {
    typedef unsigned long long ULL;
    ULL x = abs(x_);
    ULL y = abs(y_);
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

LL lcm(LL x, LL y) {
    assert(x >= 1);
    assert(y >= 1);
    return x/gcd(x, y)*y;
}

LL X[40];
void init() {
    X[0] = 1;
    X[1] = 1;
    for (int i=2; i<40; i++) {
	X[i] = lcm(X[i-1], i);
    }
}
int N;
LL A[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    bool yes = true;
    REP (i, N) {
	LL b = X[i+2];

	if (A[i] % b == 0) {
	    yes = false;
	    break;
	}
	if (b >= 1000000000) break;
    }

    puts(yes? "YES": "NO");
}

int main() {
    init();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}