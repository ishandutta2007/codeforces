#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<random>

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

int _pc[1<<20];
void init() {
    REP (i, 1<<20) _pc[i] = _pc[i/2] + (i&1);
}

int N;
int M;
int P;
char buf[111];
int C[61];
LL A[200011];

int dpX[1<<15];
int dpY[1<<15];

LL ans;
int ans_pc;


void MAIN() {
    scanf("%d%d%d", &N, &M, &P);
    REP (i, N) {
	scanf("%s", buf);
	A[i] = 0;
	REP (j, M) {
	    if (buf[j] == '1') {
		A[i] |= 1LL<<j;
	    }
	}
    }

#ifdef LOCALx
    N = 200000;
    M = 60;
    P = 15;
    REP (i, N) A[i] = (1<<P)-1;
    REP (i, N/2) A[i] = ((1<<P)-1) << P;
#endif

    REP (i, N) REP (j, M) if (A[i]>>j&1) C[j]++;

    REP (r, 30) {
	LL mask = A[engine() % N];
	memset(dpX, 0, sizeof dpX);

	VI V;
	REP (j, M) if ((mask>>j&1) && C[j]*2 >= N) V.push_back(j);
	if ((int)V.size() <= ans_pc) continue;

	REP (i, N) {
	    LL x = 0;
	    REP (j, V.size()) if (A[i]>>V[j]&1) x |= 1LL<<j;
	    dpX[x]++;
	}

	REP (t, V.size()) REP (s, 1<<V.size()) if (~s>>t&1) {
	    dpX[s] += dpX[s|(1<<t)];
	}

	int tmp = 0;
	int tmp_pc = 0;
	REP (s, 1<<V.size()) if (dpX[s]*2 >= N) {
	    if (tmp_pc < _pc[s]) {
		tmp = s;
		tmp_pc = _pc[s];
	    }
	}
	if (ans_pc < tmp_pc) {
	    ans_pc = tmp_pc;
	    ans = 0;
	    REP (j, V.size()) if (tmp>>j&1) ans |= 1LL<<V[j];
	}
    }

    REP (j, M) printf("%d", (int)(ans>>j&1));
    putchar('\n');
    eprintf("pc %d\n", ans_pc);
}

int main() {
    init();
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}