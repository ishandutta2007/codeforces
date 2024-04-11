#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

int query(int l, int r) {
    assert(r-l+1 >= 2);
    printf("? %d %d\n", l+1, r);
    fflush(stdout);

    int ret;
    scanf("%d", &ret);
    return ret-1;
}

int LEFT(int second, int right) {
    int lo = second + 1;
    int hi = right;
    while (hi - lo > 1) {
	int mid = (hi + lo) / 2;
	int q = query(second, mid);
	if (q == second) hi = mid;
	else lo = mid;
    }
    return lo;
}

int RIGHT(int left, int right) {
    int lo = left;
    int hi = right-1;
    while (hi - lo > 1) {
	int mid = (hi + lo) / 2;
	int q = query(mid, right);
	if (q == right-1) lo = mid;
	else hi = mid;
    }
    return lo;
}


void MAIN() {
    scanf("%d", &N);

    int ans;
    if (N == 1) {
	ans = 0;
    } else {
	int second = query(0, N);
	if (second == 0) {
	    ans = LEFT(0, N);
	} else if (second == N-1) {
	    ans = RIGHT(0, N);
	} else if (second == query(second, N)) {
	    ans = LEFT(second, N);
	} else {
	    ans = RIGHT(0, second+1);
	}
    }

    printf("! %d\n", ans+1);
    fflush(stdout);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}