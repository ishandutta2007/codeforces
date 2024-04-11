#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

uint64_t Z[511];
uint64_t H[511];

int N;
int A[511][511];
int salary[2011];
vector<pair<int, int> > E;
int cnt;

vector<VI> stk;

int solve(VI se) {
    if (se.size() == 1u) {
	salary[se[0]] = A[se[0]][se[0]];
	return se[0];
    }

    int ma = -1;
    EACH (e, se) amax(ma, A[se[0]][*e]);

    EACH (e, se) {
	H[*e] = 0;
	EACH (f, se) if (A[*e][*f] == ma) {
	    H[*e] ^= Z[*f];
	}
    }

    sort(se.begin(), se.end(), [&](int x, int y) {
	    return H[x] < H[y];
	    });

    int root = cnt++;
    salary[root] = ma;

    int t = 0;
    for (int i=0; i<(int)se.size(); ) {
	int j = i+1;
	while (j < (int)se.size() && H[se[i]] == H[se[j]]) j++;
	stk.emplace_back(se.begin()+i, se.begin()+j);
	t++;
	i = j;
    }

    REP (i, t) {
	int x = solve(stk.back());
	stk.pop_back();
	E.emplace_back(x, root);
    }

    return root;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) REP (j, N) scanf("%d", A[i]+j);

    REP (i, 511) engine();
    REP (i, N) Z[i] = engine();

    VI idx(N);
    REP (i, N) idx[i] = i;
    cnt = N;
    int root = solve(idx);

    printf("%d\n", cnt);
    rprintf("%d", salary, salary + cnt);
    printf("%d\n", root+1);
    EACH (e, E) {
	printf("%d %d\n", e->first+1, e->second+1);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}