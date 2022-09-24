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

int N, M;
char F[1011][1011];
int PP[1011][1011];
int PN[1011][1011];
int NP[1011][1011];
int NN[1011][1011];
bool in(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

void go(int a[1011][1011], int si, int sj, int di, int dj) {
    for (int i=si; 0<=i && i<N; i+=di) {
	for (int j=sj; 0<=j && j<M; j+=dj) {
	    int ii = i+di;
	    int jj = j+dj;
	    if (in(ii, j)) amax(a[ii][j], a[i][j] + 1);
	    if (in(i, jj)) amax(a[i][jj], a[i][j] + 1);
	}
    }
}

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, N) scanf("%s", F[i]);

    REP (i, N) {
	memset(PP[i], 0xc0, sizeof (int) * M);
	memset(PN[i], 0xc0, sizeof (int) * M);
	memset(NP[i], 0xc0, sizeof (int) * M);
	memset(NN[i], 0xc0, sizeof (int) * M);
    }
    REP (i, N) REP (j, M) if (F[i][j] == 'B') {
	PP[i][j] = PN[i][j] = NP[i][j] = NN[i][j] = 0;
    }

    go(PP, 0, 0, 1, 1);
    go(PN, 0, M-1, 1, -1);
    go(NP, N-1, 0, -1, 1);
    go(NN, N-1, M-1, -1, -1);

    int ans = 1<<29;
    int ansi = 0;
    int ansj = 0;
    REP (i, N) REP (j, M) {
	int tmp = max({PP[i][j], PN[i][j], NP[i][j], NN[i][j]});
	if (ans > tmp) {
	    ans = tmp;
	    ansi = i;
	    ansj = j;
	}
    }
    printf("%d %d\n", ansi+1, ansj+1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}