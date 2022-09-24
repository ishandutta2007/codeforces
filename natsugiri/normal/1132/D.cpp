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

LL A[200011];
LL B[200011];
LL C[200011];
VI G[200011];

bool ok(LL mid) {
    memset(C, 0, sizeof C);
    REP (k, K+1) G[k].clear();
    REP (i, N) {
	LL x = A[i] / B[i] + 1;
	if (x <= K) G[x].push_back(i);
    }

    int pos = 0;
    REP (k, K) {
	while (pos <= K && G[pos].empty()) pos++;
	if (pos <= k) return false;

	if (pos <= K) {
	    int v = G[pos].back(); G[pos].pop_back();

	    LL nxt = A[v] + C[v] + mid;
	    LL x = nxt / B[v] + 1;

	    if (x <= k+1) return false;
	    if (x <= K) G[x].push_back(v);
	    C[v] += mid;
	}
    }
    while (pos <= K) {
	if (!G[pos].empty()) return false;
	pos++;
    }
    return true;
}


void MAIN() {
    scanf("%d%d", &N, &K);
    K--;
    REP (i, N) scanf("%lld", A+i);
    REP (i, N) scanf("%lld", B+i);

    LL lo = -1, hi = 1LL<<60;
    if (!ok(hi)) {
	puts("-1");
	return;
    }
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	(ok(mid)? hi: lo) = mid;
    }
    printf("%lld\n", hi);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}