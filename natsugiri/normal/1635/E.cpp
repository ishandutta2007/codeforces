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
struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int count_node(int x) { return -u[root(x)]; }
    int count_tree() { return cc; }
};

int N;
int M;

vector<pair<int, int> > G[200011];
vector<pair<int, int> > tree[200011];
int par[200011];
char D[200011];
int X[200011];
int deg[200011];
VI H[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    UnionFind U(N);

    REP (i, M) {
	int t, x, y;
	scanf("%d%d%d", &t, &x, &y);
	x--; y--;

	if (!U.same(x, y)) {
	    tree[x].emplace_back(y, t);
	    tree[y].emplace_back(x, t);
	    U.link(x, y);
	}
	G[x].emplace_back(y, t);
	G[y].emplace_back(x, t);
    }

    bool yes = true;
    VI que;
    REP (i, N) if (U.root(i) == i) {
	par[i] = i;
	que.clear();
	que.push_back(i);

	D[i] = 'L';

	for (int j=0; j<(int)que.size(); j++) {
	    int v = que[j];
	    EACH (e, tree[v]) {
		int w = e->first;
		if (w == par[v]) continue;
		par[w] = v;
		que.push_back(w);
		D[w] = D[v] ^ 'L' ^ 'R';
	    }
	}


	REP (j, que.size()) {
	    int v = que[j];
	    EACH (e, G[v]) {
		int w = e->first;
		if (D[v] == D[w]) {
		    yes = false;
		    goto OUT;
		}

		if ((D[v] == 'L' && e->second == 1) || (D[v] == 'R' && e->second == 2)) {
		    H[v].push_back(w);
		    deg[w]++;
		}
	    }
	}
    }

    que.clear();
    REP (i, N) if (deg[i] == 0) {
	X[i] = que.size();
	que.push_back(i);
    }
    REP (i, N) {
	int v = que[i];
	EACH (e, H[v]) {
	    deg[*e]--;
	    if (deg[*e] == 0) {
		X[*e] = que.size();
		que.push_back(*e);
	    }
	}
    }
OUT:

    if (yes) {
	REP (v, N) EACH (e, G[v]) if (X[v] < X[e->first]) {
	    if (D[v] == 'R' && D[e->first] == 'L' && e->second == 2) {
	    } else if (D[v] == 'L' && D[e->first] == 'R' && e->second == 1) {
	    } else {
		yes = false;
	    }
	}
    }

    if (yes) {
	puts("YES");
	REP (i, N) printf("%c %d\n", D[i], X[i]);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}