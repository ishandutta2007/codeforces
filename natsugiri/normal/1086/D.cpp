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

    int first() {
	return lower_bound(1);
    }
    int last() {
	T s = sum(n);
	return lower_bound(s);
    }
};

const int SIZE = 200012;
Fenwick<int> F[3];
char X[SIZE];

int query(int R, int P, int S) {
    if (F[P].sum(SIZE) == 0) {
	return F[R].sum(SIZE);
    } else if (F[S].sum(SIZE) == 0) {
	return 0;
    } else {
	int ret = 0;
	int p = F[P].first();
	int s = F[S].first();
	if (p < s) ret += F[R].sum(p, s);
	p = F[P].last();
	s = F[S].last();
	if (s < p) ret += F[R].sum(s, p);
	return F[R].sum(SIZE) - ret;
    }
}

const int ROCK = 0;
const int PAPER = 1;
const int SCISSORS = 2;
void add(int idx, int v, char c) {
    if (c == 'R') F[ROCK].add(idx, v);
    if (c == 'P') F[PAPER].add(idx, v);
    if (c == 'S') F[SCISSORS].add(idx, v);
}

int query() {
    return query(ROCK, PAPER, SCISSORS) + 
	query(PAPER, SCISSORS, ROCK) +
	query(SCISSORS, ROCK, PAPER);
}

int N, Q;

void MAIN() {
    scanf("%d%d", &N, &Q);
    scanf("%s", X);

    REP (i, 3) F[i] = Fenwick<int>(SIZE);

    REP (i, N) add(i+1, 1, X[i]);
    printf("%d\n", query());

    REP ($, Q) {
	int idx;
	char op[11];
	scanf("%d%s", &idx, op);
	if (X[idx-1] != op[0]) {
	    add(idx, -1, X[idx-1]);
	    add(idx, 1, op[0]);
	    X[idx-1] = op[0];
	}
	printf("%d\n", query());
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}