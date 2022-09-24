#include<tuple>
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
template<unsigned MOD> struct ModInt {
    static const unsigned static_MOD = MOD;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
    ModInt(const ModInt &y) { x = y.x; }
    ModInt(int y) { if (y<0 || (int)MOD<=y) y %= (int)MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % MOD; else x = y; }
    ModInt &operator+=(const ModInt y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt y) { if ((x -= y.x) & (1u<<31)) x += MOD; return *this; }
    ModInt &operator*=(const ModInt y) { x = (unsigned long long)x * y.x % MOD; return *this; }
    ModInt &operator/=(const ModInt y) { x = (unsigned long long)x * y.inv().x % MOD; return *this; }
    ModInt operator-() const { return (x ? MOD-x: 0); }

    ModInt inv() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }
    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;
template<class T> vector<int> compress(const vector<T> &v, vector<T> *unq=NULL) {
    int n = v.size();
    vector<pair<T, int> > t(n);
    for (int i=0; i<n; i++) t[i] = make_pair(v[i], i);
    sort(t.begin(), t.end());
    vector<int> r(n);
    int cur = 0;
    for (int i=0, k=0; i<n; i++) {
	if (t[k].first < t[i].first) k = i, cur++;
	r[t[i].second] = cur;
    }
    if (unq) {
	unq->resize(cur+1);
	cur = 0;
	for (int i=0; i<n; i++)
	    if (i == 0 || t[i-1].first < t[i].first)
		(*unq)[cur++] = t[i].first;
    }
    return r;
}
struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};

int N, M, K;
LL C[500011];

struct Edge {
    LL hash;
    int x, y;
    bool operator<(const Edge &e) const {
	return hash < e.hash;
    }
};
Edge E[500011];
Mint pow2[500011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%lld", C+i);

    pow2[0] = 1;
    REP (i, N) pow2[i+1] = pow2[i] + pow2[i];

    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	E[i].hash = C[x] ^ C[y];
	E[i].x = x;
	E[i].y = y;
    }

    sort(E, E+M);

    VI vs, unq;
    int cnt = 0;
    Mint ans = 0;
    for (int i=0; i<M; ) {
	int j = i+1;
	while (j < M && E[i].hash == E[j].hash) {
	    j++;
	}

	vs.clear();
	for (int k=i; k<j; k++) {
	    vs.push_back(E[k].x);
	    vs.push_back(E[k].y);
	}
	unq.clear();
	VI vc = compress(vs, &unq);

	UnionFind U(unq.size());
	for (int k=0; k<(int)vc.size(); k+=2) {
	    U.link(vc[k], vc[k+1]);
	}
	int rest = N - unq.size();
	ans += pow2[U.count() + rest];

	i = j;
	cnt++;
    }

    ans += pow2[N] * ((1LL<<K) - cnt);
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}