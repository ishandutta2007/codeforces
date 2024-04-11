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

int N, X;
int A[1000111];
int fL[1000111];
int fR[1000111];
int L[1000111];
int R[1000111];
bool sortL[1000111];
bool sortR[1000111];

void MAIN() {
    scanf("%d%d", &N, &X);
    REP (i, N) scanf("%d", A+i);

    REP (a, X+2) {
	fL[a] = N;
	fR[a] = -1;
    }
    REP (i, N) {
	amin(fL[A[i]], i);
	amax(fR[A[i]], i);
    }

    int last = 0;
    sortL[0] = true;
    R[0] = 0;
    for (int a=1; a<=X; a++) {
	if (fR[a] == -1 || last <= fL[a]) {
	    sortL[a] = true;
	    amax(last, fR[a]);
	    R[a] = last;
	} else {
	    break;
	}
    }

    last = N;
    sortR[X+1] = true;
    L[X+1] = N;
    for (int a=X; a>=1; a--) {
	if (fR[a] == -1 || fR[a] <= last) {
	    sortR[a] = true;
	    amin(last, fL[a]);
	    L[a] = last;
	} else {
	    break;
	}
    }
//    rprintf("%d", sortL, sortL+X+2);
//    rprintf("%d", sortR, sortR+X+2);

    Fenwick<int> F(N+10);
    LL ans = 0;
    for (int r=1; r<=X; r++) {
	if (sortL[r-1]) {
	    F.add(R[r-1], 1);
	}
	if (sortR[r+1]) {
	    ans += F.sum(L[r+1]+1);
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