#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

const int MAXN = 500011;
int N;
int A[MAXN];
int P[MAXN];
int M;
int B[MAXN];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", P+i);
    scanf("%d", &M);
    REP (i, M) scanf("%d", B+i+1);
    M++;
    B[0] = 0;

    Fenwick<LL> X(M+11);
    X.add(1, 1LL<<60);

    int pos = 1;

    REP (i, N) {
	if (pos < M && A[i] == B[pos]) pos++;
	int k = lower_bound(B, B+M, A[i]) - B;
	LL val = X.sum(k);

	X.add(0, P[i]);
	if (P[i] > 0) X.add(k, -P[i]);

	if (k < M && B[k] == A[i]) {
	    LL tmp = X.sum(k+1);
	    if (val < tmp) {
		X.add(k, val - tmp);
		X.add(k+1, tmp - val);
	    }
	}
    }

    if (pos != M) {
	puts("NO");
    } else {
	LL ans = X.sum(M);
	puts("YES");
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}