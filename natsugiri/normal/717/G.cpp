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

// MOD 2^64
typedef unsigned long long ULL;
struct RollingHash {
    static const ULL BASE = 2e9 + 11; // 3e9+19, 4e9+7 
    static const int MAX_LEN = 1000000;
    static const vector<ULL>powB;
    static const vector<ULL>buildB();
    vector<char> S;
    vector<ULL> H; // H[i] := hash(S[0 .. i])
    RollingHash(const string &str) {
	init(str);
    }
    void init(const string &str) {
	S.clear(); H.assign(1, 0ULL);
	for (int i=0; i<(int)str.size(); i++) {
	    S.push_back(str[i]);
	    H.push_back(H.back() * BASE + str[i]);
	}
    }
    ULL get(int l, int r) { // hash(S[l .. r-1])
	return H[r] - H[l] * powB[r-l];
    }
    void push(char c) {
	S.push_back(c);
	H.push_back(H.back() * BASE + c);
    }
    void pop() {
	S.pop_back();
	H.pop_back();
    }
};
const vector<ULL>RollingHash::buildB() {
    vector<ULL>h(MAX_LEN);
    h[0] = 1;
    for (int i=1; i<MAX_LEN; i++) h[i] = h[i-1]*BASE;
    return h;
}
const vector<ULL>RollingHash::powB = RollingHash::buildB();


int N, M, X;
char buf[99999];
string S, W[111];
int P[111];

int main() {
    scanf("%d", &N);
    scanf("%s", buf);
    S = buf;
    scanf("%d", &M);
    REP (i, M) {
	scanf("%s%d", buf, P+i);
	W[i] = buf;
    }
    scanf("%d", &X);


    RollingHash RH(S);

    int src = 0, snk = N + 1;
    const int BASE = 1000;

    MinCostMaxFlow F(snk+1);
    REP (j, M) {
	RollingHash sub(W[j]);
	int len = W[j].size();
	ULL h = sub.get(0, len);
	REP (i, N-len+1) {
	    if (RH.get(i, i+len) == h) {
		F.add_edge(i, i+W[j].size(), len * BASE - P[j], 1);
	    }

	}
    }

    REP (i, N) {
	F.add_edge(i, i+1, BASE, X);
    }
    F.add_edge(N, snk, 0, X);

    F.solve(src, snk);
    int ans = BASE * N * X - F.cost;
//    eprintf("%d %d %d\n", F.flow, F.cost, BASE * N * X);
    printf("%d\n", ans);

    return 0;
}