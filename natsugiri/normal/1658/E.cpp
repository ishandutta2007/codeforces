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

int N;
int K;
int A[2011][2011];


int Y[4000011];
int X[4000011];
char F[2011][2011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) REP (j, N) scanf("%d", &A[i][j]), A[i][j]--;

#ifdef LOCAL
    N = 9;
    K = 3;
    VI idx(N*N);
    REP (i, idx.size()) idx[i] = i;
    random_shuffle(idx.begin(), idx.end());
    REP (i, N) REP (j, N) {
	A[i][j] = idx[i*N+j];
    }
    REP (i, N) rprintf("%2d", A[i], A[i]+N);
#endif

    REP (i, N) REP (j, N) {
	int a = A[i][j];
	X[a] = j;
	Y[a] = i;
    }


    int y = Y[N*N-1];
    int x = X[N*N-1];
    int max_xpy = x + y + K;
    int min_xpy = x + y - K;
    int max_xmy = x - y + K;
    int min_xmy = x - y - K;

    F[y][x] = 'M';
    for (int cnt=N*N-2; cnt>=0; cnt--) {
	y = Y[cnt];
	x = X[cnt];
	if (min_xpy <= x + y && x + y <= max_xpy
		&& min_xmy <= x - y && x - y <= max_xmy) {
	    F[y][x] = 'M';
	    amin(max_xpy, x + y + K);
	    amax(min_xpy, x + y - K);
	    amin(max_xmy, x - y + K);
	    amax(min_xmy, x - y - K);
	} else {
	    F[y][x] = 'G';
	}
    }
    REP (i, N) puts(F[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}