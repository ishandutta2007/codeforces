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

int N;
LL K;
LL A[200011];
LL sums[200011];

void MAIN() {
    scanf("%d%lld", &N, &K);
    REP (i, N) scanf("%lld", A+i);

    sort(A, A+N);
    REP (i, N) sums[i+1] = sums[i] + A[i];

    LL ans = 1LL<<60;

    REP (c, N) {
	LL p = sums[N-c] - sums[1];

	LL x = (K-p) / (c+1);
	while ((c+1) * x < K-p) x++;
	while ((c+1) * x > K-p) x--;

	LL tmp;
	if (A[0] <= x) tmp = 0;
	else tmp = A[0] - x;
	amin(ans, tmp + c);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}