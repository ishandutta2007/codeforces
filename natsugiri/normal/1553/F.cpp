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

int N;
int A[200011];

const int MAGIC = 1024;

const int LIMIT = 300000;

LL memo[MAGIC];
LL freq[MAGIC];
LL sum_all;
LL cnt_all;
Fenwick<LL> F(600011);
Fenwick<LL> G(310011);

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

#ifdef LOCALx
    N = 20;
    REP (i, N) A[i] = rand() % 300000;
    A[N/2] = 300000;
#endif


    LL cur = 0;

    REP (i, N) {
	// x % A[i];
	if (A[i] < MAGIC) {
	    cur += memo[A[i]];
	} else {
	    cur += sum_all;
	    LL prv = 0;
	    for (int j=0; j<=LIMIT; j+=A[i]) {
		LL tmp = F.sum(j+A[i]);
		cur -= (tmp - prv) * j;
		prv = tmp;
	    }
	}

	for (int d=1; d<MAGIC; d++) {
	    memo[d] += A[i] % d;
	}
	F.add(A[i], 1);
	sum_all += A[i];


	// A[i] % x;
	for (int d=1; d<MAGIC; d++) if (freq[d]) {
	    cur += A[i] % d * freq[d];
	}
	cur += cnt_all * A[i] + G.sum(A[i]);


	if (A[i] < MAGIC) {
	    freq[A[i]]++;
	} else {
	    cnt_all++;
	    for (int j=A[i]; j<=LIMIT; j+=A[i]) {
		G.add(j-1, -A[i]);
	    }
	}

	printf("%lld%c", cur, " \n"[i==N-1]);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}