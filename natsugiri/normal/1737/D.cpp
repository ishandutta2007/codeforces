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
int M;
int U[250011];
int V[250011];
int W[250011];
int D[511][511];

int S[511];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d%d%d", U+i, V+i, W+i), U[i]--, V[i]--;

    REP (i, N) memset(D[i], 0x3f, sizeof (int) * N);
    REP (i, M) {
	int u = U[i];
	int v = V[i];
	D[u][v] = 1;
	D[v][u] = 1;
    }
    REP (i, N) D[i][i] = 0;
    REP (k, N) REP (i, N) REP (j, N) amin(D[i][j], D[i][k] + D[k][j]);

    REP (i, N) {
	int s = 0;
	REP (j, N) {
	    if (D[0][j] + D[N-1][j] + D[i][j] < D[0][s] + D[N-1][s] + D[i][s]) {
		s = j;
	    }
	}
	S[i] = s;
    }
    // rprintf("%d", S, S+N);

    LL ans = 1LL<<60;
    REP (i, M) {
	int u = U[i];
	int v = V[i];
	LL w = W[i];

	REP (t, 2) {
	    amin(ans, w * (D[0][u] + 1 + D[N-1][v]));

	    int s = S[u];
	    amin(ans, w * (D[0][s] + D[s][u] + 2 + D[N-1][s]));

	    swap(u, v);
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}