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

const int MAXN = 200111;
int N, M;

struct Edge {
    int to;
    LL cost;
    Edge(int to_=0, LL cost_=0) {
	to = to_;
	cost = cost_;
    }
    bool operator<(const Edge &y) const {
	return cost > y.cost;
    }
};

vector<Edge> G[MAXN];

LL C[MAXN];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int u, v;
	LL w;
	scanf("%d%d%lld", &u, &v, &w);
	u--; v--;
	G[u].emplace_back(v, w);
	G[v].emplace_back(u, w);
    }

    REP (i, N) scanf("%lld", C+i); 

    priority_queue<Edge> Q;
    REP (i, N) {
	Q.emplace(i, C[i]);
    }
    while (!Q.empty()) {
	Edge h = Q.top(); Q.pop();
	if (h.cost > C[h.to]) continue;
	EACH (e, G[h.to]) {
	    LL cost = h.cost + e->cost * 2;
	    if (C[e->to] > cost) {
		C[e->to] = cost;
		Q.emplace(e->to, cost);
	    }
	}
    }

    rprintf("%lld", C, C+N);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}