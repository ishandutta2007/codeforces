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

int N, X;
int A[200011];

int calc(int lo, int hi) {
    int ret = 1<<30;

    amin(ret, abs(hi - A[0]));
    amin(ret, abs(lo - A[0]));
    amin(ret, abs(hi - A[N-1]));
    amin(ret, abs(lo - A[N-1]));

    REP (i, N-1) {
	amin(ret, abs(A[i] - lo) + abs(A[i+1] - hi));
	amin(ret, abs(A[i] - hi) + abs(A[i+1] - lo));
    }
    REP (i, N) {
	amin(ret, abs(A[i] - lo) + abs(A[i] - hi));
    }

    return ret + hi - lo;
}

void MAIN() {
    scanf("%d%d", &N, &X);
    REP (i, N) scanf("%d", A+i);

    int mi = *min_element(A, A+N);
    int ma = *max_element(A, A+N);


    LL ans = 0;
    REP (i, N-1) ans += abs(A[i+1] - A[i]);

    if (1 < mi) {
	ans += calc(1, min(X, mi));
    }
    if (ma < X) {
	ans += calc(max(1, ma), X);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}