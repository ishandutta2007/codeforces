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
char S[200011];
int sums[200011];
bool ok(int mid) {
    int r = 0;
    REP (i, N) {
	while (r < N && (r+1-i) - (sums[r+1]-sums[i]) <= mid) {
	    r++;
	}
	if (r-i - (sums[r]-sums[i]) <= mid && sums[i] + sums[N]-sums[r] <= mid) {
	    return true;
	}
    }
    return false;
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    REP (i, N) sums[i+1] = sums[i] + (S[i] - '0');

    int lo = -1, hi = N+1;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }
    printf("%d\n", hi);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}