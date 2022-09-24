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


int N;
char S[111];
int B[111];
int cnt[26];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);
    REP (i, N) scanf("%d", B+i);

    int LV_1 = 0, LV_2 = LV_1 + N/2, SRC = LV_2 + 26, SNK = SRC+1;
    MinCostMaxFlow D(SNK+1);

    const int BASE = 100;

    REP (i_, N/2) {
	int i = i_, j = N-1-i;
	int z = LV_1 = i_;
	D.add_edge(SRC, z, 0, 2);

	REP (c, 26) {
	    if (c == S[i]-'a' && c == S[j]-'a') {
		D.add_edge(z, LV_2 + c, BASE - max(B[i], B[j]), 1);
	    } else if (c == S[i]-'a') {
		D.add_edge(z, LV_2 + c, BASE - B[i], 1);
	    } else if (c == S[j]-'a') {
		D.add_edge(z, LV_2 + c, BASE - B[j], 1);
	    } else {
		D.add_edge(z, LV_2 + c, BASE, 1);
	    }
	}
    }

    REP (i, N) cnt[S[i]-'a']++;
    REP (c, 26) {
	D.add_edge(LV_2 + c, SNK, 0, cnt[c]);
    }

    D.solve(SRC, SNK);

//    eprintf("%d %d\n", D.flow, D.cost);
    printf("%d\n", BASE * N - D.cost);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}