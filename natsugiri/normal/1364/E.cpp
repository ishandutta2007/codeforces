#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<random>
#include<map>

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

mt19937 engine(seq);

int N;
int ans[2048];


int P[2048];
void init() {
#ifdef MYTEST
    N = 2048;
    REP (i, N) P[i] = i;
    shuffle(P, P+N, engine);
#endif
}

int cnt;
map<pair<int, int>, int> mp;
int query(int i, int j) {
    if (i > j) swap(i, j);
    pair<int, int> key(i, j);
    if (mp.count(key)) return mp[key];

    cnt++;
    printf("? %d %d\n", i+1, j+1);
    fflush(stdout);
#ifdef MYTEST
    return mp[key] = P[i] | P[j];
#endif
    int a;
    scanf("%d", &a);
    return mp[key] = a;
}

void answer() {
    printf("! ");
    rprintf("%d", ans, ans+N);
    fflush(stdout);

#ifdef MYTEST
    printf("> ");
    rprintf("%d", P, P+N);

    REP (i, N) assert(ans[i] == P[i]);
    printf("query %d\n", cnt);
#endif
}

VI three(int x, int y, int z) {
    int a = query(x, y);
    int b = query(y, z);
    int c = query(z, x);
    VI ret;
    if (a <= c && b <= c && (a|b) == c) {
	ret.push_back(y);
    }
    if (b <= a && c <= a && (b|c) == a) {
	ret.push_back(z);
    }
    if (a <= b && c <= b && (a|c) == b) {
	ret.push_back(x);
    }

    if (ret.size() == 3u) ret.clear();
#ifdef MYTEST
    eprintf("three %d %d %d -> ", P[x], P[y], P[z]);
    EACH (e, ret) eprintf(" %d", P[*e]);
    eprintf("\n");
#endif
    return ret;
}

void MAIN() {
    scanf("%d", &N);
    init();

    VI cur;
    REP (i, N) cur.push_back(i);

    VI nxt;
    while (cur.size() >= 4u) {
	shuffle(cur.begin(), cur.end(), engine);
	VI qs;
	nxt.clear();
	int len = cur.size();
	REP (i, len) {
	    int q = query(cur[i], cur[(i+1)%len]);
	    qs.push_back(q);
	}
	REP (i, len) {
	    int a0 = qs[i];
	    int a1 = qs[(i+1)%len];
	    int b0 = qs[(i-1+len)%len];
	    int b1 = qs[(i-2+len)%len];
	    if (a0 != b0 && (a0 & a1) == a0 && ((b0 & b1) == b0)) {
		nxt.push_back(cur[i]);
	    }
	}

	swap(cur, nxt);
    }

    while (cur.size() != 1u) {
	if (cur.size() < 3u) {
	    int v = engine() % N;
	    auto it = find(cur.begin(), cur.end(), v);
	    if (it == cur.end()) {
		cur.push_back(v);
	    }
	}
	if (cur.size() == 3u) {
	    cur = three(cur[0], cur[1], cur[2]);
	    assert(cur.size());
	}
    }

    int zero = cur[0];

    REP (i, N) {
	if (i == zero) ans[i] = 0;
	else ans[i] = query(zero, i);
    }

    answer();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}