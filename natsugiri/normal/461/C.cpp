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

int N, Q;
int A[100111];

int main() {
    scanf("%d%d", &N, &Q);
    int L = 0, R = N, sgn = 1;
    Fenwick<int> F(N);
    REP (i, N) F.add(i, 1);

    REP ($, Q) {
	char op[11];
	scanf("%s", op);
	if (*op == '1') {
	    int p;
	    scanf("%d", &p);
	    if (sgn == 1) {
		p += L;
		if (p - L <= R - p) {
		    for (int i=L; i<p; i++) {
			int tmp = F.sum(i, i+1);
			F.add(2*p-i-1, tmp);
			F.add(i, -tmp);
		    }
		    L = p;
		} else {
		    for (int i=p; i<R; i++) {
			int tmp = F.sum(i, i+1);
			F.add(2*p-i-1, tmp);
			F.add(i, -tmp);
		    }

		    R = p;
		    sgn = -1;
		}
	    } else {
		p = R - p;
		if (R - p <= p - L) {
		    for (int i=p; i<R; i++) {
			int tmp = F.sum(i, i+1);
			F.add(2*p-i-1, tmp);
			F.add(i, -tmp);
		    }
		    R = p;
		} else {
		    for (int i=L; i<p; i++) {
			int tmp = F.sum(i, i+1);
			F.add(2*p-i-1, tmp);
			F.add(i, -tmp);
		    }
		    L = p;
		    sgn = 1;
		}
	    }
	} else {
	    int l, r;
	    scanf("%d%d", &l, &r);
	    int ans = 0;
	    if (sgn == 1) {
		ans = F.sum(l+L, r+L);
	    } else {
		ans = F.sum(R-r, R-l);
	    }
	    printf("%d\n", ans);
	}

//	REP (i, N) eprintf("%d ", F.sum(i, i+1)); eprintf("\n");
    }

    return 0;
}