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
};

LL powMod(LL x, LL y, LL m) {
    LL r = 1;
    for (; y; y>>=1) {
	if (y&1) r = r * x % m;
	x = x * x % m;
    }
    return r;
}
const LL MOD = 1e9+7;

Adj G;
int N, K;
vector<pair<int, int> > E;
int main() {
    scanf("%d", &N);
    G = Adj(N);
    REP (i, N-1) {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
	if (z) E.push_back(make_pair(x, y));
    }

    VI ord(1, 0), par(N, 0);
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    ord.push_back(*e);
	    par[*e] = v;
	}
    }

    LCA lca(G);

    VI U(N), D(N);

    int cur = 0;
    scanf("%d", &K);
    REP (k, K) {
	int nxt; scanf("%d", &nxt); nxt--;
//	eprintf("%d %d\n", cur, nxt);
	int l = lca.lca(cur, nxt);
	U[cur]++; U[l]--;
	D[nxt]++; D[l]--;

	cur = nxt;
    }


    for (int i=N; i--; ) {
	int v = ord[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    U[v] += U[*e];
	    D[v] += D[*e];
	}
    }

    LL ans = 0;
    EACH (e, E) {
	int x = e->first, y = e->second;
	if (lca.depth[x] > lca.depth[y]) ans += powMod(2, D[x], MOD) - 1;
	else ans += powMod(2, U[y], MOD) - 1;
    }

    ans = (ans % MOD + MOD) % MOD;
    printf("%d\n", (int)ans);

    return 0;
}