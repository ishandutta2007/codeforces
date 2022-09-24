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

namespace SCC {
const int MAXN = 500011; // TODO: check the maximum size;
typedef vector<VI> Adj;
const VI *g;
int n;
int scc[MAXN]; // scc[v] := v's index of shrinked graph; topological order;
int cnt; // size of shrinked graph;
int num[MAXN]; // num[v] := dfs position of v;
int low[MAXN];
int par[MAXN];
int iter[MAXN];
int st[MAXN], st_i;
int vis[MAXN], vis_i;
bool in_vis[MAXN];

int build(const VI *g_, int n_) { // HINT: Adj G(N); build(&G[0], N);
    g = g_;
    n = n_;
    memset(scc, -1, sizeof (int) * n);
    cnt = 0;
    memset(num, -1, sizeof (int) * n);
    memset(low, -1, sizeof (int) * n);
    memset(par, -1, sizeof (int) * n);
    memset(iter, 0, sizeof (int) * n);
    st_i = 0;
    vis_i = 0;
    memset(in_vis, 0, sizeof (bool) * n);

    int time = 0;

    REP (s, n) if (scc[s] == -1) {
	st[st_i++] = s;
	while (st_i) {
	    int v = st[st_i-1];
	    if (num[v] == -1) {
		low[v] = num[v] = time++;
		vis[vis_i++] = v; in_vis[v] = true;
	    }

	    if (iter[v]) {
		int w = g[v][iter[v]-1];
		if (v == par[w]) amin(low[v], low[w]);
		else if (in_vis[w]) amin(low[v], num[w]);
	    }

	    if (iter[v] < (int)g[v].size()) {
		int w = g[v][iter[v]++];
		if (num[w] == -1) {
		    par[w] = v;
		    st[st_i++] = w;
		}
	    } else {
		st_i--;
		if (low[v] == num[v]) {
		    while (1) {
			int w = vis[--vis_i]; in_vis[w] = false;
			scc[w] = cnt;
			if (v == w) break;
		    }
		    cnt++;
		}
	    }
	}
    }
    REP (v, n) scc[v] = cnt - 1 - scc[v];
    return cnt;
}

// shrink(false, false) returns directed forest, topological sorted;
Adj shrink(bool self_loop, bool parallel_edges) {
    Adj h(cnt);
    REP (v, n) EACH (e, g[v]) if (self_loop || scc[v] != scc[*e]) h[scc[v]].push_back(scc[*e]);
    if (!parallel_edges) REP (v, cnt) {
	sort(h[v].begin(), h[v].end());
	h[v].erase(unique(h[v].begin(), h[v].end()), h[v].end());
    }
    return h;
}
}; // namespace SCC;
struct TwoSAT {
    typedef vector<VI> Adj;
    int N, n;
    Adj G;
    vector<int>truth;
    bool sat;
    TwoSAT() {}
    TwoSAT(int n):n(n) { // n = number of variables
	N = n*2;
	G = Adj(N);
    }
    void add(int p, int q) { // p -> q
	G[p].push_back(q);
    }
    int inv(int p) { // id of ~p
	return (p+n)%N;
    }
    void IMP(int p, int q) { // p -> q
	add(p, q);
	add(inv(q), inv(p));
    }
    void T(int p) { // p is true : ~p -> p
	add(inv(p), p);
    }
    void OR(int p, int q) {
	IMP(inv(p), q);
    }
    void XOR(int p, int q) {
	IMP(p, inv(q));
	IMP(inv(p), q);
    }
    void EQ(int p, int q) {
	IMP(p, q);
	IMP(inv(p), inv(q));
    }
    bool SAT() {
	SCC::build(&G[0], N);
	sat = true; truth = vector<int>(n, 0);
	for (int i=0; i<n; i++) {
	    if (SCC::scc[i] == SCC::scc[i+n]) sat = false;
	    if (SCC::scc[i] > SCC::scc[i+n]) truth[i] = 1;
	}
	return sat;
    }
};

int N;
int M, K;

int T, F;

int ans[20011];

// : A[i] >= x;
int id(int i, int x) {
    if (x <= 0) return T;
    if (x > K) return F;
    return K * i + (x-1);
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);

    T = N * K;
    F = T + 1;
    TwoSAT sat(F+1);

    sat.T(T);
    sat.T(sat.inv(F));

    REP (i, N) {
	sat.T(id(i, 1));
	for (int a=2; a<=K; a++) sat.IMP(id(i, a), id(i, a-1));
    }
    REP (i, N-1) {
	for (int a=2; a<=K; a++) sat.IMP(id(i, a), id(i+1, a));
    }

    REP ($, M) {
	int op;
	scanf("%d", &op);
	if (op == 1) {
	    int i, x;
	    scanf("%d%d", &i, &x);
	    i--;
	    sat.EQ(id(i, x), id(i, x+1));
	} else {
	    int i, j, x;
	    scanf("%d%d%d", &i, &j, &x);
	    i--;
	    j--;
	    if (op == 2) {
		// a + b <= x;
		// b <= x - a;
		for (int a=1; a<=K; a++) {
		    int b = x - a;
		    sat.IMP(id(i, a), sat.inv(id(j, b+1)));
		    sat.IMP(id(j, a), sat.inv(id(i, b+1)));
		}
	    } else {
		// a + b >= x;
		// b >= x - a;
		for (int a=1; a<=K; a++) {
		    int b = x - a;
		    sat.IMP(sat.inv(id(i, a+1)), id(j, b));
		    sat.IMP(sat.inv(id(j, a+1)), id(i, b));
		}
	    }
	}
    }

    if (sat.SAT()) {
	REP (i, N) {
	    int cnt = 0;
	    for (int a=1; a<=K; a++) {
		if (sat.truth[id(i, a)]) cnt++;
	    }
	    ans[i] = cnt;
	}
	rprintf("%d", ans, ans+N);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}