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

// -4 2 3 3 -4;
int N;
LL K;
LL A[3011];

LL ans = -1;
void calc(int a, int b, LL diff) {
    // eprintf("%d %d %lld\n", a, b, diff);
    int cnt = 0;
    LL pos = 0, mi = 0, ma = 0;
    // K, diff, -K, K;
    REP (i, N) {
	if (A[i] == 0) {
	    if (cnt < a) pos += K;
	    else if (cnt == a) pos += diff;
	    else if (cnt < a + 1 + b) pos -= K;
	    else pos += K;
	    cnt++;
	} else {
	    pos += A[i];
	}

	amin(mi, pos);
	amax(ma, pos);
    }

    amax(ans, ma - mi + 1);
    assert(pos == 0);

    cnt = 0;
    pos = mi = ma = 0;
    // K, -K, diff, K;
    REP (i, N) {
	if (A[i] == 0) {
	    if (cnt < a) pos += K;
	    else if (cnt < a + b) pos -= K;
	    else if (cnt == a + b) pos += diff;
	    else pos += K;
	    cnt++;
	} else {
	    pos += A[i];
	}

	amin(mi, pos);
	amax(ma, pos);
    }
    amax(ans, ma - mi + 1);
    assert(pos == 0);
}



void MAIN() {
    scanf("%d%lld", &N, &K);
    REP (i, N) scanf("%lld", A+i);

    int zeros = count(A, A+N, 0LL);

    REP (t, 2) {
	LL sum = 0;
	REP (i, N) sum += A[i];

	if (sum == 0 && zeros == 0) calc(0, 0, 0);

	REP (a, zeros) {
	    int b = zeros - 1 - a;
	    LL diff = a * K + sum - b * K;

	    if (abs(diff) > K) continue;

	    REP (c, a+1) {
		calc(c, b, -diff);
	    }
	}

	REP (i, N) A[i] = -A[i];
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}