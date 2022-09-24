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

int N;
LL A[200011];
LL D[19][200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    REP (i, N-1) D[0][i] = abs(A[i] - A[i+1]);

    REP (t, 18) {
	REP (i, N-1) {
	    if (i + (2<<t) <= N-1) {
		D[t+1][i] = gcd(D[t][i], D[t][i + (1<<t)]);
	    } else {
		D[t+1][i] = 1;
	    }
	}
    }

    int ans = 1;
    REP (i, N-1) {
	LL g = 0;
	int x = i;
	for (int t=19; t-- && x < N-1;) {
	    LL tmp = gcd(g, D[t][x]);
	    if (tmp != 1) {
		g = tmp;
		x += 1<<t;
	    }
	}

	amax(ans, x-i+1);
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}