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


void MAIN() {
    scanf("%d", &N);

    int second = -1;
    int lo = 0, hi = N;
    while (hi - lo >= 4) {
	if (second == -1) second = query(lo, hi);

	int mid = (lo + hi) / 2;
	if (second < mid) {
	    int q = query(lo, mid);
	    if (second == q) hi = mid;
	    else { lo = mid; second = -1; }
	} else {
	    int q = query(mid, hi);
	    if (second == q) lo = mid;
	    else { hi = mid; second = -1; }
	}
    }

    if (second == -1) second = query(lo, hi);

    int ans;
    if (hi - lo == 3) {
	int a = lo;
	int b = lo+1;
	int c = lo+2;
	if (second == a) {
	    int q = query(b, c+1);
	    ans = b + c - q;
	} else if (second == c) {
	    int q = query(a, b+1);
	    ans = a + b - q;
	} else {
	    int q = query(a, b+1);
	    if (q == b) { // a > b > c
		ans = a;
	    } else { // a < b < c
		ans = c;
	    }
	}
    } else if (hi - lo == 2) {
	ans = lo + (lo+1) - second;
    } else if (hi - lo == 1) {
	ans = lo;
    } else {
	assert(false);
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