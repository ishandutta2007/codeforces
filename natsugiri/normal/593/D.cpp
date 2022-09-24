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
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

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


typedef unsigned long long ULL;;
const int MAXN = 200011;
int N, A[MAXN], B[MAXN], Q;
int link[MAXN];
ULL C[MAXN], R[MAXN];
Adj G;
LCA lca;

int linker(int v) {
    if (v == 0 || R[v] > 1) return v;
    return link[v] = linker(link[v]);
}
ULL up(int v, int l, ULL y) {
    while (true) {
	if (y == 0 || lca.depth[v] <= lca.depth[l]) return y;
	y /= R[v];
	v = linker(link[v]);
    }
}

int main() {
    scanf("%d%d", &N, &Q);
    G = Adj(N);
    REP (i, N-1) {
	scanf("%d%d%llu",A+i, B+i, C+i);
	A[i]--; B[i]--;
	G[A[i]].push_back(B[i]);
	G[B[i]].push_back(A[i]);
    }

    lca = LCA(G);

    REP (i, N-1) {
	if (lca.depth[A[i]] < lca.depth[B[i]]) { R[B[i]] = C[i]; link[B[i]] = A[i]; }
	else { R[A[i]] = C[i]; link[A[i]] = B[i]; }
    }
    
    REP (_, Q) {
	char op[9];
	scanf("%s", op);
	if (op[0] == '1') {
	    int a, b;
	    ULL y;
	    scanf("%d%d%llu", &a, &b, &y);
	    a--; b--;
	    int l = lca(a, b);
	    y = up(a, l, y);
	    y = up(b, l, y);
	    printf("%llu\n", y);
	} else {
	    int p; ULL c;
	    scanf("%d%llu", &p, &c);
	    p--;
	    C[p] = c;
	    if (lca.depth[A[p]] < lca.depth[B[p]]) C[p] = R[B[p]] = c;
	    else C[p] = R[A[p]] = c;
	}
    }
    return 0;
}