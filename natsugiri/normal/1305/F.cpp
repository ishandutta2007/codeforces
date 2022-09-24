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

const int MAX = 1000011;
int min_factor[MAX];
vector<int>prime;
void make_prime() {
    assert("Call once" && prime.empty());
    for (int i=2; i<MAX; i+=2) min_factor[i] = 2;
    for (int i=3; i*i<MAX; i++) {
	if (min_factor[i] == 0) {
	    min_factor[i] = i;
	    for (int j=i*i; j<=MAX; j+=i)
		if (min_factor[j] == 0) min_factor[j] = i;
	}
    }
    for (int i=2; i<MAX; i++) {
	if (min_factor[i] == 0) min_factor[i] = i;
	if (min_factor[i] == i) prime.push_back(i);
    }
}

vector<pair<LL, int> > prime_factor(LL n) {
    assert(n <= (LL)MAX * MAX);
    vector<pair<LL, int> > ret;
    REP (i, prime.size()) {
	if (n < MAX) break;
	if (n < (LL)prime[i] * prime[i]) break;
	int cnt = 0;
	while (n % prime[i] == 0) {
	    n /= prime[i];
	    cnt++;
	}
	if (cnt) ret.emplace_back(prime[i], cnt);
    }
    if (MAX <= n) {
	ret.emplace_back(n, 1);
    } else {
	while (1 < n) {
	    int p = min_factor[n], cnt = 0;
	    while (n % p == 0) { n /= p, cnt++; }
	    ret.emplace_back(p, cnt);
	}
    }
    return ret;
}

int N;
LL A[200011];
LL ans;

int cnt;
LL naive(LL t) {
    cnt++;
    LL ret = 0;
    REP (i, N) {
	if (A[i] <= t) {
	    ret += t - A[i];
	} else {
	    LL m = A[i] % t;
	    if (m) ret += min(m, t-m);
	}
	if (ret >= ans) break;
    }
    return ret;
}

const int LIMIT = 200;

void go(LL a) {
    auto f = prime_factor(a);
    EACH (e, f) if (e->first >= prime[LIMIT]) {
	amin(ans, naive(e->first));
    }
}

void MAIN() {
    make_prime();

    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);
#ifdef MYTEST
    N = 200000;
    REP (i, N) A[i] = engine() % 1000000000000LL;
#endif

    sort(A, A+N);

    ans = N;
    REP (i, LIMIT) {
	amin(ans, naive(prime[i]));
    }

    REP (t, 100) {
	int x = engine() % N;
	go(A[x]);
    }
    REP (t, 100) {
	int x = engine() % N;
	go(A[x]+1);
    }

    if (A[0] > 10) {
	REP (t, 100) {
	    int x = engine() % N;
	    go(A[x]-1);
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