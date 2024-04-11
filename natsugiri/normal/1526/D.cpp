#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

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

char ANOT[5] = "ANOT";
int rnk[26];
int cnt[26];
string S;
LL eval() {
    REP (i, 4) {
	rnk[ANOT[i]-'A'] = i;
    }

    memset(cnt, 0, sizeof cnt);
    LL ret = 0;
    REP (i, S.size()) {
	int r = rnk[S[i]-'A'];
	for (int k=r+1; k<4; k++) ret += cnt[k];
	cnt[r]++;
    }
    return ret;
}

char buf[1000011];

LL best_cost;
string best_s;
int C[26];


void MAIN() {
    scanf("%s", buf);
    S = buf;

    memset(C, 0, sizeof C);
    REP (i, S.size()) C[S[i]-'A']++;

    best_cost = -1;

    do {
	LL ret = eval();
	if (best_cost < ret) {
	    best_cost = ret;

	    best_s.clear();
	    REP (i, 4) {
		REP (j, C[ANOT[i]-'A']) best_s.push_back(ANOT[i]);
	    }
	}

    } while (next_permutation(ANOT, ANOT+4));

    printf("%s\n", best_s.c_str());
    eprintf("%lld\n", best_cost);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}