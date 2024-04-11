#include<unordered_map>
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

const char * NO = "NO";
const char * YES = "YES";

const int MAXN = 300111;

int N, M;
int A[MAXN], B[MAXN];
VI G[MAXN];
VI H[MAXN];
VI G2[MAXN];
int deg[MAXN];

bool use[MAXN];

unordered_map<int, int> Emap[MAXN];

int X[MAXN];
int XX[MAXN];

int get_edge(int v, int w) {
    auto it = Emap[v].find(w);
    if (it == Emap[v].end()) return -1;
    else return it->second;
}

inline int to(int v, int x) {
    return A[x] ^ B[x] ^ v;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	scanf("%d%d", A+i, B+i);
	A[i]--, B[i]--;
	deg[A[i]]++;
	deg[B[i]]++;
    }

    REP (i, N) G[i].reserve(deg[i]);
    REP (i, M) {
	G[A[i]].push_back(i);
	G[B[i]].push_back(i);
	Emap[A[i]].emplace(B[i], i);
	Emap[B[i]].emplace(A[i], i);
    }


    int cnt = -1;
    VI C, E;
    REP (i, M) if (!use[i]) {

	if (H[A[i]].size() >= 2u || H[B[i]].size() >= 2u) {
	    puts(NO);
	    return;
	}

	int s = (deg[A[i]] < deg[B[i]] ? A[i] : B[i]);
	C.resize(2);
	C[0] = A[i]; C[1] = B[i];

	cnt++;
	use[i] = true;
	H[A[i]].push_back(cnt);
	H[B[i]].push_back(cnt);
	use[i] = true;

	EACH (e, G[s]) {
	    E.resize(0);

	    bool all = true;
	    int v = to(s, *e);

	    EACH (f, C) {
		int z = get_edge(v, *f);
		if (z == -1) {
		    all = false;
		    break;
		} else {
		    E.push_back(z);
		}
	    }

	    if (all) {
		if (H[v].size() >= 2u) {
		    puts(NO);
		    return;
		}

		C.push_back(v);
		H[v].push_back(cnt);

		EACH (g, E) {
		    use[*g] = true;
		}
	    }
	}
    }


    memset(deg, 0, sizeof deg);
    cnt++;
    UnionFind U(cnt);

    REP (i, N) {
	if (H[i].size() == 2u) {
	    // C id-s;
	    int a = H[i][0], b = H[i][1];
	    bool has = false;
	    EACH (e, G2[a]) if (*e == b) has = true;
	    if (has) continue;

	    if (deg[a] <= 1 && deg[b] <= 1 && !U.same(a, b)) {
		G2[a].push_back(b);
		G2[b].push_back(a);
		U.link(a, b);
	    } else {
		puts(NO);
		return;
	    }
	}
    }

    if (U.count() != 1) {
	puts(NO);
	return;
    }

    int last = -1;
    REP (s, cnt) if (G2[s].size() == 1u) {
	int cur = s, par = s;

	int val = 1;
	while (1) {
	    XX[cur] = val++;

	    int nxt = -1;
	    EACH (e, G2[cur]) {
		if (*e != par) {
		    nxt = *e;
		    break;
		}
	    }

	    if (nxt == -1) {
		break;
	    } else {
		par = cur;
		cur = nxt;
	    }
	}

	last = cur;
	break;
    }

    if (last == -1) {
	REP (v, N) X[v] = 1;
    } else {
	REP (v, N) {
	    if (H[v].size() == 2u) {
		X[v] = max(XX[H[v][0]], XX[H[v][1]]);
	    } else if (H[v][0] == last) {
		X[v] = XX[H[v][0]] + 1;
	    } else {
		X[v] = XX[H[v][0]];
	    }
	}
    }
//    rprintf("%d", XX, XX + cnt);

    memset(deg, 0, sizeof deg);
    REP (v, N) {
	deg[X[v]]++;
    }
    REP (v, N) {
	int t[3] = {};
	EACH (e, G[v]) {
	    int w = to(v, *e);
	    if (X[w] == X[v] - 1) {
		t[0]++;
	    } else if (X[w] == X[v]) {
		t[1]++;
	    } else if (X[w] == X[v] + 1) {
		t[2]++;
	    } else {
		puts(NO);
		return;
	    }
	}

	if (deg[X[v]-1] != t[0] ||
		deg[X[v]] != t[1] + 1 ||
		deg[X[v]+1] != t[2]) {
	    puts(NO);
	    return;
	}
    }

    puts(YES);
    rprintf("%d", X, X + N);

 //   REP (i, N) {
 //       printf("%d : ", i);
 //       rprintf("%d", H[i].begin(), H[i].end());
 //   }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}