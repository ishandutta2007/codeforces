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

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

namespace SCC {
const int MAXN = 2600000;
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
int Q;
VI G[400011];
int par[400011];
int depth[400011];

VI P[400011];
string S[400011];
char buf[400011];

vector<char> SE[400011];
VI ID[400011];


void MAIN() {
    scanf("%d%d", &N, &Q);

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    VI que;
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    depth[*e] = depth[v] + 1;
	    que.push_back(*e);
	}
    }

    VI xs, ys;
    REP (j, Q) {
	int x, y;
	scanf("%d%d%s", &x, &y, buf);
	x--; y--;

	xs.clear();
	ys.clear();
	while (x != y) {
	    if (depth[x] > depth[y]) {
		xs.push_back(x);
		x = par[x];
	    } else {
		ys.push_back(y);
		y = par[y];
	    }
	}

	xs.push_back(x);
	xs.insert(xs.end(), ys.rbegin(), ys.rend());
	P[j] = xs;
	S[j] = buf;
    }

    REP (j, Q) {
	int len = P[j].size();
	REP (k, len) {
	    SE[P[j][k]].push_back(S[j][k]);
	    SE[P[j][k]].push_back(S[j][len-1-k]);
	}
    }

    // [0, Q), [Q, cnt);
    int cnt = Q;
    REP (v, N) {
	sort_unique(SE[v]);
	REP (j, SE[v].size()) ID[v].push_back(cnt++);
    }

    TwoSAT SAT(cnt);
    REP (j, Q) {
	int len = P[j].size();
	REP (k, len) {
	    int v = P[j][k];
	    int pos = lower_bound(SE[v].begin(), SE[v].end(), S[j][k]) - SE[v].begin();
	    SAT.IMP(j, ID[v][pos]);

	    pos = lower_bound(SE[v].begin(), SE[v].end(), S[j][len-1-k]) - SE[v].begin();
	    SAT.IMP(SAT.inv(j), ID[v][pos]);
	}
    }

    REP (v, N) {
	REP (a, ID[v].size()) REP (b, ID[v].size()) if (a < b) {
	    SAT.IMP(ID[v][a], SAT.inv(ID[v][b]));
	}
    }

    SAT.SAT();
    if (SAT.sat) {
	puts("YES");
	REP (v, N) {
	    if (ID[v].empty()) {
		putchar('z');
	    } else {
		int cnt = 0;
		REP (a, ID[v].size()) {
		    if (SAT.truth[ID[v][a]]) {
			cnt++;
			putchar(SE[v][a]);
		    }
		}
		assert(cnt == 1);
	    }
	}
	putchar('\n');
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