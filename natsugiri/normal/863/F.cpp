#include<queue>
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
struct MinCostMaxFlow {
    typedef int Flow;
    typedef int Cost;
    static const Flow FLOW_INF = 1<<29;
    static const Cost COST_INF = 1<<29;
    struct Edge {
	int src, dst;
	Cost cst;
	Flow cap;
	int rev;
	bool operator<(const Edge&y) const {
	    return cst > y.cst;
	}
    };
    typedef vector<vector<Edge> > Graph;
    Graph G;
    MinCostMaxFlow(int N) : G(N) {}
    // directed
    void add_edge(int u, int v, Cost x, Flow f) {
	G[u].push_back((Edge){ u, v, x, f, (int)G[v].size() });
	G[v].push_back((Edge){ v, u, -x, 0, (int)G[u].size()-1 });
    }

    Flow flow;
    Cost cost;
    Flow solve(int s, int t, Flow limit = FLOW_INF) {
	flow = 0;
	cost = 0;
	vector<Cost>len, h(G.size(), 0);
	vector<int> prev, prev_num;
	while (limit > 0) {
	    priority_queue<Edge> Q;
	    Q.push((Edge){-2, s, 0, 0, 0});
	    len.assign(G.size(), COST_INF);
	    prev.assign(G.size(), -1); prev_num.assign(G.size(), -1);
	    len[s] = 0;
	    while (!Q.empty()) {
		Edge e = Q.top(); Q.pop();
		if (e.cst > len[e.dst]) continue;
//		if (e.dst == t) break;
		for (int i=0; i<(int)G[e.dst].size(); i++) {
		    const Edge &f = G[e.dst][i];
		    if (f.cap > 0 && len[f.dst] > len[f.src] + f.cst + h[f.src] - h[f.dst]) {
			len[f.dst] = len[f.src] + f.cst + h[f.src] - h[f.dst];
			Q.push((Edge){ f.src, f.dst, len[f.dst], 0, 0 });
			prev[f.dst] = f.src; prev_num[f.dst] = i;
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
const MinCostMaxFlow::Flow MinCostMaxFlow::FLOW_INF;
const MinCostMaxFlow::Cost MinCostMaxFlow::COST_INF;

int N, Q;
int atLeast[55], atMost[55];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) atMost[i] = N-1;

    REP ($, Q) {
	int op, l, r, v;
	scanf("%d%d%d%d", &op, &l, &r, &v);
	l--;
	v--;

	if (op == 1) {
	    for (int i=l; i<r; i++) amax(atLeast[i], v);
	} else {
	    for (int i=l; i<r; i++) amin(atMost[i], v);
	}
    }

    bool yes = true;
    REP (i, N) if (atLeast[i] > atMost[i]) yes = false;
    if (!yes) {
	puts("-1");
	return ;
    }

    int src = 2 * N, snk = src + 1;
    MinCostMaxFlow G(snk + 1);
    REP (i, N) {
	G.add_edge(src, i, 0, 1);
	for (int j=atLeast[i]; j<=atMost[i]; j++) {
	    G.add_edge(i, j + N, 0, 1);
	}
	REP (j, N) {
	    G.add_edge(i + N, snk, 2 * j + 1, 1);
	}
    }

    G.solve(src, snk);
    if (G.flow != N) {
	puts("-1");
    } else {
	printf("%d\n", G.cost);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}