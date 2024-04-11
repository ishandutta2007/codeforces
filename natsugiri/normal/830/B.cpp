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

int N;
VI G[100111];
LL ans = 0;
Fenwick<int> F;

void add(int pos, int nxt) {
    if (pos <= nxt) {
	ans += F.sum(pos, nxt+1);
    } else {
	ans += F.sum(pos, N);
	ans += F.sum(0, nxt+1);
    }

    F.add(nxt, -1);
}

void MAIN() {
    scanf("%d", &N);
    int stop = 0;
    REP (i, N) {
	int a;
	scanf("%d", &a);
	G[a].push_back(i);
	amax(stop, a);
    }

    F = Fenwick<int>(N);
    REP (i, N) F.add(i, 1);

    int value = 0;
    int pos = 0;
    while (1) {
	while (value <= stop && G[value].empty()) value++;
	if (value > stop) break;

	int k = 0;
	REP (i, G[value].size()) if (pos <= G[value][i]) {
	    k = i;
	    break;
	}

	for (int i=k; i<(int)G[value].size(); i++) {
	    int nxt = G[value][i];
	    add(pos, nxt);
	    pos = (nxt + 1) % N;
	}
	for (int i=0; i<k; i++) {
	    int nxt = G[value][i];
	    add(pos, nxt);
	    pos = (nxt + 1) % N;
	}

	G[value].clear();
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}