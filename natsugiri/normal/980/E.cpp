#include<queue>
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

template<class T> struct Fenwick {
    int n;
    T* d;
    Fenwick() : n(0), d(NULL) {}
    Fenwick(int n_) : n(n_) {
	d = new T[n_]();
    }
    Fenwick(const Fenwick &y) : n(y.n) {
	d = new T[n];
	memcpy(d, y.d, sizeof (T) * n);
    }
    ~Fenwick() {
	delete[] d; d = NULL;
	n = 0;
    }
    friend void swap(Fenwick &x, Fenwick &y) {
	swap(x.n, y.n); swap(x.d, y.d);
    }
    Fenwick& operator=(Fenwick y) {
	swap(*this, y);
	return *this;
    }
    inline void add(int i, const T &x) {
	for (; i<n; i|=i+1) d[i] += x;
    }
    inline T sum(int r) {
	T s = T();
	for (; r; r&=r-1) s += d[r-1];
	return s;
    }
    T sum(int l, int r) {
	return sum(r) - sum(l);
    }
};

const int MAXN = 1000011;
int N, K;
VI G[MAXN];
VI ord, st;
int sz[MAXN];
int par[MAXN];
int iter[MAXN];
int depth[MAXN];

int pos[1000111];
bool use[MAXN];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    par[N-1] = N-1;
    ord.reserve(N);
    st.reserve(N);
    st.push_back(N-1);
    while (!st.empty()) {
	int v = st.back();

	if (iter[v] == 0) {
	    pos[v] = ord.size();
	    ord.push_back(v);
	}
	if (iter[v] == (int)G[v].size()) {
	    st.pop_back();
	    continue;
	}

	int w = G[v][iter[v]++];
	if (w == par[v]) continue;
	par[w] = v;
	st.push_back(w);
    }

    for (int i=1; i<N; i++) {
	int v = ord[i];
	depth[v] = depth[par[v]] + 1;

	v = ord[N-i];
	sz[v]++;
	sz[par[v]] += sz[v];
    }
    sz[N-1] = N;

//    rprintf("%d", ord.begin(), ord.end());
//    rprintf("%d", sz, sz+N);

    int pre = 0;
    Fenwick<int> F(N+11);
    REP (i, N) {
	int v = ord[i];
	F.add(i, depth[v] - pre);
	pre = depth[v];
    }

    int rest = N-K;
    for (int v=N; v-- && rest;) {
	if (use[v]) continue;

	int len = F.sum(pos[v]+1);
//	eprintf("%d %d, %d\n", v+1, len, rest);
//	REP (j, N+1) eprintf("%d ", F.sum(j));
//	eprintf("\n");

	if (len+1 <= rest) {
	    int cur = v;
	    while (!use[cur]) {
		use[cur] = true;
		F.add(pos[cur], -1);
		F.add(pos[cur]+sz[cur], +1);
		cur = par[cur];
		rest--;
	    }
	}
    }

    
    VI ans; ans.reserve(K);
    REP (i, N) if (!use[i]) ans.push_back(i+1);
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}