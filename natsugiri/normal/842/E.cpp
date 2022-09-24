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

const int MAXN = 300111; // TODO
const int LOGN = 2 < __lg(MAXN) ? __lg(MAXN)+1 : 3; // (1<<LOG) > MAXN;
int pos[MAXN];
int par[MAXN];
int tbl[LOGN+1][MAXN * 2];
int depth[MAXN];

void build(const VI * const G, int N, const int root) {
    int ord_i = 0, *ord = tbl[0], stk_i = 0, *stk = tbl[1], *iter = tbl[2];
    memset(iter, 0, sizeof (int) * N);
    stk[stk_i++] = root;
    par[root] = root;
    depth[root] = 0;
    while (stk_i) {
	int v = stk[stk_i-1];
	if (iter[v] == 0) {
	    pos[v] = ord_i;
	}
	if (iter[v] < (int)G[v].size()) {
	    int w = G[v][iter[v]++];
	    if (w != par[v]) {
		ord[ord_i++] = v;
		stk[stk_i++] = w;
		par[w] = v;
		depth[w] = depth[v] + 1;
	    }
	} else {
	    ord[ord_i++] = v;
	    stk_i--;
	}
    }

    REP (t, __lg(ord_i)) for (int i=0, s=1<<t; i<=ord_i-s; i++) {
	int x = tbl[t][i], y = tbl[t][i+s];
	tbl[t+1][i] = depth[y] < depth[x] ? y : x;
    }
}

int lca(int x, int y) {
    int a = pos[x], b = pos[y];
    if (b < a) { swap(a, b); }
    int t = __lg(b - a + 1);
    x = tbl[t][a]; y = tbl[t][b-(1<<t)+1];
    return depth[y] < depth[x] ? y : x;
}

int dist(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int N, M;
VI G[MAXN];
int A[MAXN];

void MAIN() {
    scanf("%d", &M);
    N = M+1;
    REP (i, M) {
	scanf("%d", A+i);
	A[i]--;
	G[A[i]].push_back(i+1);
    }

    build(G, N, 0);

    VI B; B.push_back(0);
    int D = 0;

    REP (i, M) {
	int v = i+1;

	if (dist(B[0], v) > D || dist(B.back(), v) > D) {
	    VI nxt;
	    int w = (dist(B[0], v) > D ? B[0] : B.back());
	    nxt.push_back(w);
	    EACH (e, B) {
		if (*e == w) continue;
		if (dist(*e, w) > D || dist(*e, v) > D) nxt.push_back(*e);
	    }
	    nxt.push_back(v);
	    swap(B, nxt);
	    D++;
	} else if (dist(B[0], v) == D) {
	    B.push_back(v);
	} else if (dist(B.back(), v) == D) {
	    swap(B[0], B.back());
	    B.push_back(v);
	} else {
	}

	printf("%d\n", (int)B.size());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}