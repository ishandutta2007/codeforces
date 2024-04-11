#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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
    int lower_bound(const T &x) { // sum(ret) < x <= sum(ret+1);
	if (n == 0) return 0;
	int i = 0; T s = T();
	for (int k=1<<__lg(n); k; k>>=1) {
	    if (i+k <= n && s + d[i+k-1] < x) {
		i += k; s += d[i-1];
	    }
	}
	return i;
    }
    int upper_bound(const T &x) { // sum(ret) <= x < sum(ret+1);
	if (n == 0) return 0;
	int i = 0; T s = T();
	for (int k=1<<__lg(n); k; k>>=1) {
	    if (i+k <= n && !(x < s + d[i+k-1])) {
		i += k; s += d[i-1];
	    }
	}
	return i;
    }
};

void UNIQUE(VI &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
int N;
int TP[200011];
int D[200011];

VI B;

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d", TP+i, D+i);

    REP (i, N) {
	if (D[i] > 0) {
	    B.push_back(D[i]);
	}
    }

    UNIQUE(B);
    Fenwick<LL> F(B.size()), C(B.size());

    set<int> Fset, Lset;

    REP (i, N) {
	if (TP[i] == 0) {
	    if (D[i] > 0) Fset.insert(D[i]);
	    else Fset.erase(-D[i]);
	} else {
	    if (D[i] > 0) Lset.insert(D[i]);
	    else Lset.erase(-D[i]);
	}

	int index = lower_bound(B.begin(), B.end(), abs(D[i])) - B.begin();

	if (D[i] > 0) {
	    F.add(index, D[i]);
	    C.add(index, 1);
	} else {
	    F.add(index, D[i]);
	    C.add(index, -1);
	}

	LL ans = 0;

	if (Lset.empty()) {
	    ans = F.sum(B.size());
	} else if (Fset.empty()) {
	    ans = F.sum(B.size()) * 2 - *Lset.begin();
	} else {
	    int hi = *Fset.rbegin();
	    int index_hi = lower_bound(B.begin(), B.end(), hi) - B.begin();
	    int lo = *Lset.begin();
	    int index_lo = lower_bound(B.begin(), B.end(), lo) - B.begin();
	    F.add(index_hi, -hi);
	    C.add(index_hi, -1);
	    F.add(index_lo, -lo);
	    C.add(index_lo, -1);

	    int all = C.sum(B.size());
	    int dd = Lset.size() - 1u;
	    int pos = C.upper_bound(all - dd);

	    ans = F.sum(pos) + F.sum(pos, B.size()) * 2 + hi * 2 + lo;

	    F.add(index_hi, hi);
	    C.add(index_hi, 1);
	    F.add(index_lo, lo);
	    C.add(index_lo, 1);
	}

	//eprintf("%lld %lld\n", C.sum(B.size()), F.sum(B.size()));
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}