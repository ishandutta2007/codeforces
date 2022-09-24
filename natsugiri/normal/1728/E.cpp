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
// xs + yt = gcd(x, y), xu + yv = 0
// abs(s) < abs(y / gcd(x, y));
// abs(t) < abs(x / gcd(x, y));
LL u, v;
LL extgcd(LL x, LL y, LL&s, LL&t) {
    assert(x >= 0 && y >= 0);
    for (u=t=1, v=s=0; x; ) {
	LL q = y / x;
	swap(s -= q * u, u);
	swap(t -= q * v, v);
	swap(y -= q * x, x);
    }
    return y;
}

int N;
LL A[300011];
LL B[300011];
LL D[300011];
LL sums[300011];

int M;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", A+i, B+i);

    LL all_a = 0;
    REP (i, N) {
	all_a += A[i];
	D[i] = B[i] - A[i];
    }
    sort(D, D+N);
    reverse(D, D+N);
    REP (i, N) sums[i+1] = sums[i] + D[i];

    LL target = 0;
    REP (i, N+1) if (D[i] < 0) {
	target = i;
	break;
    }

    scanf("%d", &M);
    REP ($, M) {
	LL X, Y;
	scanf("%lld%lld", &X, &Y);
	LL s, t;

	// Xs + Yt = g;
	// Xs + Yt = N;
	// X(s+uk) + Y(t+vk) = N;

	LL g = extgcd(X, Y, s, t);
	if (v < 0) {
	    u = -u;
	    v = -v;
	}

	LL ans = -1;
	if (N % g != 0) {
	    ans = -1;
	} else {
	    LL rate = N / g;
	    s *= rate;
	    t *= rate;

	    auto eval = [&](LL k) -> LL {
		assert(X * (s + u * k) + Y * (t + v * k) == N);
		if (s + u * k < 0) return -1;
		if (t + v * k < 0) return -1;
		return all_a + sums[Y * (t + v * k)];
	    };

	    // X(s+uk) + Y(t+vk) = N;
	    // u < 0 < v;
	    LL lo = -t / v, hi = -s / u;
	    LL guess = (target - t * Y) / (v*Y);

	    for (int a=-1; a<=1; a++) {
		amax(ans, eval(lo + a));
		amax(ans, eval(hi + a));
		amax(ans, eval(guess + a));
	    }

	    // eprintf("%lld (%lld %lld %lld %lld)\n", X*u + Y*v, s, t, u, v);
	}
	printf("%lld\n", ans);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}