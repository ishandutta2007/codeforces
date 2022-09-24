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
    inline T sum(int r) const {
	T s = T();
	for (; r; r&=r-1) s += d[r-1];
	return s;
    }
    T sum(int l, int r) const {
	return sum(r) - sum(l);
    }
};

int N, M;
int A[100011];
int B[100011];
int sh[100011];

struct Data {
    int a;
    int i, j;
} D[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    int NM = N*M;
    REP (i, NM) scanf("%d", A+i);
    REP (i, NM) {
	B[i] = A[i];
    }

    sort(B, B+NM);

    REP (i, NM) {
	sh[i] = 0;
	D[i].a = B[i];
    }

    REP (i, N) REP (j, M) {
	D[i*M+j].i = i;
	D[i*M+j].j = j;
    }

    sort(D, D+NM, [&](const Data &x, const Data &y) {
	    if (x.a != y.a) return x.a < y.a;
	    if (x.i != y.i) return x.i < y.i;
	    return x.j > y.j;
	    });

    LL ans = 0;
    Fenwick<int> F(NM);

    REP (p, NM) {
	int k = lower_bound(B, B+NM, A[p]) - B;
	int i = D[k+sh[k]].i;
	int j = D[k+sh[k]].j;

	ans += F.sum(i*M, i*M+j);
	F.add(i*M+j, 1);
	sh[k]++;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}