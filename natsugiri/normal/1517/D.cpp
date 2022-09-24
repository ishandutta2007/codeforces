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

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};


int N, M, K;
int H[511][511];
int V[511][511];

bool in(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

int cost(int i, int j, int ii, int jj) {
    assert(abs(i-ii) + abs(j-jj) == 1);
    if (i != ii) return V[min(i, ii)][j];
    if (j != jj) return H[i][min(j, jj)];

    assert(false);
    return 0;
}

LL D[11][511][511];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) REP (j, M-1) scanf("%d", &H[i][j]);
    REP (i, N-1) REP (j, M) scanf("%d", &V[i][j]);

    if (K % 2 == 0) {
	memset(D, 0x3f, sizeof D);

	REP (i, N) REP (j, M) {
	    REP (d, 4) {
		int ii = i + dy[d];
		int jj = j + dx[d];
		if (in(ii, jj)) amin(D[1][i][j], (LL)cost(i, j, ii, jj));
	    }
	}
	for (int k=1; k<K/2; k++) {
	    REP (i, N) REP (j, M) {
		REP (d, 4) {
		    int ii = i + dy[d];
		    int jj = j + dx[d];
		    if (in(ii, jj)) amin(D[k+1][i][j], D[k][ii][jj] + cost(i, j, ii, jj));
		}
	    }
	}

	REP (i, N) {
	    REP (j, M) {
		LL ans = D[K/2][i][j] * 2;
		printf("%lld%c", ans, " \n"[j==M-1]);
	    }
	}
    } else {
	REP (i, N) {
	    REP (j, M) {
		printf("-1%c", " \n"[j==M-1]);
	    }
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}