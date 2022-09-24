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
template<int MOD>
struct ModInt {
    unsigned x;
    void undef() { x = (unsigned)-1; }
    bool isnan() const { return x == (unsigned)-1; }
    inline int getInt() const { return (int)x; }
    template<class T> T get() const { return (T)x; }
    inline int mod() const { return MOD; }
    ModInt(int y=0) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(long long y) { if (y<0 || MOD<=y) y %= MOD; if (y<0) y += MOD; x=y; }
    ModInt(unsigned long long y) { if (MOD<=y) x = y % (unsigned long long)MOD; else x = y; }
    ModInt &operator+=(const ModInt &y) { if ((x += y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(const ModInt &y) { if ((x += MOD - y.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(const ModInt &y) { x = (unsigned long long)x * y.x % (unsigned long long)MOD; return *this; }
    ModInt &operator/=(const ModInt &y) { x = (unsigned long long)x * y.inv().x % (unsigned long long)MOD; return *this; }
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
};
const LL MOD = 1000000007;
typedef ModInt<MOD> Mint;
Mint operator+(Mint x, const Mint &y) { if ((x.x += y.x) >= (unsigned)x.mod()) x.x -= x.mod(); return x; }
Mint operator-(Mint x, const Mint &y) { if ((x.x += x.mod() - y.x) >= (unsigned)x.mod()) x.x -= x.mod(); return x; }
Mint operator*(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.x % (unsigned long long)x.mod(); return x; }
Mint operator/(Mint x, const Mint &y) { x.x = (unsigned long long)x.x * y.inv().x % (unsigned long long)x.mod(); return x; }
bool operator<(const Mint &x, const Mint &y) { return x.x < y.x; }
bool operator==(const Mint &x, const Mint &y) { return x.x == y.x; }
bool operator!=(const Mint &x, const Mint &y) { return x.x != y.x; }

//const LL MOD = 1e9+7;
struct Arr {
    unsigned d0, d1;

    Arr() { d0 = d1 = 0; }
    Arr(int d0_, int d1_) {
	if ((d0_ %= MOD) < 0) d0_ += MOD;
	if ((d1_ %= MOD) < 0) d1_ += MOD;
	d0 = d0_; d1 = d1_;
    }
    Arr(LL d0_, LL d1_) {
	if ((d0_ %= MOD) < 0) d0_ += MOD;
	if ((d1_ %= MOD) < 0) d1_ += MOD;
	d0 = d0_; d1 = d1_;
    }

    const unsigned &operator[](int i) const {
	return operator()(i);
    }
    const unsigned &operator()(int i) const {
	return i? d1: d0;
    }

    Arr& set(int i, int v) {
	if ((v %= MOD) < 0) v += MOD;
	(i? d1: d0) = v;
	return *this;
    }
    Arr& set(int i, LL v) {
	if ((v %= MOD) < 0) v += MOD;
	(i? d1: d0) = v;
	return *this;
    }

    Arr& operator+=(const Arr &y) {
	if ((d0 += y.d0) >= MOD) d0 -= MOD;
	if ((d1 += y.d1) >= MOD) d1 -= MOD;
	return *this;
    }
    Arr& operator-=(const Arr &y) {
	if ((d0 += MOD - y.d0) >= MOD) d0 -= MOD;
	if ((d1 += MOD - y.d1) >= MOD) d1 -= MOD;
	return *this;
    }
    Arr operator+(const Arr &y) const { return Arr(*this) += y; }
    Arr operator-(const Arr &y) const { return Arr(*this) -= y; }
};

struct Mat {
    unsigned d00, d01, d10, d11;
    Mat() { d00 = d01 = d10 = d11 = 0; }
    Mat(int d00_, int d01_, int d10_, int d11_) { 
	if ((d00_ %= MOD) < 0) d00_ += MOD; d00 = d00_; 
	if ((d01_ %= MOD) < 0) d01_ += MOD; d01 = d01_; 
	if ((d10_ %= MOD) < 0) d10_ += MOD; d10 = d10_; 
	if ((d11_ %= MOD) < 0) d11_ += MOD; d11 = d11_; 
    }
    Mat(LL d00_, LL d01_, LL d10_, LL d11_) { 
	if ((d00_ %= MOD) < 0) d00_ += MOD; d00 = d00_; 
	if ((d01_ %= MOD) < 0) d01_ += MOD; d01 = d01_; 
	if ((d10_ %= MOD) < 0) d10_ += MOD; d10 = d10_; 
	if ((d11_ %= MOD) < 0) d11_ += MOD; d11 = d11_; 
    }

    const unsigned &operator()(int r, int c) const { 
	return r? (c? d11: d10): (c? d01: d00);
    }

    Mat& set(int r, int c, int v) {
	if ((v %= MOD) < 0) v += MOD;
	(r? (c? d11: d10): (c? d01: d00)) = v;
	return *this;
    }
    Mat& set(int r, int c, LL v) {
	if ((v %= MOD) < 0) v += MOD;
	(r? (c? d11: d10): (c? d01: d00)) = v;
	return *this;
    }

    Mat& operator+=(const Mat &y) {
	if ((d00 += y.d00) >= MOD) d00 -= MOD;
	if ((d01 += y.d01) >= MOD) d01 -= MOD;
	if ((d10 += y.d10) >= MOD) d10 -= MOD;
	if ((d11 += y.d11) >= MOD) d11 -= MOD;
	return *this;
    }
    Mat& operator-=(const Mat &y) {
	if ((d00 += MOD - y.d00) >= MOD) d00 -= MOD;
	if ((d01 += MOD - y.d01) >= MOD) d01 -= MOD;
	if ((d10 += MOD - y.d10) >= MOD) d10 -= MOD;
	if ((d11 += MOD - y.d11) >= MOD) d11 -= MOD;
	return *this;
    }
    Mat& operator*=(const Mat &y) { return *this = *this * y; }
    Mat operator+(const Mat &y) const { return Mat(*this) += y; }
    Mat operator-(const Mat &y) const { return Mat(*this) -= y; }
    Mat operator*(const Mat &y) const {
	Mat r = Mat();
	r.d00 = ((unsigned long long)d00 * y.d00 + (unsigned long long)d01 * y.d10) % MOD;
	r.d01 = ((unsigned long long)d00 * y.d01 + (unsigned long long)d01 * y.d11) % MOD;
	r.d10 = ((unsigned long long)d10 * y.d00 + (unsigned long long)d11 * y.d10) % MOD;
	r.d11 = ((unsigned long long)d10 * y.d01 + (unsigned long long)d11 * y.d11) % MOD;
	return r;
    }
    Arr operator*(const Arr &y) const {
	Arr r = Arr();
	r.d0 = ((unsigned long long)d00 * y.d0 + (unsigned long long)d01 * y.d1) % MOD;
	r.d1 = ((unsigned long long)d10 * y.d0 + (unsigned long long)d11 * y.d1) % MOD;
	return r;
    }
    Mat pow(unsigned long long y) const {
	Mat x(*this), r = I();
	for (; y; y>>=1) {
	    if (y&1) r *= x;
	    x *= x;
	}
	return r;
    }
    Arr powmul(unsigned long long y, Arr z) const {
	Mat x(*this);
	for (; y; y>>=1) {
	    if (y&1) z = x * z;
	    x *= x;
	}
	return z;
    }
    static const Mat& I() {
	static const Mat I_ = Mat(1, 0, 0, 1);
	return I_;
    }
};

int N;
LL A[100111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);

    const int INV2 = (MOD + 1) / 2;
    Mint de = 2;
    Mat ma(0, 1, 2, 1);
    REP (i, N) {
	de = de.pow(A[i]);
	ma = ma.pow(A[i]);
    }

    Arr ar(INV2, 0);
    Mint nu = (LL)(ma * ar)(0);
    de *= INV2;
    printf("%d/%d\n", nu.getInt(), de.getInt());

    return 0;
}