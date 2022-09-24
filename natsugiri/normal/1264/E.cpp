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
namespace MIN_COST_MAX_FLOW {
typedef LL Flow;
typedef LL Cost;
const Flow FLOW_INF = 1LL<<60;
const Cost COST_INF = 1LL<<60;

const int SIZE = 65;
vector<pair<Cost, int> > B[SIZE];
Cost last;
int sz;

int bsr(Cost c) {
    if (c == 0) return 0;
    return __lg(c)+1;
}

void init() {
    last = sz = 0;
    REP (i, SIZE) B[i].clear();
}

void push(Cost cst, int v) {
    assert(cst >= last);
    sz++;
    B[bsr(cst^last)].emplace_back(cst, v);
}

pair<Cost, int> pop_min() {
    assert(sz);
    if (B[0].empty()) {
	int k = 1;
	while (k < SIZE && B[k].empty()) k++;
	assert(k < SIZE);
	last = B[k][0].first;
	EACH (e, B[k]) amin(last, e->first);
	EACH (e, B[k]) B[bsr(e->first^last)].push_back(*e);
	B[k].clear();
    }
    assert(B[0].size());
    pair<Cost, int> ret = B[0].back();
    B[0].pop_back();
    sz--;
    return ret;
}

struct MinCostMaxFlow {
    struct Edge {
	int dst;
	Cost cst;
	Flow cap;
	int rev;
    };
    typedef vector<vector<Edge> > Graph;
    Graph G;
    bool negative_edge;
    MinCostMaxFlow(int N) : G(N) {
	negative_edge = false;
    }

    void add_edge(int u, int v, Cost x, Flow f) {
	if (u == v) return;
	if (x < 0) negative_edge = true;
	G[u].push_back((Edge){ v, x, f, (int)G[v].size() });
	G[v].push_back((Edge){ u, -x, 0, (int)G[u].size()-1 });
    }

    void bellman_ford(int s, vector<Cost> &h) {
	fill(h.begin(), h.end(), COST_INF);
	vector<bool> in(G.size());
	h[s] = 0;
	in[s] = true;
	VI front, back;
	front.push_back(s);
	while (1) {
	    if (front.empty()) {
		if (back.empty()) return;
		swap(front, back);
		reverse(front.begin(), front.end());
	    }
	    int v = front.back(); front.pop_back();
	    in[v] = false;
	    EACH (e, G[v]) if (e->cap) {
		int w = e->dst;
		if (h[w] > h[v] + e->cst) {
		    h[w] = h[v] + e->cst;
		    if (!in[w]) {
			back.push_back(w);
			in[w] = true;
		    }
		}
	    }
	}
    }

    Flow flow;
    Cost cost;
    Flow solve(int s, int t, Flow limit = FLOW_INF) {
	flow = 0;
	cost = 0;
	vector<Cost>len(G.size()), h(G.size());
	if (negative_edge) bellman_ford(s, h);

	vector<int> prev(G.size()), prev_num(G.size());
	while (limit > 0) {
	    init(); push(0, s);
	    fill(len.begin(), len.end(), COST_INF);
	    fill(prev.begin(), prev.end(), -1);
	    len[s] = 0;
	    while (sz) {
		pair<Cost, int> p = pop_min();
		Cost cst = p.first;
		int v = p.second;
		if (cst > len[v]) continue;
		for (int i=0; i<(int)G[v].size(); i++) {
		    const Edge &f = G[v][i];
		    Cost tmp = len[v] + f.cst + h[v] - h[f.dst];
		    if (f.cap > 0 && len[f.dst] > tmp) {
			len[f.dst] = tmp;
			push(tmp, f.dst);
			prev[f.dst] = v; prev_num[f.dst] = i;
		    }
		}
	    }

	    if (prev[t] == -1) return flow;
	    for (int i=0; i<(int)G.size(); i++) h[i] += len[i];
	    
	    Flow f = limit;
	    for (int v=t; v!=s; v=prev[v])
		f = min(f, G[prev[v]][prev_num[v]].cap);
	    for (int v=t; v!=s; v=prev[v]) {
		Edge &e = G[prev[v]][prev_num[v]];
		e.cap -= f;
		G[e.dst][e.rev].cap += f;
	    }
	    limit -= f;
	    flow += f;
	    cost += f * h[t];
	}
	return flow;
    }
};
}; // namespace MIN_COST_MAX_FLOW;
using MinCostMaxFlow = MIN_COST_MAX_FLOW::MinCostMaxFlow;

int N, M;
char F[55][55];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	F[x][y] = '1';
	F[y][x] = '0';
    }

    const int R = N * (N-1) / 2;
    const int SRC = R + N;
    const int SNK = SRC + 1;
    MinCostMaxFlow X(SNK + 1);

    int cnt = 0;
    REP (i, N) REP (j, i) {
	X.add_edge(SRC, cnt, 0, 1);

	if (F[i][j] == '1') {
	    X.add_edge(cnt, R + i, 0, 1);
	} else if (F[i][j] == '0') {
	    X.add_edge(cnt, R + j, 0, 1);
	} else {
	    X.add_edge(cnt, R + i, 0, 1);
	    X.add_edge(cnt, R + j, 0, 1);
	}

	cnt++;
    }
    REP (i, N) {
	REP (j, N) {
	    X.add_edge(R + i, SNK, j*2+1, 1);
	}
    }

    X.solve(SRC, SNK);

    cnt = 0;
    REP (i, N) REP (j, i) {
	EACH (e, X.G[cnt]) {
	    if (R <= e->dst && e->dst < R + N && e->cap == 0) {
		int a = e->dst - R;
		F[a][i^j^a] = '1';
		F[i^j^a][a] = '0';
	    }
	}
	cnt++;
    }

    REP (i, N) F[i][i] = '0';
    REP (i, N) puts(F[i]);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}