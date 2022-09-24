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

int N, M;
int A[300011][8];

int B[300011];
int C[1<<8];

int ansi, ansj;

bool ok(int mid) {
    memset(C, -1, sizeof C);
    REP (i, N) {
	int mask = 0;
	REP (j, M) if (A[i][j] >= mid) mask |= 1<<j;
	B[i] = mask;
	if (C[mask] == -1) C[mask] = i;
    }
    REP (t, M) REP (s, 1<<M) if (s>>t&1 && C[s^(1<<t)] == -1 && C[s] != -1) C[s^(1<<t)] = C[s];
    REP (i, N) {
	int k = ((1<<M)-1) ^ B[i];
	if (C[k] != -1) {
	    ansi = i;
	    ansj = C[k];
	    return true;
	}
    }

    return false;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	REP (j, M) scanf("%d", A[i]+j);
    }

    LL lo = 0, hi = 1<<30;
    while (hi - lo > 1) {
	LL mid = (hi + lo) / 2;
	(ok(mid)? lo: hi) = mid;
    }

    ok(lo);
    printf("%d %d\n", ansi+1, ansj+1);
//    eprintf("%d\n", (int)lo);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}