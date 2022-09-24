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

int N, K;
int A[100011];
int B[100011];

bool ok(int mid) {
    int cnt = 0;
    REP (i, N) {
	if (A[i] * 2 < mid) {
	    cnt++;
	    B[i] = 1000000000;
	} else {
	    B[i] = A[i];
	}
    }
    if (cnt > K) return false;

    REP (i, N-1) {
	int a = min(B[i], B[i+1]);
	int b = max(B[i], B[i+1]);
	if (a >= mid) return true;
	if (cnt+1 <= K && b >= mid) return true;
	if (cnt+2 <= K && 1000000000 >= mid) return true;
    }

    return false;
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    int ans = 0;
    if (N == 2) {
	sort(A, A+N);
	REP (i, K) A[i] = 1000000000;
	ans = min(A[0], A[1]);
    } else {
	LL lo = 1, hi = 1000000001;
	while (hi - lo > 1) {
	    LL mid = (lo + hi) / 2;
	    (ok(mid)? lo: hi) = mid;
	}
	ans = lo;
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}