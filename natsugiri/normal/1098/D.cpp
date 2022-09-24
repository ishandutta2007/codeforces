#include<set>
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
    AddMinimum(int n_) : n(n_), data(new T[n<<1]()), lazy(new T[n<<1]()) {}
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
//	if (data != NULL) {
//	    n = 0;
//	    delete[] data; data = NULL;
//	    delete[] lazy; lazy = NULL;
//	}
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

    int count(int l, int r, int k) {
	if (r - l == 1) {
	    return (int)(data[k] < 0);
	} else if (data[k] >= 0) {
	    return 0;
	} else {
	    data[k*2] += lazy[k];
	    data[k*2+1] += lazy[k];
	    lazy[k*2] += lazy[k];
	    lazy[k*2+1] += lazy[k];
	    lazy[k] = 0;
	    return count(l, (l+r)/2, k*2) + count((l+r)/2, r, k*2+1);
	}
    }

};

const LL INF = 1LL<<60;

const int MAXQ = 500111;
int Q;
char op[MAXQ];
int X[MAXQ];
int buddy[MAXQ];
int idx[MAXQ];



void MAIN() {
    scanf("%d", &Q);
    REP (i, Q) {
	scanf("%s%d", op+i, X+i);
    }

    set<pair<int, int> > se;
    vector<pair<int, int> > P;
    REP (i, Q) buddy[i] = Q;
    REP (i, Q) {
	if (op[i] == '+') {
	    se.emplace(X[i], -i);
	} else {
	    const int inf = 1<<29;
	    auto it = se.lower_bound(make_pair(X[i], -inf));
	    buddy[i] = -it->second;
	    buddy[-it->second] = i;
	    se.erase(it);
	}
    }
    REP (i, Q) {
	if (op[i] == '+') {
	    P.emplace_back(X[i], i);
	}
    }

    sort(P.begin(), P.end());
    REP (i, P.size()) {
	idx[P[i].second] = idx[buddy[P[i].second]] = i;
    }

    int sz = P.size();
    int m = 1;
    while (m < sz) m *= 2;
    AddMinimum<LL> M(m);
    M.add(0, m, INF);
    int in = 0;
    REP (i, Q) {
//	eprintf("%c %d\n", op[i], X[i]);
	if (op[i] == '+') {
	    M.add(idx[i]+1, m, X[i]*2);
	    M.add(idx[i], idx[i]+1, -INF-X[i]);
	    in++;
	} else {
	    M.add(idx[i]+1, m, -X[i]*2);
	    M.add(idx[i], idx[i]+1, INF+X[i]);
	    in--;
	}

	int ans = in - M.count(0, m, 1);
//	REP (j, m) if (M.minimum(j, j+1) < 0) ans--;
//	REP (j, m) eprintf("%lld ", M.minimum(j, j+1));
//	eprintf("\n");
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}