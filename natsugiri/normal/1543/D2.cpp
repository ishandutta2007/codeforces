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
int A[2];
int bits;
LL LIMIT;

int NEG(int x) {
    x = -x;
    int z = 0;
    int p = 1;
    REP (i, bits) {
	int c = x % K;
	x /= K;
	if (c) {
	    z += p * (K - c);
	}
	p *= K;
    }
    return z;
}
int ADD(int x, int y) {
    eprintf("%d %d\n", x, y);
    if (x < 0) x = NEG(x);
    if (y < 0) y = NEG(y);
    int z = 0;
    int p = 1;
    REP (i, bits) {
	int c = (x + y) % K;
	x /= K;
	y /= K;
	z += p * c;
	p *= K;
    }

    return z;
}

void MAIN() {
    scanf("%d%d", &N, &K);

    bits = 0;
    LIMIT = 1;
    while (LIMIT <= N) {
	LIMIT *= K;
	bits++;
    }

    A[0] = 0;
    A[1] = 1;
    REP (i, N) {
	// cur = a1 X + a0;
	
	int query = ADD(A[1] * i, A[0]);
	printf("%d\n", query);
	fflush(stdout);

	// cur + nxt == query;
	// a1 X + a0 + nxt == a1 i + a0 (mod K);
	// nxt == -a1 X + a1 i (mod K);
	A[0] = A[1] * i;
	A[1] = -A[1];

	int ret;
	scanf("%d", &ret);

	if (ret == 1) {
	    return;
	}
    }
    assert(false);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}