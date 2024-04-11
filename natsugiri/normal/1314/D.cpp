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

#include<random>
#include<chrono>
#include<memory>

uint64_t murmurhash3mixer(uint64_t x) {
    x ^= (x >> 33);
    x *= 0xff51afd7ed558ccdULL;
    x ^= (x >> 33);
    x *= 0xc4ceb9fe1a85ec53ULL;
    x ^= (x >> 33);
    return x;
}

seed_seq seq{
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
	(uint64_t) __builtin_ia32_rdtsc(),
	(uint64_t) (uintptr_t) make_unique<char>().get(),
	murmurhash3mixer(random_device()()),
};

mt19937_64 engine(seq);

int N, K;
int A[81][81];
int D[11][81];

LL b0, b1;
inline bool B(int i) {
    if (i < 64) return b0>>i&1;
    i -= 64;
    return b1>>i&1;
}

int MASK;
int solve() {
    memset(D, 0x3f, sizeof D);
    D[0][0] = 0;
    int t = 0;
    while (t < K) {
	REP (i, N) if (B(i)) {
	    REP (j, N) if (!B(j)) {
		amin(D[t+1][j], D[t][i] + A[i][j]);
	    }
	}
	t++;
	REP (i, N) if (!B(i)) {
	    REP (j, N) if (B(j)) {
		amin(D[t+1][j], D[t][i] + A[i][j]);
	    }
	}
	t++;
    }

    return D[K][0];
}


void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) REP (j, N) scanf("%d", A[i]+j);

#ifdef MYTEST
    N = 80;
    K = 10;
    REP (i, N) REP (j, N) {
	A[i][j] = 1e8;
	//A[i][j] = engine() % (100000001);
    }
    REP (i, N) A[i][i] = 0;
    REP (i, 10) A[i][(i+1)%10] = 1;
#endif

    int ans = 1<<30;
    REP (t, 15000) {
	b0 = engine() | 1;
	b1 = engine();
	amin(ans, solve());
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}