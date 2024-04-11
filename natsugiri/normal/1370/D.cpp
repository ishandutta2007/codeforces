#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

int N, K;
int A[200011];
int sortedA[200011];

int add;

bool ok(int val) {
    int cnt = 0;
    REP (i, N) {
	if ((cnt+add) % 2 == 0) {
	    if (A[i] <= val) cnt++;
	} else {
	    cnt++;
	}
    }

    return cnt >= K;
}

int solve() {
    int lo = -1, hi = N-1;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	(ok(sortedA[mid])? hi: lo) = mid;
    }

    return sortedA[hi];
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    REP (i, N) sortedA[i] = A[i];
    sort(sortedA, sortedA+N);

    add = 0;
    int ans0 = solve();
    add = 1;
    int ans1 = solve();
    // eprintf("%d %d\n", ans0, ans1);
    printf("%d\n", min(ans0, ans1));
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}