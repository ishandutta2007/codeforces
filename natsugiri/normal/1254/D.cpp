#include<stack>
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

int N;
VI G[150011];
VI skip[150011];
int parent[150011];
int iter[150011];
int in[150011];
int sz[150011];
VI ord;

struct CMP {
    bool operator()(int i, int j) const {
	return sz[i] < sz[j];
    }
} cmp;

void build() {
    ord.reserve(N);
    ord.push_back(0);
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) if (*e != parent[v]) {
	    ord.push_back(*e);
	    parent[*e] = v;
	    G[*e].erase(remove(G[*e].begin(), G[*e].end(), v), G[*e].end());
	}
    }
    REP (i, N) {
	int v = ord[N-1-i];
	sz[v] = 1;
	EACH (e, G[v]) sz[v] += sz[*e];
    }
    REP (i, N) {
	sort(G[i].begin(), G[i].end(), cmp);
    }

    ord.clear();
    stack<int> st;
    st.push(0);
    in[0] = 0;
    ord.push_back(0);
    parent[0] = 0;
    while (!st.empty()) {
	int v = st.top();
	if (iter[v] == (int)G[v].size()) {
	    st.pop();
	    continue;
	}

	int w = G[v][iter[v]];

	iter[v]++;
//	if (w == parent[v]) continue;
//	parent[w] = v;
	in[w] = ord.size();
	ord.push_back(w);
	st.push(w);
    }

    REP (i, N) {
	skip[i].resize(G[i].size());
	int prv = -1;
	for (int j=G[i].size(); j--;) {
	    if (prv == sz[G[i][j]]) {
		skip[i][j] = skip[i][j+1] + 1;
	    } else {
		prv = sz[G[i][j]];
		skip[i][j] = 1;
	    }
	}
    }

#ifdef MYTEST
//    rprintf("%d", ord.begin(), ord.end());
#endif
}
template<unsigned MOD_> struct ModInt {
    static const unsigned MOD = MOD_;
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

    ModInt inv() const { return pow(MOD-2); }
    ModInt pow(long long y) const {
	ModInt b = *this, r = 1;
	if (y < 0) { b = b.inv(); y = -y; }
	for (; y; y>>=1) {
	    if (y&1) r *= b;
	    b *= b;
	}
	return r;
    }

    ModInt extgcd() const {
	unsigned a = MOD, b = x; int u = 0, v = 1;
	while (b) {
	    int t = a / b;
	    a -= t * b; swap(a, b);
	    u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return ModInt(u);
    }

    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

//const LL MOD = 1000000007;
const LL MOD = 998244353;
typedef ModInt<MOD> Mint;


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

Fenwick<Mint> F;
void ADD(int x, int y, Mint v) {
    F.add(y, -v);
    F.add(x, v);
}

void MAIN() {
    int Q;
    scanf("%d%d", &N, &Q);

    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    Mint DE = Mint(1) / Mint(N);
    build();
    const int SIZE = 1<<18;
    F = Fenwick<Mint>(SIZE);

    REP ($, Q) {
	char op[11];
	scanf("%s", op);
	if (*op == '1') {
	    int v;
	    LL d;
	    scanf("%d%lld", &v, &d);
	    v--;

	    if (v == 0) {
		ADD(0, SIZE, d);
	    } else {
		ADD(0, SIZE, sz[v] * DE * d);
		ADD(in[v], in[v] + sz[v], (-sz[v] * DE + 1) * d);
	    }
	    if (G[v].size()) {
		int pos = in[v] + 1;
		Mint prv = 0;
		for (int i=0; i<(int)G[v].size();) {
		    int w = G[v][i];
		    Mint tmp = sz[w] * DE * d;
		    F.add(pos, prv - tmp);
		    prv = tmp;
		    pos += skip[v][i] * sz[w];
		    i += skip[v][i];
		}
		F.add(pos, prv);
	    }
	} else {
	    int v;
	    scanf("%d", &v);
	    v--;
	    Mint ans = F.sum(in[v]+1);
	    printf("%d\n", ans.geti());
	}
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}