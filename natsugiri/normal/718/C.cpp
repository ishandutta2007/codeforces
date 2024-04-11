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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }

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

const int SIZE = 2;
struct Arr {
    unsigned D[SIZE];
    Arr() { memset(D, 0, sizeof D); }
    unsigned &operator[](int i) { return D[i]; }
    const unsigned &operator[](int i) const { return D[i]; }
    Arr& operator+=(const Arr &y) {
	for (int i=0; i<SIZE; i++)
	    if ((D[i] += y[i]) >= MOD) D[i] -= MOD;
	return *this;
    }
    Arr& operator-=(const Arr &y) {
	for (int i=0; i<SIZE; i++)
	    if ((D[i] += MOD-y[i]) >= MOD) D[i] -= MOD;
	return *this;
    }
    Arr operator+(const Arr &y) const { return Arr(*this) += y; }
    Arr operator-(const Arr &y) const { return Arr(*this) -= y; }
};

struct Mat {
    unsigned D[SIZE][SIZE];
    Mat() { memset(D, 0, sizeof D); }
    unsigned (&operator[](int i))[SIZE] { return D[i]; }
    const unsigned (&operator[](int i) const)[SIZE] { return D[i]; }
    static unsigned long long z[SIZE];
    Mat& operator+=(const Mat &y) {
	for (int i=0; i<SIZE; i++)
	    for (int j=0; j<SIZE; j++)
		if ((D[i][j] += y[i][j]) >= MOD) D[i][j] -= MOD;
	return *this;
    }
    Mat& operator-=(const Mat &y) {
    	for (int i=0; i<SIZE; i++)
	    for (int j=0; j<SIZE; j++)
		if ((D[i][j] += MOD-y[i][j]) >= MOD) D[i][j] -= MOD;
	return *this;
    }
    Mat& operator*=(const Mat &y) { return *this = *this * y; }
    Mat operator+(const Mat &y) const { return Mat(*this) += y; }
    Mat operator-(const Mat &y) const { return Mat(*this) -= y; }
    Mat operator*(const Mat &y) const {
	Mat r = Mat();
	memset(z, 0, sizeof z);
	for (int i=0; i<SIZE; i++) {
	    for (int k=0; k<SIZE; k++) {
		for (int j=0; j<SIZE; j++)
		    z[j] += (unsigned long long)D[i][k] * y[k][j];
		if ((k&7)==7)
		    for (int j=0; j<SIZE; j++)
			z[j] %= MOD;
	    }
	    for (int j=0; j<SIZE; j++) {
		r[i][j] = z[j] % MOD;
		z[j] = 0;
	    }
	}
	return r;
    }
    Arr operator*(const Arr &y) const {
	Arr r = Arr();
	memset(z, 0, sizeof z);
	for (int i=0; i<SIZE; i++) {
	    for (int j=0; j<SIZE; j++) {
		z[i] += (unsigned long long)D[i][j] * y[j];
		if (z[i] & (1LL<<63)) z[i] %= MOD;
	    }
	    r[i] = z[i] % MOD;
	    z[i] = 0;
	}
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
    static Mat I() {
	Mat x = Mat();
	for (int i=0; i<SIZE; i++) x[i][i] = 1;
	return x;
    }
};
unsigned long long Mat::z[SIZE];

const int MAX = 1000000;

//LL fib[MAX];
//void make_fib() {
//    fib[0] = 0;
//    fib[1] = 1;
//    for (int i=2; i<MAX; i++)
//        fib[i] = fib[i-1] + fib[i-2];
//}
//
//// O(1);
//LL fast_fibonacci(int n, LL f0=0, LL f1=1) {
//    assert(0<=n && n<MAX);
//    if (n==0) return f0;
//    if (n==1) return f1;
//    return (fib[n-1] * f0 + fib[n] * f1) % MOD;
//}

// O(log n)
LL fib(LL n, LL f0=0, LL f1=1) {
    LL x[3] = { 0, 1, 1 }, y[3];
    for (; n; n>>=1) {
        if (n&1) {
            LL g0 = (x[1] * f1 + x[0] * f0) % MOD;
            LL g1 = (x[2] * f1 + x[1] * f0) % MOD;
            f0 = g0;
            f1 = g1;
        }
        y[0] = (x[1]*x[1] + x[0]*x[0]) % MOD;
        y[1] = (x[2]+x[0])*x[1] % MOD;
        y[2] = (x[2]*x[2] + x[1]*x[1]) % MOD;
        x[0] = y[0]; x[1] = y[1]; x[2] = y[2];
    }
    return f0;
}


Mat fib_i;
struct Seg {
    Arr f;
    Seg(int val_=0) {
	f[0] = fib(val_);
	f[1] = fib(val_+1);
    }
    Seg(int f0_, int f1_) {
	f[0] = f0_;
	f[1] = f1_;
    }
};

Seg operator+(const Seg &x, const Seg &y) {
    Seg z;
    z.f = x.f + y.f;
    return z;
};

struct Lazy {
    Mat m;
    Lazy() {
	m = Mat::I();
    }
    void inc(LL x) {
	m = fib_i.pow(x) * m;
    }
};

Seg operator*(const Lazy &x, const Seg &y) {
    Seg z;
    z.f = x.m * y.f;
    return z;
}

const Seg unit = Seg(0, 0);

// With Lazy
struct SegmentTree {
    int n, m;
    vector<Seg> d;
    vector<Lazy> lazy;

    SegmentTree(int n_=1) : n(n_) {
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, unit);
	lazy.assign(m*2, Lazy());
    }

    template<class T> SegmentTree(const vector<T> &a) : n(a.size()) { // When Seg(T) is defined
	if (n < 2) m = 1;
	else m = 2 << __lg(n-1);
	d.assign(m*2, unit);
	REP (i, n) d[i+m] = Seg(a[i]);
	for (int i=m; --i; ) d[i] = d[i*2] + d[i*2+1];
	lazy.assign(m*2, Lazy());
    }

    void force(int k) {
//	if (k < m) {
//	    lazy[k*2] += lazy[k];
//	    lazy[k*2+1] += lazy[k];
//	}
//	// Lazy Update on d[k]
//	lazy[k] = 0;
    }

    void add(int x, int y, LL v) { add(x, y, v, 1, 0, m); }

    void add(int x, int y, LL v, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return;
	if (x<=l && r<=y) { lazy[k].inc(v); force(k); return; }
	add(x, y, v, k*2, l, (l+r)/2); add(x, y, v, k*2+1, (l+r)/2, r); 
	d[k] = lazy[k*2] * d[k*2] + lazy[k*2+1] * d[k*2+1];
    }

    Seg query(int x, int y) { return query(x, y, 1, 0, m); }

    Seg query(int x, int y, int k, int l, int r) {
	force(k);
	if (r<=x || y<=l) return unit;
	if (x<=l && r<=y) return lazy[k] * d[k];
	return lazy[k] * (query(x, y, k*2, l, (l+r)/2) + query(x, y, k*2+1, (l+r)/2, r));
    }
};


int N, M, A[100111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);


    fib_i[0][0] = 0;
    fib_i[0][1] = 1;
    fib_i[1][0] = 1;
    fib_i[1][1] = 1;

    SegmentTree X(VI(A, A+N));

    REP ($, M) {
	int op, l, r, x;
	scanf("%d%d%d", &op, &l, &r);
	l--;
	if (op == 1) {
	    scanf("%d", &x);
	    X.add(l, r, x);
	} else {
	    Seg s = X.query(l, r);
	    printf("%d\n", (int)s.f[0]);
	}

    }


    return 0;
}