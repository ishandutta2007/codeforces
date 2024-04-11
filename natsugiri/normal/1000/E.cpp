#include<stack>
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

typedef vector<VI> Adj;

struct ArticulationPoint {
    vector<int> ord, low, art;
    vector<pair<int, int> > bridge;
    ArticulationPoint() {}
    ArticulationPoint(const Adj &G) {
	int n = G.size();
	ord.assign(n, -1); low.assign(n, 0); art.assign(n, 0);
	int cnt = 0;
	REP (i, n) if (ord[i] == -1) {
	    stack<int> S, P;
	    S.push(i); P.push(-1);
	    while (!S.empty()) {
		int v = S.top(), p = P.top(); S.pop(); P.pop();
		if (v >= 0 && ord[v] == -1) {
		    S.push(v-n); P.push(p);
		    ord[v] = low[v] = cnt++;
		    EACH (e, G[v]) {
			if (ord[*e] == -1) { S.push(*e); P.push(v); }
			else if (*e == p) p = -1;
			else low[v] = min(low[v], ord[*e]);
		    }
		}
		if (v < 0 && p >= 0) {
		    v += n;
		    low[p] = min(low[p], low[v]);
		    if (ord[p] <= low[v]) art[p]++;
		    if (ord[p] < low[v]) bridge.push_back(make_pair(min(p, v), max(p, v)));
		}
	    }
	    if (art[i]) art[i]--;
	}
    }
    // {v, w} must be an edge
    bool is_bridge(int v, int w) { return ord[v] < low[w] || ord[w] < low[v]; }
    // the number of increasing CC
    int art_size(int v) { return art[v]; }
    vector<int> ecc;
    Adj ecc_shrink(const Adj &G) { // returns Forest
	int n = G.size();
	ecc.assign(n, -1);
	int cnt = 0;
	REP (i, n) if (ecc[i] == -1) {
	    stack<int> S; S.push(i);
	    while (!S.empty()) {
		int v = S.top(); S.pop();
		if (ecc[v] != -1) continue;
		ecc[v] = cnt;
		EACH (e, G[v]) if (ecc[*e] == -1 && !is_bridge(v, *e)) S.push(*e);
	    }
	    cnt++;
	}
	Adj X(cnt);
	EACH (e, bridge) {
	    int a = ecc[e->first], b = ecc[e->second];
	    X[a].push_back(b);
	    X[b].push_back(a);
	}
	return X;
    }
};

int N, M;
Adj G, T;

int len[300011];
VI ord;
int bfs(int s) {
    memset(len, 0x3f, sizeof len);
    len[s] = 0;
    ord.clear();
    ord.push_back(s);
    REP (i, T.size()) {
	int v = ord[i];
	EACH (e, T[v]) if (len[*e] > len[v] + 1) {
	    len[*e] = len[v] + 1;
	    ord.push_back(*e);
	}
    }

    return max_element(len, len + T.size()) - len;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    G.resize(N);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    T = ArticulationPoint(G).ecc_shrink(G);

//    REP (i, T.size()) {
//	printf("%d : ", i);
//	rprintf("%d", T[i].begin(), T[i].end());
//    }

    int x = bfs(0);
    int y = bfs(x);
    int ans = len[y];
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}