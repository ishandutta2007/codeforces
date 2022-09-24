#include<stack>
#include<map>
#include<set>
#include<assert.h>
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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

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
Adj G;
int A[400111], B[400111];
bool use[400111];
bool in_cluster[400111];
set<pair<int, int> > edges;

int par[400111];
int iter[400111];

bool is_fixed(int x, int y) {
    if (edges.find(make_pair(x, y)) != edges.end()) return true;
    if (edges.find(make_pair(y, x)) != edges.end()) return true;
    return false;
}


int main() {
    scanf("%d%d", &N, &M);
    G = Adj(N);
    REP (i, M) {
	scanf("%d%d", A+i, B+i);
	A[i]--;
	B[i]--;

	G[A[i]].push_back(B[i]);
	G[B[i]].push_back(A[i]);
    }

    ArticulationPoint AP(G);
    Adj H = AP.ecc_shrink(G);
    int root = 0;

    {
	map<int, int> mp;
	EACH (e, AP.ecc) mp[*e]++;
	EACH (e, mp) if (mp[root] < e->second) root = e->first;
    }


    VI cluster;
    REP (i, N) if (AP.ecc[i] == root) cluster.push_back(i);



    // bfs ecc
    {
	memset(use, 0, sizeof use);
	VI ord = cluster;
	EACH (e, cluster) use[*e] = true;

	REP (i, N) {
	    int v = ord[i];
	    EACH (e, G[v]) if (!use[*e]) {
		edges.insert(make_pair(*e, v));
		use[*e] = true;
		ord.push_back(*e);
	    }
	}
    }

    // bfs cluster
    {
	memset(use, 0, sizeof use);
	memset(par, -1, sizeof par);
	EACH (e, cluster) use[*e] = true;
	VI ord; ord.push_back(cluster[0]);
	par[cluster[0]] = -2;
	stack<int> S;
	S.push(cluster[0]);
	while (!S.empty()) {
	    int v = S.top(); S.pop();
	    if (iter[v] < (int)G[v].size()) {
		S.push(v);
		int w = G[v][iter[v]++];
		if (use[w] && !is_fixed(v, w)) {
		    edges.insert(make_pair(v, w));
		    S.push(w);
		}
	    }
	}
    }

    printf("%d\n", (int)cluster.size());
    REP (i, M) {
	if (edges.find(make_pair(B[i], A[i])) != edges.end()) swap(A[i], B[i]);
	printf("%d %d\n", A[i] + 1, B[i] + 1);
    }

    
    return 0;
}