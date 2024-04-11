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
int R[32];
int D[32];
int Rs[32];
int Ds[32];

void MAIN() {
    scanf("%d%d", &N, &K);

    REP (i, N-1) {
	int pc = __builtin_ctz(i+1);
	R[i] = 1<<(pc*2);
	D[i] = 1<<(pc*2+1);
    }
    REP (i, N) {
	rprintf("%d", R, R+N-1);
    }
    REP (i, N-1) {
	REP (j, N) printf("%d%c", D[i], " \n"[j==N-1]);
    }
    fflush(stdout);

    REP (i, 31) {
	Rs[i+1] = Rs[i] ^ R[i];
	Ds[i+1] = Ds[i] ^ D[i];
    }

    const int FIVE = 0x55555555;
    const int AS = 0xAAAAAAAA;

    int row = 0, col = 0;

    REP ($, K) {
	int X;
	scanf("%d", &X);

	int nrow = -1, ncol = -1;
	REP (i, N) {
	    if ((Rs[col] ^ Rs[i]) == (X & FIVE)) {
		assert(ncol == -1);
		ncol = i;
	    }
	    if ((Ds[row] ^ Ds[i]) == (X & AS)) {
		assert(nrow == -1);
		nrow = i;
	    }
	}

	row = nrow;
	col = ncol;
	printf("%d %d\n", row + 1, col + 1);
	fflush(stdout);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}