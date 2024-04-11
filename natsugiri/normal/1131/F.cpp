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

int N;

int head[300011];
pair<int, int> E[300011];
int iter[300011];

VI ans;
void dfs(int idx) {
    stack<int> st;
    st.push(idx);
    while (!st.empty()) {
	idx = st.top();
	if (E[idx].first == -1) {
	    ans.push_back(idx+1);
	    st.pop();
	} else if (iter[idx] == 2) {
	    st.pop();
	} else if (iter[idx] == 1) {
	    st.push(E[idx].second);
	    iter[idx]++;
	} else {
	    st.push(E[idx].first);
	    iter[idx]++;
	}
    }
//    if (E[idx].first == -1) {
//	ans.push_back(idx+1);
//    } else {
//	dfs(E[idx].first);
//	dfs(E[idx].second);
//    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	E[i] = make_pair(-1, -1);
	head[i] = i;
    }

    UnionFind U(N);
    int cnt = N;
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	x = U.root(x);
	y = U.root(y);

	E[cnt] = make_pair(head[x], head[y]);
	U.link(x, y);
	int z = U.root(x);
	head[z] = cnt;
	cnt++;
    }

    dfs(cnt-1);
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}