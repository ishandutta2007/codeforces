#include<tuple>
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

template<class T> struct AddMinimum {
    int n;
    T *data, *lazy;
    AddMinimum() : n(0), data(NULL), lazy(NULL) {}
    AddMinimum(int n_) : n(n_), data(new T[n<<1]()), lazy(new T[n]()) {}
    template<class Iter> AddMinimum(Iter begin, Iter end) : n(end - begin), data(new T[n<<1]()), lazy(new T[n]()) {
	for (int i=0; i<n; i++, ++begin) data[i + n] = *begin;
	for (int i=n; --i; ) data[i] = min(data[i<<1], data[i<<1|1]);
    }
    AddMinimum(AddMinimum &&y) : n(0), data(NULL), lazy(NULL) { swap(*this, y); }
    ~AddMinimum() { clear(); }
    AddMinimum& operator=(AddMinimum &&y) { swap(*this, y); return *this; }

    friend void swap(AddMinimum &x, AddMinimum &y) {
	swap(x.n, y.n); swap(x.data, y.data); swap(x.lazy, y.lazy);
    }

    void clear() {
	if (data != NULL) {
	    n = 0;
	    delete[] data; data = NULL;
	    delete[] lazy; lazy = NULL;
	}
    }

    void fill(const T v) {
	std::fill(data, data + 2*n, v);
	std::fill(lazy, lazy + n, T());
    }

    T at(int i) const {
	T ret = data[i+=n];
	while (i>>=1) ret += lazy[i];
	return ret;
    }

    void modify(int i, const T v) {
	for (int t=__lg(i+=n)+1; --t>1; ) {
	    int k = i>>t;
	    lazy[k<<1] += lazy[k]; lazy[k<<1|1] += lazy[k];
	    data[k<<1] += lazy[k]; data[k<<1|1] += lazy[k];
	    lazy[k] = T();
	}
	data[i] += lazy[i>>1]; data[i^1] += lazy[i>>1];
	lazy[i>>1] = T();
	data[i] = v;
	store(i-n);
    }

    void add(int l, int r, const T v) {
	int l_ = l+n, r_ = r+n;
	if (l_ & 1) data[l_++] += v;
	if (r_ & 1) data[--r_] += v;
	while ((l_>>=1)<(r_>>=1)) {
	    if (l_ & 1) { data[l_] += v; lazy[l_] += v; l_++; }
	    if (r_ & 1) { --r_; data[r_] += v; lazy[r_] += v; }
	}
	store(l); if (l < r - 1) store(r - 1);
    }

    T minimum(int l, int r) const {
	int l0 = l+n, r0 = r+n-1;
	l += n; r += n;
	T ret_l = data[l0], ret_r = data[r0];
	while (l<r) {
	    if (l & 1) { if (data[l] < ret_l) ret_l = data[l0=l]; l++; }
	    if (r & 1) { --r; if (data[r] < ret_r) ret_r = data[r0=r]; }
	    l >>= 1; r >>= 1; l0 >>= 1; r0 >>= 1;
	    ret_l += lazy[l0]; ret_r += lazy[r0];
	}
	while (l0>>=1) ret_l += lazy[l0];
	while (r0>>=1) ret_r += lazy[r0];
	return min(ret_l, ret_r);
    }

    void store(int i) {
	for (i += n; i >>= 1; )
	    data[i] = min(data[i<<1], data[i<<1|1]) + lazy[i];
    }
};
const int MAXN = 500011;

int N, Q;
VI G[MAXN];
LL W[MAXN];

LL dist[MAXN];
int sz[MAXN];

void bfs() {
    REP (v, N) {
	EACH (e, G[v]) {
	    dist[*e] = dist[v] + W[*e];
	}
    }
    REP (i_, N) {
	int v = N-1-i_;
	sz[v] = 1;
	EACH (e, G[v]) {
	    sz[v] += sz[*e];
	}
    }
}

LL A[MAXN];
const LL INF = 1LL<<52;
AddMinimum<LL> D;
void build() {
    REP (v, N) {
	if (G[v].empty()) {
	    A[v] = dist[v];
	} else {
	    A[v] = INF;
	}
    }

    D = AddMinimum<LL>(A, A+N);
}

using ILR = tuple<int, int, int>;
vector<ILR> H[MAXN];
LL global;
LL ans[MAXN];

int iter[MAXN];
void dfs() {
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
	int v = st.top();
	if (iter[v] == 0) {
	    EACH (e, H[v]) {
		int i, l, r;
		tie(i, l, r) = *e;
		ans[i] = D.minimum(l, r) + global;
	    }
	}

	if (iter[v] == (int)G[v].size()) {
	    st.pop();
	    global -= W[v];
	    D.add(v, v+sz[v], +W[v]*2);
	} else {
	    int w = G[v][iter[v]++];
	    st.push(w);
	    global += W[w];
	    D.add(w, w+sz[w], -W[w]*2);
	}
    }
}

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N-1) {
	int p; LL w;
	scanf("%d%lld", &p, &w);
	p--;
	G[p].push_back(i+1);
	W[i+1] = w;
    }
    bfs();
    build();
    REP (i, Q) {
	int v, l, r;
	scanf("%d%d%d", &v, &l, &r);
	v--;
	l--;
	H[v].emplace_back(i, l, r);
    }

    dfs();

    REP (i, Q) printf("%lld\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}