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

const int MAX_V = 100111;
const int LOG_V = 18;
int N, Q;
VI G[MAX_V];
VI ord;
int depth[MAX_V];
int parent[LOG_V][MAX_V];

void build_lca(/* VI G[], int N, */ const int root=0) {
    depth[root] = 0;
    parent[0][root] = root;
    ord.reserve(N);
    ord.push_back(root);
    REP (i_, N) {
	int v = ord[i_];
	EACH (e, G[v]) if (*e != parent[0][v]) {
	    ord.push_back(*e);
	    depth[*e] = depth[v] + 1;
	    parent[0][*e] = v;
	    // G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end()); // remove parent edge
	}
    }
    REP (t, LOG_V-1) REP (v, N) parent[t+1][v] = parent[t][parent[t][v]];
}

int lca(int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    REP (t, LOG_V) if ((depth[x] - depth[y]) & (1 << t)) x = parent[t][x];
    if (x == y) return x;
    for (int t=LOG_V; t--;) {
	if (parent[t][x] != parent[t][y]) {
	    x = parent[t][x];
	    y = parent[t][y];
	}
    }
    return parent[0][x];
}

int distance(int x, int y, int z=-1) { // number of edges
    if (z == -1) z = lca(x, y);
    return depth[x] + depth[y] - 2 * depth[z];
}

int kth_vertex(int x, int y, int k, int z=-1) { // return { x, ?, ?, ..., y}[k];
    if (z == -1) z = lca(x, y);
    if (depth[x] - depth[z] < k) {
	k = depth[x] + depth[y] - 2 * depth[z] - k;
	swap(x, y);
    }
    REP (t, LOG_V) if (k & (1 << t)) x = parent[t][x];
    return x;
}


int prefix(int f, int s, int t) {
    int zs = lca(f, s);
    int zt = lca(f, t);
    int d = min(distance(f, s, zs), distance(f, t, zt));

    int lo = 0, hi = d+1;
    while (hi - lo > 1) {
	int mid = (lo + hi) / 2;
	if (kth_vertex(f, s, mid, zs) == kth_vertex(f, t, mid, zt)) {
	    lo = mid;
	} else {
	    hi = mid;
	}
    }
    return hi;
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N-1) {
	int x;
	scanf("%d", &x);
	G[x-1].push_back(i+1);
    }

    build_lca();

    REP ($, Q) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	a--; b--; c--;

	int ans = 0;
	amax(ans, prefix(a, b, c));
	amax(ans, prefix(b, c, a));
	amax(ans, prefix(c, a, b));
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}