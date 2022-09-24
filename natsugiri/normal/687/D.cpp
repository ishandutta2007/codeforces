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
    void reset() { n = U.size(); fill(U.begin(), U.end(), -1); }
};

int N, M, Q;
struct Edge {
    int a, b, c, id;
    Edge() {}
    Edge(int a_, int b_, int c_, int i_) : a(a_), b(b_), c(c_), id(i_) {}
    bool operator<(const Edge &y) const {
	return c < y.c;
    }
} E[1000111];

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    REP (i, M) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	a--; b--;
	E[i] = Edge(a, b, c, i);
    }

    sort(E, E+M);


    UnionFind U(2 * N);
    REP ($, Q) {
	int L, R;
	scanf("%d%d", &L, &R);
	L--;
	U.reset();
	int ans = -1;
	for (int i=M; i--;) {
	    if (L <= E[i].id && E[i].id < R) {
		if (U.same(E[i].a, E[i].b) || U.same(E[i].a, E[i].b)) {
		    ans = E[i].c;
		    break;
		} else {
		    U.link(E[i].a, E[i].b + N);
		    U.link(E[i].a + N, E[i].b);
		}
	    }
	}

	printf("%d\n", ans);
    }

    return 0;
}