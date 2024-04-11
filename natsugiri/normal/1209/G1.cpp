#include<stack>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

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

const int MAX = 200011;

int N, Q;
int A[MAX];
int L[MAX], R[MAX];

int C[MAX], M[MAX];

void slow() {
    REP (i, MAX) {
	L[i] = MAX;
	R[i] = -1;
    }
    memset(C, 0, sizeof C);
    memset(M, 0, sizeof M);

    REP (i, N) {
	amin(L[A[i]], i);
	amax(R[A[i]], i);

	C[A[i]]++;
	M[A[i]]++;
    }

    UnionFind U(MAX);
    stack<int> st;
    REP (i, N) {
	int a = A[i];
	if (L[a] == i) {
	    if (!st.empty()) {
		int k = st.top();
		int x = U.root(A[i]);
		int y = U.root(A[k]);
		if (x != y) {
		    U.link(x, y);
		    int r = U.root(x);
		    C[r] = C[x] + C[y];
		    M[r] = max(M[x], M[y]);
		}
	    }
	    st.push(i);
	}

	if (R[A[i]] == i) {
	    st.pop();
	}
    }

    int ans = 0;
    REP (i, MAX) if (U.root(i) == i) {
	ans += C[i] - M[i];
    }
    printf("%d\n", ans);
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);

    slow();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}