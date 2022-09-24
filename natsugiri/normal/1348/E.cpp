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

LL dp_[2][511];
LL (*cur) = dp_[0];
LL (*nxt) = dp_[1];
LL A[511];
LL B[511];

void MAIN() {
    scanf("%d%d", &N, &K);

    REP (i, N) scanf("%lld%lld", A+i, B+i);

    memset(dp_, 0xc0, sizeof dp_);
    cur[0] = 0;

    LL sum = 0;
    REP (i, N) {
	memset(nxt, 0xc0, sizeof dp_[0]);

	REP (r, K) if (cur[r] >= 0) {
	    int b = (sum - cur[r]*K - r) % K;
	    for (int x=0; x<K && x<=A[i]; x++) {
		LL add = (A[i] + B[i] - x) / K;
		int y = (A[i] + B[i] - x) % K;
		if (y > B[i]) continue;

		int nr = x + r;
		int nb = y + b;
		while (nr >= K) { nr -= K; add++; }
		while (nb >= K) { nb -= K; add++; }
		amax(nxt[nr], cur[r] + add);
	    }
	}

	sum += A[i] + B[i];
	swap(cur, nxt);
    }

    LL ans = *max_element(cur, cur+K);
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}