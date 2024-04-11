#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

const int INF = 1<<29;
struct Seg {
    int val, idx;
    Seg(): val(0), idx(-1) { }
    Seg(int val_): val(val_) { }

    Seg& operator+=(const Seg &o) {
	val += o.val;
	return *this;
    }
    friend Seg operator+(Seg x, const Seg &y) {
	return x += y;
    }

    bool operator<(const Seg &o) const {
	return val < o.val;
    }
};

template<class T> struct AddMaximum {
    int n;
    T *data, *lazy;
    AddMaximum() : n(0), data(NULL), lazy(NULL) {}
    AddMaximum(int n_) : n(n_), data(new T[n<<1]()), lazy(new T[n]()) {}
    template<class Iter> AddMaximum(Iter begin, Iter end) : n(end - begin), data(new T[n<<1]()), lazy(new T[n]()) {
	for (int i=0; i<n; i++, ++begin) data[i + n] = *begin;
	for (int i=n; --i; ) data[i] = max(data[i<<1], data[i<<1|1]);
    }
    AddMaximum(AddMaximum &&y) : n(0), data(NULL), lazy(NULL) { swap(*this, y); }
    ~AddMaximum() { clear(); }
    AddMaximum& operator=(AddMaximum &&y) { swap(*this, y); return *this; }

    friend void swap(AddMaximum &x, AddMaximum &y) {
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
	if (l >= r) return;
	int l_ = l+n, r_ = r+n;
	if (l_ & 1) data[l_++] += v;
	if (r_ & 1) data[--r_] += v;
	while ((l_>>=1)<(r_>>=1)) {
	    if (l_ & 1) { data[l_] += v; lazy[l_] += v; l_++; }
	    if (r_ & 1) { --r_; data[r_] += v; lazy[r_] += v; }
	}
	store(l); if (l < r - 1) store(r - 1);
    }

    T maximum(int l, int r) const {
	int l0 = l+n, r0 = r+n-1;
	l += n; r += n;
	T ret_l = data[l0], ret_r = data[r0];
	while (l<r) {
	    if (l & 1) { if (ret_l < data[l]) ret_l = data[l0=l]; l++; }
	    if (r & 1) { --r; if (ret_r < data[r]) ret_r = data[r0=r]; }
	    l >>= 1; r >>= 1; l0 >>= 1; r0 >>= 1;
	    ret_l += lazy[l0]; ret_r += lazy[r0];
	}
	while (l0>>=1) ret_l += lazy[l0];
	while (r0>>=1) ret_r += lazy[r0];
	return max(ret_l, ret_r);
    }

    void store(int i) {
	for (i += n; i >>= 1; )
	    data[i] = max(data[i<<1], data[i<<1|1]) + lazy[i];
    }
};
int N;
int K;
VI G[200011];

int par[200011];
int in[200011];
int out[200011];
int depth[200011];
bool use[200011];

VI ord;
void dfs(int v) {
    in[v] = ord.size();

    if (G[v].empty()) {
	ord.push_back(v);
    } else {
	EACH (e, G[v]) {
	    depth[*e] = depth[v] + 1;
	    dfs(*e);
	}
    }

    out[v] = ord.size();
}


VI dp[200011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    VI que;
    que.reserve(N);
    que.push_back(0);
    REP (i, N) {
	int v = que[i];
	EACH (e, G[v]) {
	    par[*e] = v;
	    G[*e].erase(find(G[*e].begin(), G[*e].end(), v));
	    que.push_back(*e);
	}
    }

    dfs(0);

    LL ans = 0;

    if ((int)ord.size() <= K) {
	for (LL i=(int)ord.size(); i<=K; i++) {
	    amax(ans, i * (N-i));
	}
    } else {
	AddMaximum<Seg> tree(ord.size());
	REP (i, ord.size()) {
	    Seg s;
	    s.val = depth[ord[i]];
	    s.idx = ord[i];
	    tree.modify(i, s);
	}

	LL B = N;
	LL W = 0;
	REP (k, K) {
	    Seg s = tree.maximum(0, ord.size());
	    int x = s.idx;

	    W += s.val;
	    B -= s.val;
	    B--;

	    while (!use[x]) {
		use[x] = true;

		Seg lazy;
		lazy.val = -1;
		tree.add(in[x], out[x], lazy);

		if (x == 0) break;
		x = par[x];
	    }
	}

	ans = 1LL<<60;
	for (LL b=0; b<=B; b++) {
	    amin(ans, (N-K-b)*(K-b));
	}
    }
    printf("%lld\n", ans);
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}