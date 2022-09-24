#include<stack>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
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

/*
struct ArticulationPoint {
    vector<int> ord, low, art;
    int cnt;
    //vector<pair<int, int> > bridge;
    ArticulationPoint(){}
    ArticulationPoint(const Adj&G) {
	int n = G.size();
	cnt = 0;
	ord.assign(n, -1); low.assign(n, 0); art.assign(n, 0);
	for (int i=0; i<n; i++) {
	    if (ord[i] == -1) {
		dfs(G, i, -1);
		if (art[i]) art[i]--;
	    }
	}
    }
    void dfs(const Adj&G, int v, int p) {
	ord[v] = low[v] = cnt++;
	for (int i=0; i<(int)G[v].size(); i++) {
	    int w = G[v][i];
	    if (ord[w] == -1) {
		dfs(G, w, v);
		low[v] = min(low[v], low[w]);
		if (ord[v] <= low[w]) art[v]++;
		//if (ord[v] < low[w]) bridge.push_back(make_pair(min(v, w), max(v, w)));
	    } else if (w != p) low[v] = min(low[v], ord[w]); 
	    else p = -1;
	}
    }
    // {v, w} must be an edge
    bool is_bridge(int v, int w) { return ord[v] < low[w] || ord[w] < low[v]; }
    // the number of increasing CC
    int is_art(int v) { return art[v]; }
};
*/

const int MAX_V = 1000000;
const int LOG_V = 20;

struct LCA {
    vector<int> depth;
    vector<vector<int> > par; // par[v][i] : v's 2^i ancestor
    LCA() {}
    LCA(const Adj &G, int r=0) {
	int n = G.size();
	par = vector<vector<int> >(n, vector<int>(LOG_V));
	depth = vector<int>(n);
	stack<int>vv, pp; // Stack DFS
	vv.push(r); pp.push(r);
	depth[r] = 0;
	for (;!vv.empty();) {
	    int v = vv.top(), p = pp.top();
	    vv.pop(); pp.pop();
	    par[v][0] = p;
	    for (int i=0; i<(int)G[v].size(); i++) {
		if (G[v][i] == p) continue;
		vv.push(G[v][i]);
		pp.push(v);
		depth[G[v][i]] = depth[v]+1;
	    }
	}
	for (int i=1; i<LOG_V; i++) {
	    for (int v=0; v<n; v++) par[v][i] = par[par[v][i-1]][i-1];
	}
    }
    int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y); // x must be deeper
	for (int i=0; depth[x] != depth[y]; i++) {
	    if ((depth[x]-depth[y]) & (1<<i)) x = par[x][i];
	}
	if (x == y) return x;
	for (int i=LOG_V; i--;) {
	    if (par[x][i] != par[y][i]) { x=par[x][i]; y=par[y][i]; }
	}
	return par[x][0];
    }
    int dist(int x, int y) { // number of edges in {x -- y}
	int z = lca(x, y);
	return depth[x] + depth[y] - 2 * depth[z];
    }
    int kth(int x, int y, int k) { // assert( dist(x, y) >= k );
	int z = lca(x, y);
	if (depth[x] - depth[z] < k) {
	    k = depth[x] + depth[y] - 2 * depth[z] - k;
	    x = y;
	}
	for (int i=LOG_V; i--;)
	    if (k & (1<<i)) x = par[x][i];
	return x;
    }
};

// verified SPOJ/LCA
const int MAX = 200011;
int N, M, Q;
Adj G;
ArticulationPoint AP;

int name[MAX];
bool use[MAX];

Adj shrink() {
    int cnt = 1;
    REP (i, N) if (!name[i]) {
	stack<int> S; S.push(i);
	name[i] = cnt;
	while (!S.empty()) {
	    int v = S.top(); S.pop();
	    EACH (e, G[v]) if (!AP.is_bridge(v, *e) && !name[*e]) {
		name[*e] = cnt;
		S.push(*e);
	    }
	}
	cnt++;
    }

    Adj X(cnt);
    REP (i, N) EACH (e, G[i]) if (AP.is_bridge(i, *e)) {
	X[name[i]].push_back(name[*e]);
//	X[name[*e]].push_back(name[i]);
    }

    use[0] = true;
    REP (i, cnt) if (!use[i]) {
	stack<int> S;
	S.push(i);
	use[i] = true;
	while (!S.empty()) {
	    int v = S.top(); S.pop();
	    EACH (e, X[v]) if (!use[*e]) {
		S.push(*e);
		use[*e] = true;
	    }
	}
	    

	X[0].push_back(i);
	X[i].push_back(0);
    }

//    REP (i, cnt) EACH (e, X[i]) eprintf("%d %d\n", i, *e);
    return X;
}

Adj X;
int U[MAX], D[MAX];
void dfs(int v, int p) {
    EACH (e, X[v]) if (*e != p) {
	dfs(*e, v);
	U[v] += U[*e];
	D[v] += D[*e];
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    G.resize(N);
    REP (i, M) {
	int a, b;
	scanf("%d%d", &a, &b); a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    AP = ArticulationPoint(G);
    X = AP.ecc_shrink(G);
//    EACH (e, AP.bridge) eprintf("%d - %d\n", e->first, e->second);
//    REP (i, N) eprintf("%d ", AP.low[i]); eprintf("\n");
//    REP (i, X.size()) EACH (e, X[i]) eprintf("%d -> %d\n", i, *e);
    int root = X.size();
    {
	X.push_back(VI());
	vector<bool> use(root, 0);
	REP (i, root) if (!use[i]) {
	    X[root].push_back(i);
	    stack<int> S;
	    S.push(i); use[i] = true;
	    while (!S.empty()) {
		int v = S.top(); S.pop();
		EACH (e, X[v]) if (!use[*e]) {
		    S.push(*e); use[*e] = true;
		}
	    }
	}
    }

    LCA lca(X, root);

    REP ($, Q) {
	int x, y, z;
	scanf("%d%d", &x, &y);
	//x = name[x-1]; y = name[y-1];
	x = AP.ecc[x-1]; y = AP.ecc[y-1];
	z = lca.lca(x, y);
//	eprintf("%d %d %d\n", x, y, z);
	U[x]++; U[z]--;
	D[y]++; D[z]--;
    }

    bool yes = true;
    dfs(root, root);
//    REP (i, X.size()) eprintf("%d %d\n", U[i], D[i]);

    REP (i, root) {
	if (U[i] && D[i]) yes = false;
    }
    EACH (e, X[root]) {
	if (U[*e] || D[*e]) yes = false;
    }
    
    puts(yes ? "Yes" : "No");

    return 0;
}