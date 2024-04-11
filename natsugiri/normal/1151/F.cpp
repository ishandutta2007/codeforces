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

template<class Mint, int SIZE> struct MintArrBase {
    Mint d[SIZE];

    MintArrBase() { clear(); }
    MintArrBase(const MintArrBase &y) { memcpy(d, y.d, sizeof d); }
    void clear() { memset(d, 0, sizeof d); }

    Mint& operator[](int i) { return d[i]; }
    const Mint& operator[](int i) const { return d[i]; }
    Mint& get(int i) { return d[i]; }
    const Mint& get(int i) const { return d[i]; }
    void set(int i, const Mint &v) { d[i] = v; }
    void add(int i, const Mint &v) { d[i] += v; }

    MintArrBase& operator+=(const MintArrBase &y) {
	for (int i=0; i<SIZE; i++) d[i] += y.d[i];
	return *this;
    }
    MintArrBase& operator-=(const MintArrBase &y) {
	for (int i=0; i<SIZE; i++) d[i] -= y.d[i];
	return *this;
    }
    MintArrBase operator+(const MintArrBase &y) const { return MintArrBase(*this) += y; }
    MintArrBase operator-(const MintArrBase &y) const { return MintArrBase(*this) -= y; }

    bool operator==(const MintArrBase &y) const {
	for (int i=0; i<SIZE; i++) if (d[i] != y.d[i]) return false;
	return true;
    }
    bool operator!=(const MintArrBase &y) const { return !(*this == y); }

    friend string to_string(const MintArrBase &x) {
	string s;
	char buf[21];
	for (int i=0; i<SIZE; i++) {
	    sprintf(buf, "%d", x[i].geti());
	    s += buf;
	    if (i < SIZE-1) s += " ";
	}
	return s;
    }
};

template<class Mint, int ROW, int COL> struct MintMatBase {
    static const int SIZE = ROW * COL;
    typedef unsigned long long ULL;
    Mint d[SIZE];

    MintMatBase() { clear(); }
    MintMatBase(const MintMatBase &y) { memcpy(d, y.d, sizeof d); }
    void clear() { memset(d, 0, sizeof d); }

    Mint* operator[](int r) { return d+r*COL; }
    const Mint* operator[](int r) const { return d+r*COL; }
    Mint& get(int r, int c) { return d[r*COL+c]; }
    const Mint& get(int r, int c) const { return d[r*COL+c]; }
    void set(int r, int c, const Mint &v) { d[r*COL+c] = v; }
    void add(int r, int c, const Mint &v) { d[r*COL+c] += v; }

    MintMatBase& operator+=(const MintMatBase &y) {
	for (int i=0; i<SIZE; i++) d[i] += y.d[i];
	return *this;
    }
    MintMatBase& operator-=(const MintMatBase &y) {
	for (int i=0; i<SIZE; i++) d[i] -= y.d[i];
	return *this;
    }
    template<int COL2> MintMatBase<Mint, ROW, COL2>& operator*=(const MintMatBase<Mint, COL, COL2> &y) { return *this = *this * y; }
    MintMatBase operator+(const MintMatBase &y) const { return MintMatBase(*this) += y; }
    MintMatBase operator-(const MintMatBase &y) const { return MintMatBase(*this) -= y; }
    template<int COL2> MintMatBase<Mint, ROW, COL2> operator*(const MintMatBase<Mint, COL, COL2> &y) const {
	static MintMatBase r;
	static ULL buf[COL2];
	for (int i=0; i<ROW; i++) {
	    memset(buf, 0, sizeof buf);
	    int k = 0; 
	    for (; k<=COL-16; k+=16) {
		for (int k_=k; k_<k+16; k_++)
		    for (int j=0; j<COL2; j++)
			buf[j] += (ULL)d[i*COL+k_].x * y.d[k_*COL2+j].x;
		for (int j=0; j<COL2; j++) buf[j] %= (ULL)Mint::static_MOD;
	    }
	    for (; k<COL; k++)
		for (int j=0; j<COL2; j++)
		    buf[j] += (ULL)d[i*COL+k].x * y.d[k*COL2+j].x;
	    for (int j=0; j<COL2; j++) r.d[i*COL2+j] = Mint(buf[j]);
	}
	return r;
    }
    MintArrBase<Mint, ROW> operator*(const MintArrBase<Mint, COL> &y) const {
	static MintArrBase<Mint, ROW> r;
	for (int i=0; i<ROW; i++) {
	    ULL buf = 0;
	    int j = 0;
	    for (; j<=COL-16; j+=16) {
		for (int j_=j; j_<j+16; j_++) buf += (ULL)d[i*COL+j_].x * y.d[j_].x;
		buf %= Mint::static_MOD;
	    }
	    for (; j<COL; j++) buf += (ULL)d[i*COL+j].x * y.d[j].x;
	    r.d[i] = Mint(buf);
	}
	return r;
    }
    MintMatBase pow(unsigned long long y) const {
	static MintMatBase x, r;
	x = *this; r = I();
	for (; y; y>>=1) {
	    if (y&1) r = r * x;
	    x = x * x;
	}
	return r;
    }
    MintArrBase<Mint, ROW> powmul(unsigned long long y, MintArrBase<Mint, ROW> z) const {
	static_assert(ROW == COL, "");
	static MintMatBase x;
	x = *this;
	for (; y; y>>=1) {
	    if (y&1) z = x * z;
	    x = x * x;
	}
	return z;
    }

    bool operator==(const MintMatBase &y) const {
	for (int i=0; i<SIZE; i++) if (d[i] != y.d[i]) return false;
	return true;
    }
    bool operator!=(const MintMatBase &y) const { return !(*this == y); }

    static const MintMatBase I() {
	static MintMatBase I_ = MintMatBase();
	if (I_.d[0] == 0)
	    for (int i=0; i<min(ROW, COL); i++) I_.set(i, i, 1);
	return I_;
    }

    friend string to_string(const MintMatBase &x) {
	string s;
	char buf[21];
	for (int i=0; i<ROW; i++) {
	    for (int j=0; j<COL; j++) {
		sprintf(buf, "%d", x.get(i, j).geti());
		s += buf;
		s += " \n"[j==COL-1];
	    }
	}
	return s;
    }
};



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

const int SIZE = 55;
const int ROW = SIZE;
const int COL = SIZE;

typedef MintArrBase<Mint, COL> Arr;
typedef MintMatBase<Mint, ROW, COL> Mat;

int N, K;
int A[101];
Mat M;

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    int one = count(A, A+N, 1);
    int zero = N - one;
    Mint base = Mint(N) * (N-1);
    base = base.inv();

    int mi = min(one, zero);
    REP (i, mi+1) {
	Mint rest = 1;
	if (i) {
	    Mint p = Mint(i) * i * base * 2;
	    rest -= p;
	    M.add(i-1, i, p);
	}
	if (i+1 <= mi) {
	    Mint p = Mint(zero-i) * (one-i) * base * 2;
	    rest -= p;
	    M.add(i+1, i, p);
	}
	M.add(i, i, rest);
    }

    int has = count(A, A+zero, 1);
    Arr X;
    X.add(has, 1);
    Arr Y = M.powmul(K, X);
    Mint ans = Y.get(0);
    printf("%d\n", ans.geti());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}