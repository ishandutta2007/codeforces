#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<cmath>

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
LL K;
LL A[100011];
LL X[100011];
LL B[100011];

void MAIN() {
    scanf("%d%lld", &N, &K);
    REP (i, N) scanf("%lld", A+i);

    REP (i, N) {
	LL hint = sqrt(A[i] / 3.0);
	X[i] = hint;
	LL best = hint * (A[i] - hint * hint);
	LL x = hint-1;
	while (x >= 0) {
	    LL tmp = x * (A[i] - x * x);
	    if (best < tmp) {
		X[i] = x;
		best = tmp;
		x--;
	    } else {
		break;
	    }
	}
	
	x = hint+1;
	while (x <= A[i]) {
	    LL tmp = x * (A[i] - x * x);
	    if (best < tmp) {
		X[i] = x;
		best = tmp;
		x++;
	    } else {
		break;
	    }
	}
    }

    LL sum = 0;
    REP (i, N) sum += X[i];

    if (sum == K) {
	rprintf("%lld", X, X+N);
    } else if (sum < K) {
	LL cnt = 0;
	auto ok = [&](LL MID) {
	    cnt = 0;
	    REP (i, N) {
		LL lo = X[i], hi = A[i]+1;
		while (hi - lo > 1) {
		    LL c = (lo + hi) / 2;
		    LL diff = A[i] - 3*c*c + 3*c - 1;
		    assert(diff <= 0);
		    if (MID <= diff) {
			lo = c;
		    } else {
			hi = c;
		    }
		}

		B[i] = lo;
		cnt += lo;
	    }

	    return K <= cnt;
	};

	LL lo = -1, hi = 1;
	while (!ok(lo)) {
	    hi = lo;
	    lo += lo;
	}
	while (hi - lo > 1) {
	    LL mid = (lo + hi) / 2;
	    (ok(mid)? lo: hi) = mid;
	}

	ok(lo);
	REP (i, N) if (cnt > K) {
	    LL c = B[i];
	    LL diff = A[i] - 3*c*c + 3*c - 1;
	    if (diff == lo) {
		B[i]--;
		cnt--;
	    }
	}
	rprintf("%lld", B, B+N);
    } else {
	LL cnt = 0;
	auto ok = [&](LL MID) {
	    cnt = 0;
	    REP (i, N) {
		LL lo = -1, hi = X[i];
		while (hi - lo > 1) {
		    LL c = (lo + hi) / 2;
		    LL diff = A[i] - 3*c*c - 3*c - 1;
		    assert(diff >= 0);
		    if (diff <= MID) {
			hi = c;
		    } else {
			lo = c;
		    }
		}

		B[i] = hi;
		cnt += hi;
	    }

	    return K >= cnt;
	};

	LL lo = -1, hi = 1;
	while (!ok(hi)) {
	    lo = hi;
	    hi += hi;
	}
	while (hi - lo > 1) {
	    LL mid = (lo + hi) / 2;
	    (ok(mid)? hi: lo) = mid;
	}

	ok(hi);
	REP (i, N) if (cnt < K) {
	    LL c = B[i];
	    LL diff = A[i] - 3*c*c - 3*c - 1;
	    if (diff == lo) {
		B[i]++;
		cnt++;
	    }
	}
	rprintf("%lld", B, B+N);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}