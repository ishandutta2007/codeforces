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

const int LOG = 22;
const int ALL = (1<<LOG)-1;
int M;
int A[1<<22];
bool C[1<<22];
bool D[1<<22];
bool checked[1<<22];

stack<int> st;

void MAIN() {
    scanf("%*d%d", &M);
    REP (i, M) {
	int x;
	scanf("%d", &x);
	A[i] = x;
	C[x] = true;
	D[x] = true;
    }

    REP (i, 1<<LOG) if (D[i]) {
	REP (t, LOG) D[i|(1<<t)] = true;
    }

    UnionFind U(1<<LOG);

    REP (i, M) {
	int mask = A[i] ^ ALL;
	if (D[mask]) {
	    U.link(A[i], mask);
	    if (!checked[mask]) {
		st.push(mask);
		checked[mask] = true;
	    }
	}

	while (!st.empty()) {
	    int x = st.top();
	    st.pop();

	    REP (t, LOG) if (x>>t&1) {
		int nxt = x ^ (1<<t);
		if (D[nxt]) {
		    U.link(A[i], nxt);
		    if (!checked[nxt]) {
			st.push(nxt);
			checked[nxt] = true;
		    }
		}
	    }
	}
    }

    VI ans;
    REP (i, M) ans.push_back(U.root(A[i]));
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    printf("%d\n", (int)ans.size());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}