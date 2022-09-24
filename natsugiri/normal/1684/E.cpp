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

int ans;
VI X;
bool ok(int target, bool calc=false) {
    int idx = 0;
    int space = 0, pool = 0;
    REP (t, target) {
	if (idx < N && A[idx] == t) {
	    idx++;
	    while (idx < N && A[idx] == t) {
		idx++;
		pool++;
	    }
	} else {
	    space++;
	}
    }

    if (space > K) return false;
    if (space > pool + (N - idx)) return false;

    if (calc) {
	X.clear();

	for (; idx<N; ) {
	    int j = idx;
	    while (j < N && A[j] == A[idx]) j++;
	    X.push_back(j-idx);
	    idx = j;
	}

	sort(X.begin(), X.end());
	reverse(X.begin(), X.end());

	REP (t, space) {
	    if (X.empty()) {

	    } else if (X.back() == 1) {
		X.pop_back();
	    } else {
		X.back()--;
	    }
	}

	int diff = target + X.size();
	ans = diff - target;
    }

    return true;
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);
    sort(A, A+N);

    LL lo = 0, hi = N + 2;
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	(ok(mid)? lo: hi) = mid;
    }
    ok(lo, true);
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}