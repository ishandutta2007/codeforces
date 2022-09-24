#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
template<unsigned MOD_> struct ModInt {
    static constexpr unsigned MOD = MOD_;
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int geti() const { return (int)x; }
    ModInt() { x = 0; }
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

    friend ModInt operator+(ModInt x, const ModInt y) { return x += y; }
    friend ModInt operator-(ModInt x, const ModInt y) { return x -= y; }
    friend ModInt operator*(ModInt x, const ModInt y) { return x *= y; }
    friend ModInt operator/(ModInt x, const ModInt y) { return x *= y.inv(); }
    friend bool operator<(const ModInt x, const ModInt y) { return x.x < y.x; }
    friend bool operator==(const ModInt x, const ModInt y) { return x.x == y.x; }
    friend bool operator!=(const ModInt x, const ModInt y) { return x.x != y.x; }
};

constexpr LL MOD = 998244353;
using Mint = ModInt<MOD>;
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

char S[11];
void test() {
    int N = 10;
    VI C, P;
    int cnt = 0;
    REP (s, 1<<N) {
	REP (i, N) S[i] = "CP"[s>>i&1];

	C.clear();
	P.clear();
	REP (i, N) {
	    if (S[i] == 'C') C.push_back(i);
	    else P.push_back(i);
	}

	bool ok = true;
	REP (i, (int)C.size()-2) {
	    if (C[i+1]-C[i] > C[i+2]-C[i+1]) ok = false;
	}
	REP (i, (int)P.size()-2) {
	    if (P[i+1]-P[i] < P[i+2]-P[i+1]) ok = false;
	}
	if (ok) {
	    REP (i, N) {
		if (S[i] == 'C' && S[i+1] == 'P') {
		    printf("[CP]");
		    i += 1;
		} else {
		    putchar(S[i]);
		}
	    }
	    puts("");
	    cnt++;
	}
    }
    printf("cnt %d\n", cnt);
}

int N;
int A[200011];

LL sums[200011];
Mint ans;

vector<pair<char, LL> > D;
vector<LL> Xs;
LL global;
void init() {
    global = 0;
    D.clear();
    Xs.clear();
}
void add(LL x) {
    D.emplace_back('A', x);
    Xs.push_back(x-global);
}
void add_global(LL x) {
    global += x;
    D.emplace_back('G', x);
}
void find(LL x) {
    D.emplace_back('F', x);
}
void run() {
    sort_unique(Xs);
    Fenwick<int> F(Xs.size());
    global = 0;
    Mint tmp = 0;
    EACH (e, D) {
	LL x = e->second;
	if (e->first == 'A') {
	    // eprintf("ADD %lld\n", x);
	    int k = lower_bound(Xs.begin(), Xs.end(), x - global) - Xs.begin();
	    assert(k < (int)Xs.size());
	    assert(Xs[k] == x-global);
	    F.add(k, 1);
	} else if (e->first == 'G') {
	    // eprintf("GLO %lld\n", x);
	    global += x;
	} else if (e->first == 'F') {
	    int k = upper_bound(Xs.begin(), Xs.end(), - x - global) - Xs.begin();
	    Mint t = F.sum(k, Xs.size());
	    tmp += t;
	    // eprintf("FND %lld = %d\n", x, t.geti());
	}
    }

    ans += tmp;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) sums[i+1] = sums[i] + A[i];
    ans = 0;

    {
	init();
	add(0);
	for (int i=0; i+2<=N; i+=2) {
	    add_global(A[i+1] - A[i]);

	    if (i+2 == N) {
		find(0);
	    } else {
		// PPPP;
		find(sums[N] - sums[i+2]);

		// PPPC;
		find(sums[N] - sums[i+2] - 2LL*A[N-1]);
	    }

	    // CCCC;
	    add(-sums[i+2]);
	    // PCCC;
	    add(2LL*A[0] - sums[i+2]);
	}

	run();
    }

    {
	init();
	add(A[0]);
	add(-A[0]);
	for (int i=1; i+2<=N; i+=2) {
	    add_global(A[i+1] - A[i]);

	    if (i+2 == N) {
		find(0);
	    } else {
		// PPPP;
		find(sums[N] - sums[i+2]);

		// PPPC;
		find(sums[N] - sums[i+2] - 2LL*A[N-1]);
	    }

	    // CCCC;
	    add(-sums[i+2]);
	    // PCCC;
	    add(2LL*A[0] - sums[i+2]);
	}

	run();
    }

    {
	Mint tmp = 0;
	// PPPPPP
	if (sums[N]) tmp += 1;

	// PPCC
	for (int i=1; i<N; i++) {
	    LL x = sums[i] - (sums[N] - sums[i]);
	    if (x > 0) tmp += 1;
	}
	ans += tmp;
    }

    printf("%d\n", ans.geti());
}

int main() {
    // test();
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}