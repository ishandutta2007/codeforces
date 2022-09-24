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
const LL INF = 1LL<<60;
struct Seg {
    LL all;
    LL left;
    LL right;
    LL best;
    Seg() {}
    Seg(LL a): all(a), left(max(0LL, a)), right(max(0LL, a)), best(max(0LL, a)) {}
};

Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    z.all = x.all + y.all;
    z.left = max(x.left, x.all + y.left);
    z.right = max(y.right, y.all + x.right);
    z.best = max(x.best, max(y.best, x.right + y.left));
    return z;
}

int N, Q;
int A[1<<18];
int LEN;

Seg B[19][1<<18];

void MAIN() {
    scanf("%d", &N);
    LEN = 1<<N;
    REP (i, LEN) scanf("%d", A+i);
    scanf("%d", &Q);

    REP (i, LEN) {
	B[0][i] = A[i];
    }
    for (int t=0; t<N; t++) {
	REP (s, LEN) {
	    B[t+1][s] = B[t][s] + B[t][s^(1<<t)];
	}
    }

    int mask = 0;
    REP ($, Q) {
	int K;
	scanf("%d", &K);
	mask ^= 1<<K;
	printf("%lld\n", B[N][mask].best);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}