#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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

VI query(int len) {
    printf("? 1 %d\n", len);
    fflush(stdout);

    VI ret;
    REP (i, len) {
	int x;
	scanf("%d", &x);
	x--;
	ret.push_back(x);
    }
    return ret;
}

void MAIN() {
    scanf("%d", &N);
    int lo = 0, hi = N;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	VI v = query(mid);
	int cnt = 0;
	EACH (e, v) if (*e >= mid) cnt++;

	if (mid % 2 == cnt % 2) {
	    lo = mid;
	} else {
	    hi = mid;
	}
    }

    printf("! %d\n", hi);
    fflush(stdout);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}