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
    int n;
    vector<int> U;
    UnionFind() {}
    UnionFind(int n_): n(n_), U(n, -1) {}
    int root(int x) {
	if (U[x] < 0) return x;
	return U[x] = root(U[x]);
    }
    int link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return x;
	if (U[y] < U[x]) swap(x, y);
	U[x] += U[y];
	n--;
	return U[y] = x;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size() { return n; }
    int count(int x) { return -U[root(x)]; }
};

int N;
int A[200111];
VI G[200111];
int X[200111], Y[200111];

int par[200111];
int len[200111];

int calc(int s) {
    memset(par, -1, sizeof par);
    memset(len, 0x3f, sizeof len);
    par[s] = s;
    len[s] = 0;
    VI ord(1, s);
    for (int i=0; i<(int)ord.size(); i++) {
	int v = ord[i];
	EACH (e, G[v]) if (*e != par[v]) {
	    par[*e] = v;
	    len[*e] = len[v] + 1;
	    ord.push_back(*e);
	}
    }
    return ord.back();
}

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    UnionFind U(N);

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	X[i] = x; Y[i] = y;
	if (A[x] == A[y]) U.link(x, y);
    }

    REP (i, N-1) {
	int x = U.root(X[i]);
	int y = U.root(Y[i]);
	if (A[x] != A[y]) {
	    G[x].push_back(y);
	    G[y].push_back(x);
	}
    }

    int root = 0;
    REP (i, N) if (U.root(i) == i) root = i;

    int v1 = calc(root);
    int v2 = calc(v1);

    int ans = (len[v2] + 1) / 2;
    printf("%d\n", ans);

    return 0;
}