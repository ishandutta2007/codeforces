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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }
// G : Adjacent list of BIDIRECTED tree
// r : root

typedef vector<vector<int> > Adj;
const int MAX_V = 1000000;
const int LOG_V = 20;

struct LCA {
    vector<int> depth;
    vector<vector<int> > par; // par[v][i] : v's 2^i ancestor
    LCA() {}
    LCA(const Adj &G, int r=0) {
	int n = G.size();
	par = vector<vector<int> >(n, vector<int>(LOG_V, -1));
	depth = vector<int>(n);
	vector<int> ord; ord.reserve(n);
	ord.push_back(r);
	par[r][0] = r;
	REP (i, n) {
	    int v = ord[i];
	    EACH (e, G[v]) if (*e != par[v][0]) {
		par[*e][0] = v;
		ord.push_back(*e);
		depth[*e] = depth[v]+1;
	    }
	}
	for (int i=1; i<LOG_V; i++) {
	    for (int v=0; v<n; v++) par[v][i] = par[par[v][i-1]][i-1];
	}
    }
    int operator()(int x, int y) {
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
    int lca(int x, int y) {
	return (*this)(x, y);
    }
    int dist(int x, int y, int z=-1) { // number of edges in {x -- y}
	if (z == -1) z = lca(x, y);
	return depth[x] + depth[y] - 2 * depth[z];
    }
    int kth(int x, int y, int k, int z=-1) { // assert( dist(x, y) >= k );
	if (z == -1) z = lca(x, y);
	if (depth[x] - depth[z] < k) {
	    k = depth[x] + depth[y] - 2 * depth[z] - k;
	    x = y;
	}
	for (int i=LOG_V; i--;)
	    if (k & (1<<i)) x = par[x][i];
	return x;
    }
};

const int MAXN = 100111;
int N, M;
VI G[MAXN];
int par[MAXN];
int subsz[MAXN];
LL chsum[MAXN];
LL otsum[MAXN];

bool use[MAXN];
VI ord;

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    ord.reserve(N);
    ord.push_back(0);
    par[0] = -1;
    REP (i, N) {
	int v = ord[i];
	use[v] = true;
	EACH (e, G[v]) if (!use[*e]) {
	    par[*e] = v;
	    ord.push_back(*e);
	}
    }
    for (int i=N; i--;) {
	int v =  ord[i];
	subsz[v] = 1;
	EACH (e, G[v]) if (*e != par[v]) {
	    subsz[v] += subsz[*e];
	    chsum[v] += chsum[*e] + subsz[*e];
	}
    }
    REP (i, N) {
	int v = ord[i];
	if (v == 0) continue;

	int c = N - subsz[v];
	otsum[v] = otsum[par[v]] + chsum[par[v]] - (chsum[v] + subsz[v]) + c;
    }


    LCA lca(Adj(G, G+N));
    
    REP ($, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;

	double nu = 0, de = 0;
	
	int l = lca(x, y);
	if (l == y) swap(x, y);
	if (l == x) {
	    int x1 = lca.kth(x, y, 1, x);
	    int c = N - subsz[x1];
	    LL g = otsum[x] + chsum[x] - (chsum[x1] + subsz[x1]);

	    de = (double)c * subsz[y];
	    int len = lca.dist(x, y, x);
	    nu += (len + 1) * de;
	    nu += (double)g * subsz[y] + (double)chsum[y] * c;
	} else {
	    de = (double)subsz[x] * subsz[y];
	    int len = lca.dist(x, y, l);
	    nu += (len + 1) * de;
	    nu += (double)chsum[x] * subsz[y] + (double)chsum[y] * subsz[x];
	}

	printf("%.9f\n", nu / de);
    }
    return 0;
}