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
int N, M;
int A[200011];

pair<int, int> P[200011];
int ans[200011];

struct Query {
    int k, pos, i;
    bool operator<(const Query &o) const {
	return k < o.k;
    }
} query[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) P[i] = make_pair(-A[i], i);
    sort(P, P+N);

    scanf("%d", &M);
    REP (i, M) {
	int k, pos;
	scanf("%d%d", &k, &pos);
	query[i] = (Query){k, pos, i};
    }
    sort(query, query+M);

    Fenwick<int> F(N);
    for (int i=0, j=0, cnt=0; i<N; i++) {
	F.add(P[i].second, 1);
	cnt++;
	while (j < M && query[j].k == cnt) {
	    ans[query[j].i] = A[F.lower_bound(query[j].pos)];
	    j++;
	}
    }
    REP (i, M) printf("%d\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}