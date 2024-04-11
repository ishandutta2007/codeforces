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
    ~AddMinimum() { clear(); }

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


int N, M;
int A[200111];
char buf[100111];
const LL INF = 1LL<<60;

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    AddMinimum<LL> X(A, A+N);

    scanf("%d ", &M);
    REP ($, M) {
	scanf("%[^\n] ", buf);
	int l, r, v;
	int c = count(buf, buf + strlen(buf), ' ');
	if (c >= 2) {
	    sscanf(buf, "%d%d%d", &l, &r, &v);
	    if (l <= r) {
		X.add(l, r+1, v);
	    } else {
		X.add(l, N, v);
		X.add(0, r+1, v);
	    }
	} else {
	    sscanf(buf, "%d%d", &l, &r);
	    LL ans;
	    if (l <= r) {
		ans = X.minimum(l, r+1);
	    } else {
		ans = min(X.minimum(l, N), X.minimum(0, r+1));
	    }
	    printf("%I64d\n", ans);
	}
    }


    return 0;
}