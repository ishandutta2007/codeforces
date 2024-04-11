#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
VI R[500011][2];
int D[500011][2];
VI B[500011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y, t;
	scanf("%d%d%d", &x, &y, &t);
	x--; y--;
	R[y][t].push_back(x);
    }

    memset(D, 0x3f, sizeof D);
    const int INF = D[0][0];
    D[N-1][0] = D[N-1][1] = 0;

    B[0].push_back(N-1);

    REP (cst, N+1) EACH (it, B[cst]) {
	int v = *it;

	if (max(D[v][0], D[v][1]) != cst) continue;

	REP (k, 2) EACH (e, R[v][k]) {
	    if (D[*e][k] > cst + 1) {
		int cur_cst = max(D[*e][0], D[*e][1]);
		D[*e][k] = cst + 1;
		int nxt_cst = max(D[*e][0], D[*e][1]);
		if (nxt_cst < cur_cst) {
		    B[nxt_cst].push_back(*e);
		}
	    }
	}
    }

    int ans = max(D[0][0], D[0][1]);
    if (ans == INF) {
	puts("-1");
    } else {
	printf("%d\n", ans);
    }

    REP (i, N) {
	if (D[i][0] > D[i][1]) putchar('0');
	else putchar('1');
    }
    puts("");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}