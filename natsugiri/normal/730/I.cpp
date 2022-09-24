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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
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
		if (e.dst == t) break;
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



int N, P, S;
int A[3011], B[3011];
int name[3011];

int main() {
    scanf("%d%d%d", &N, &P, &S);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    int node_p = N, node_s = node_p + 1, src = node_s + 1, snk = src + 1;
    MinCostMaxFlow X(snk + 1);
    const int BASE = 3111;

    REP (i, N) name[i] = i;
    random_shuffle(name, name+N);

    X.add_edge(node_p, src, 0, P);
    X.add_edge(node_s, src, 0, S);
    REP (i, N) {
	X.add_edge(i, node_s, BASE - B[name[i]], 1);
	X.add_edge(i, node_p, BASE - A[name[i]], 1);
	X.add_edge(snk, i, 0, 1);
    }

    X.solve(snk, src);
    printf("%d\n", BASE * (P + S) - X.cost);

    bool sp = false;
    EACH (e, X.G[node_p]) {
	if (e->dst < N && e->cap == 1) {
	    if (sp) putchar(' ');
	    sp = true;
	    printf("%d", name[e->dst]+1);
	}
    }
    putchar('\n');
    sp = false;
    EACH (e, X.G[node_s]) {
	if (e->dst < N && e->cap == 1) {
	    if (sp) putchar(' ');
	    sp = true;
	    printf("%d", name[e->dst]+1);
	}
    }
    putchar('\n');
    
    return 0;
}