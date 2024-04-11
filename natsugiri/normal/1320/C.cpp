#include<tuple>
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
int N, M, P;

vector<pair<int, int> > atk, def;

using XYZ = tuple<int, int, int>;
vector<XYZ> xyz;

void MAIN() {
    scanf("%d%d%d", &N, &M, &P);

    atk.resize(N);
    REP (i, N) scanf("%d%d", &atk[i].first, &atk[i].second);

    def.resize(M);
    REP (i, M) scanf("%d%d", &def[i].first, &def[i].second);

    xyz.resize(P);
    REP (i, P) {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	xyz[i] = make_tuple(x, y, z);
    }

    sort(atk.begin(), atk.end());
    sort(def.begin(), def.end());
    sort(xyz.begin(), xyz.end());

    vector<LL> init;
    REP (i, def.size()) init.push_back(-def[i].second);
    AddMaximum<LL> X(init.begin(), init.end());

    LL ans = -(1LL<<60);
    int pos = 0;
    REP (i, atk.size()) {
	int a = atk[i].first;
	int ca = atk[i].second;

	while (pos < (int)xyz.size()) {
	    int x, y, z;
	    tie(x, y, z) = xyz[pos];
	    if (x < a) {
		int k = lower_bound(def.begin(), def.end(), make_pair(y+1, -1)) - def.begin();
		if (k < (int)init.size()) {
		    X.add(k, init.size(), z);
		}
		pos++;
	    } else {
		break;
	    }
	}

	LL tmp = X.maximum(0, init.size()) - ca;
	amax(ans, tmp);
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}