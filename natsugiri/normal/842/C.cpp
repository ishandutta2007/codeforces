#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

const int SIZE = 4011;
unsigned tbl[SIZE][SIZE];

unsigned gcd(unsigned x, unsigned y) {
    while ((unsigned)SIZE <= x || (unsigned)SIZE <= y) {
	if (x) y %= x;
	else return y;
	if (y) x %= y;
	else return x;
    }
    return tbl[x][y];
}

const int MAXN = 200111;
int N;
VI G[MAXN];
int A[MAXN];
int ans[MAXN];

void dfs2(int v, int p, int g) {
    int z = (g==1? 1: gcd(A[v], g));
    amax(ans[v], z);
    EACH (e, G[v]) if (*e != p) {
	dfs2(*e, v, z);
    }
}

void dfs(int v, int p, int g) {
    amax(ans[v], g);
    int z = (g==1? 1: gcd(A[v], g));
    if (z != g) {
	EACH (e, G[v]) if (*e != p) {
	    dfs2(*e, v, g);
	}
    }

    EACH (e, G[v]) if (*e != p) {
	dfs(*e, v, z);
    }
}

void MAIN() {
    REP (i, SIZE) REP (j, SIZE) tbl[i][j] = 1;
    for (int g=2; g<SIZE; g++) {
	for (int i=0; i<SIZE; i+=g) for (int j=0; j<SIZE; j+=g) {
	    tbl[i][j] = g;
	}
    }
    tbl[0][0] = 0;

    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--;y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    dfs(0, 0, 0);

    ans[0] = A[0];
    rprintf("%d", ans, ans + N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}