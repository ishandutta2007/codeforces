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

int N;
LL A, R, M;
LL H[100011];

void MAIN() {
    scanf("%d%lld%lld%lld", &N, &A, &R, &M);
    REP (i, N) scanf("%lld", H+i);
    sort(H, H+N);

    LL ans = 1LL<<60;

    LL tmp = 0;
    REP (i, N) {
	tmp += H[i] - H[0];
    }
    amin(ans, tmp * R);

    tmp = 0;
    REP (i, N) {
	tmp += H[N-1] - H[i];
    }
    amin(ans, tmp * A);

    LL sum = 0;
    REP (i, N) sum += H[i];

    auto update = [&](LL x, LL y) {
	amin(ans, x*A + y*R);
	LL g = min(x, y);
	x -= g;
	y -= g;
	amin(ans, x*A + y*R + g*M);
    };

    LL cur = 0;
    for (int i=1; i<N; i++) {
	cur += H[i-1];
	// H[i-1] <= h <= H[i];
	// x := h * i - cur;
	// y := sum - cur - h * (N - i);
	
	LL xl = H[i-1]*i-cur;
	LL yl = sum-cur-H[i-1]*(N-i);
	LL xr = H[i]*i-cur;
	LL yr = sum-cur-H[i]*(N-i);
	update(xl, yl);
	update(xr, yr);

	if (xl < yl && xr > yr) {
	    LL lo = H[i-1], hi = H[i];
	    while (hi - lo > 1) {
		LL mid = (hi + lo) / 2;
		LL x = mid*i-cur;
		LL y = sum-cur-mid*(N-i);
		if (x <= y) lo = mid;
		else hi = mid;
	    }


	    update(lo*i-cur, sum-cur-lo*(N-i));
	    update(hi*i-cur, sum-cur-hi*(N-i));
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}