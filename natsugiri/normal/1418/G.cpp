#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<unordered_map>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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

int N;
int A[500011];

int LC[500011];
int RC[500011];

ULL Z[500011][3];

LL solve() {
    REP (i, N) {
	Z[i][0] = engine();
	Z[i][1] = engine();
	Z[i][2] = Z[i][0] ^ Z[i][1];
    }

    LL ans = 0;

    memset(RC, 0, sizeof (RC[0]) * N);
    memset(LC, 0, sizeof (LC[0]) * N);

    unordered_map<ULL, int> mp;
    int li = 0, ri = 0;
    ULL L = 0, R = 0;
    mp[0] = 1;

    while (ri < N) {
	int a = A[ri];
	ri++;
	R ^= Z[a][RC[a] % 3];
	RC[a]++;

	while (RC[a] - LC[a] > 3) {
	    assert(mp.find(L) != mp.end());
	    mp[L]--;

	    int b = A[li];
	    li++;
	    L ^= Z[b][LC[b] % 3];
	    LC[b]++;
	}

	auto it = mp.find(R);
	if (it != mp.end()) {
	    ans += it->second;
	    it->second++;
	} else {
	    mp[R]++;
	}

    }

    return ans;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;


    LL ans[3];
    REP (i, 3) ans[i] = solve();
    sort(ans, ans+3);
    printf("%lld\n", ans[1]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}