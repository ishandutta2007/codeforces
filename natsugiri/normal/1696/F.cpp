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
char buf[111];
char A[101][101][101];
bool fix[101];
int par[101];
int FW[101][101];

void MAIN() {
    scanf("%d", &N);
    memset(A, '.', sizeof A);

    REP (i, N-1) {
	REP (j, N-1-i) {
	    scanf("%s", buf);
	    REP (k, N) {
		A[k][i][i+j+1] = A[k][i+j+1][i] = buf[k];
	    }
	}
    }

//    REP (c, N) {
//	REP (i, N) {
//	    A[c][i][N] = 0;
//	    puts(A[c][i]);
//	}
//	puts("");
//    }
//    puts("");

    par[0] = -1;
    VI que;
    for (int h=1; h<N; h++) {
	memset(fix, 0, sizeof (fix[0]) * N);
	que.clear();
	par[h] = 0;
	que.push_back(h);
	fix[0] = true;
	fix[h] = true;
	REP (i, N) {
	    if (i != 0 && i != h && A[0][h][i] == '1') {
		par[i] = 0;
		que.push_back(i);
		fix[i] = true;
	    }
	}

	bool yes = true;

	for (int i=0; i<(int)que.size(); i++) {
	    int v = que[i];
	    REP (j, N) {
		if (j != v && j != par[v] && A[v][par[v]][j] == '1') {
		    if (fix[j]) {
			yes = false;
			goto OUT;
		    }
		    par[j] = v;
		    que.push_back(j);
		    fix[j] = true;
		}
	    }
	}

OUT:
	if (yes) {
	    if ((int)que.size() != N-1) yes = false;
	}

	if (yes) {
	    REP (i, N) memset(FW[i], 0x3f, sizeof (int) * N);
	    for (int i=1; i<N; i++) {
		amin(FW[i][par[i]], 1);
		amin(FW[par[i]][i], 1);
	    }
	    REP (i, N) FW[i][i] = 0;
	    REP (k, N) REP (i, N) REP (j, N) {
		amin(FW[i][j], FW[i][k] + FW[k][j]);
	    }
	    REP (k, N) {
		REP (i, N) REP (j, N) if (i != j) {
		    if ((FW[k][i] == FW[k][j]) != (A[k][i][j] == '1')) {
			yes = false;
			goto OUT2;
		    }
		}
	    }
	}

OUT2:
	if (yes) {
	    puts("Yes");
	    for (int i=1; i<N; i++) printf("%d %d\n", i+1, par[i]+1);
	    return;
	}
    }
    puts("No");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}