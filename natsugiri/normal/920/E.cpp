#include<map>
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
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};

const int MAXN = 200111;
int N, M;
VI Z[MAXN];
int parent[MAXN];
int sz[MAXN];
VI A, B;
VI root;

void MAIN() {
    scanf("%d%d", &N, &M);
    A.resize(M);
    B.resize(M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	Z[x].push_back(y);
	Z[y].push_back(x);
	A[i] = x;
	B[i] = y;
    }

    UnionFind U(N);

    VI rem(N), nxt;
    REP (i, N) rem[i] = i;
    nxt.reserve(N);
    while (rem.size()) {
	int v = rem.back();
	rem.pop_back();

	root.push_back(v);
	parent[v] = v;
	sz[v] = 1;
	nxt.clear();

	sort(Z[v].begin(), Z[v].end());

	EACH (e, rem) {
	    int k = lower_bound(Z[v].begin(), Z[v].end(), *e) - Z[v].begin();
	    if (k < (int)Z[v].size() && Z[v][k] == *e) {
		nxt.push_back(*e);
	    } else {
		U.link(v, *e);
		parent[*e] = v;
		sz[v]++;
	    }
	}

	swap(nxt, rem);
    }

    map<pair<int, int>, int> mp;
    REP (i, M) {
	int px = parent[A[i]], py = parent[B[i]];
	if (px != py) {
	    if (px > py) swap(px, py);
	    mp[make_pair(px, py)]++;
	}
    }

    REP (i, root.size()) for (int j=i+1; j<(int)root.size(); j++) {
	int x = root[i];
	int y = root[j];
	if (x > y) swap(x, y);
	pair<int, int> key(x, y);
	auto it = mp.find(key);
	if (it != mp.end() && it->first == key && it->second == (LL)sz[x] * sz[y]) {
	    // no edge
	} else {
	    U.link(x, y);
	}
    }

    VI ans;
    REP (i, N) if (U.root(i) == i) ans.push_back(U.size(i));
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}