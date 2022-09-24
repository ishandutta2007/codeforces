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

struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};

int N, M, Q;
const int MAXN = 300111;
VI G[MAXN];
int par[MAXN], len[MAXN];
int mem[MAXN];

VI ord;
int bfs(int s) {
    ord.clear();
    ord.push_back(s);
    par[s] = -1;
    len[s] = 0;
    int ret = s;
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	if (len[ret] < len[v]) ret = v;
	
	EACH (e, G[v]) if (par[v] != *e) {
	    par[*e] = v;
	    ord.push_back(*e);
	    len[*e] = len[v] + 1;
	}
    }

    return ret;
}

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    UnionFind U(N);

    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	U.link(x, y);
	G[x].push_back(y);
	G[y].push_back(x);
    }

    REP (s, N) if (U.root(s) == s) {
	int x = bfs(s);
    	int y = bfs(x);
	mem[s] = len[y];
    }

    REP ($, Q) {
	char op[11];
	scanf("%s", op);
	if (*op == '1') {
	    int x;
	    scanf("%d", &x);
	    x--;
	    x = U.root(x);
	    printf("%d\n", mem[x]);
	} else {
	    int x, y;
	    scanf("%d%d", &x, &y);
	    x--; y--;
	    x = U.root(x); y = U.root(y);
	    if (x != y) {
		U.link(x, y);
		int z = U.root(x);
		mem[z] = max({mem[x], mem[y], (mem[x]+1)/2 + (mem[y]+1)/2 + 1 });
	    }
	}
    }
    


    return 0;
}