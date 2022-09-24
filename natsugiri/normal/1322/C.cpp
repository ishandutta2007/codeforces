#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
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

using ULL = unsigned long long;

ULL gcd(ULL x, ULL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N, M;
ULL C[500011];
int U[500011], V[500011];
int idx[500011];
int deg[500011];

ULL H[500011], Z[500011];

ULL solve() {
    REP (i, N) Z[i] = engine();
    memset(H, 0, sizeof (H[0]) * N);
    REP (i, M) H[V[i]] += Z[U[i]];

    REP (i, N) idx[i] = i;
    sort(idx, idx+N, [&](int i, int j) {
	    return H[i] < H[j];
	    });
    ULL ret = 0;
    for (int i=0; i<N; ) {
	int j = i;
	ULL s = 0;
	while (j < N && H[idx[i]] == H[idx[j]]) {
	    s += C[idx[j]];
	    j++;
	}
	if (deg[idx[i]]) {
	    ret = gcd(ret, s);
	}
	i = j;
    }
    return ret;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%llu", C+i);
    REP (i, M) scanf("%d%d", U+i, V+i), U[i]--, V[i]--;

    memset(deg, 0, sizeof (deg[0]) * N);
    REP (i, M) deg[V[i]]++;

    ULL ret = 0;
    REP (t, 8) ret = gcd(ret, solve());

    printf("%lld\n", ret);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}