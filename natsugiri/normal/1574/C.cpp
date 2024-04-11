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
LL A[200011];
int M;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);
    sort(A, A+N);
    LL sum = 0;
    REP (i, N) sum += A[i];

    scanf("%d", &M);
    REP ($, M) {
	LL x, y;
	scanf("%lld%lld", &x, &y);

	int k = lower_bound(A, A+N, x) - A;
	LL ans = 1LL<<60;

	auto update = [&](LL a) {
	    LL D = sum - a;
	    LL cst = 0;
	    if (a < x) cst += x - a;
	    if (D < y) cst += y - D;
	    amin(ans, cst);
	};

	if (k < N) update(A[k]);
	if (k) update(A[k-1]);

	printf("%lld\n", ans);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}