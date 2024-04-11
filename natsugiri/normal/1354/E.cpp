#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
    int count_node(int x) { return -u[root(x)]; }
    int count_tree() { return cc; }
};

const int MAX_N = 5011, MAX_M = 100011;
int N, M, A[MAX_M], B[MAX_M];
int C[2*MAX_N], CC;

VI root;
vector<pair<int, int> > bipartite() {
    memset(C, 0, sizeof (char) * 2 * N);
    CC = 0;
    UnionFind U(2*N);
    REP (i, M) {
	U.link(A[i], B[i]+N);
	U.link(A[i]+N, B[i]);
    }
    vector<pair<int, int> > ret;
    REP (i, N) if (U.same(i, i+N)) return ret; // not bipartite
    vector<int> cnt(2*N, 0);
    REP (i, N) cnt[U.root(i)]++;
    REP (i, N) {
	int a = U.root(i), b = U.root(i+N);
	if ((a == i && a < b) || (b == i+N && b < a)) {
	    ret.push_back(make_pair(cnt[a], cnt[b]));
	    root.push_back(i);
	    CC++;
	    C[a] = -CC; C[b] = CC;
	}
    }
    REP (i, N) C[i] = C[U.root(i)];
    return ret;
}

int X[3];
int ans[5011];

bool dp[5011][5011];
char S[5011];
VI G[5011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, 3) scanf("%d", X+i);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	A[i] = x;
	B[i] = y;
    }

    bool yes = false;
    if (M == 0) {
	yes = true;
	REP (i, N) {
	    if (i < X[0]) ans[i] = 1;
	    else if (i < X[0] + X[1]) ans[i] = 2;
	    else ans[i] = 3;
	}
    } else {
	auto Y = bipartite();
	if (Y.empty()) {
	    yes = false;
	} else {
	    dp[0][0] = true;
	    REP (i, Y.size()) {
		REP (j, X[1]+1) if (dp[i][j]) {
		    dp[i+1][j+Y[i].first] = true;
		    dp[i+1][j+Y[i].second] = true;
		}
	    }

	    if (dp[Y.size()][X[1]]) {
		yes = true;
		int x = X[1];
		for (int i=Y.size(); i--;) {
		    if (x >= Y[i].first && dp[i][x - Y[i].first]) {
			S[i] = '2';
			x -= Y[i].first;
		    } else {
			assert(x >= Y[i].second);
			assert(dp[i][x - Y[i].second]);
			S[i] = '1';
			x -= Y[i].second;
		    }
		}
		assert(x == 0);

		REP (i, M) {
		    G[A[i]].push_back(B[i]);
		    G[B[i]].push_back(A[i]);
		}

		REP (i, Y.size()) {
		    VI stk;
		    stk.push_back(root[i]);
		    ans[root[i]] = S[i] - '0';
		    while (!stk.empty()) {
			int v = stk.back();
			stk.pop_back();
			EACH (e, G[v]) if (ans[*e] == 0) {
			    ans[*e] = 3 - ans[v];
			    stk.push_back(*e);
			}
		    }
		}

		int cnt = X[2];
		REP (i, N) if (cnt && ans[i] == 1) {
		    cnt--;
		    ans[i] = 3;
		}
	    } else {
		yes = false;
	    }
	}
    }

    if (yes) {
	puts("YES");
	REP (i, N) putchar('0' + ans[i]);
	puts("");
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