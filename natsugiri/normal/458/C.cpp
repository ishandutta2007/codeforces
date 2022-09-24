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

const int SIZE = 100011;
int N;
VI G[SIZE];
int iter[SIZE];

struct Data {
    int a, b;
    bool operator<(const Data &y) const {
	return b < y.b;
    }
} D[SIZE];

int main() {
    scanf("%d", &N);
    REP (i, N) {
	int a, b;
	scanf("%d%d", &a, &b);
	D[i].a = a;
	D[i].b = b;
    }
    sort(D, D+N);
    REP (i, N) G[D[i].a].push_back(i);

    int my_cnt = N;
    LL my_cst = 0;
    REP (i, N) if (D[i].a) my_cst += D[i].b;
    LL ans = my_cst;

    VI has; has.reserve(SIZE);
    for (int i=1; i<SIZE; i++) {
	iter[i] = G[i].size();
	has.push_back(i);
    }

    Fenwick<int> F1(N);
    Fenwick<LL> FX(N);

    int rival = 0;
    while (!has.empty()) {
	rival++;
	VI nxt;
	EACH (e, has) {
	    if (iter[*e] > 0) {
		iter[*e]--;
		int pos = G[*e][iter[*e]];
		my_cnt--;
		my_cst -= D[pos].b;
		F1.add(pos, 1);
		FX.add(pos, D[pos].b);
		nxt.push_back(*e);
	    }
	}

	int need = max(0, rival - my_cnt + 1);
	LL tmp = my_cst;
	if (need > 0) {
	    int k = F1.lower_bound(need);
	    tmp += FX.sum(k + 1);
	}

	amin(ans, tmp);
	swap(has, nxt);
    }

    printf("%lld\n", ans);
    return 0;
}