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

const LL MOD = 1e9+7;
const unsigned long long UMOD = MOD;
const unsigned HIGH = 1u << 31;
const int SIZE = 31;
struct Arr {
    unsigned D[SIZE];
    Arr() { memset(D, 0, sizeof D); }
    Arr(const Arr &y) { *this = y; }

    unsigned &operator[](int i) { return D[i]; }
    const unsigned &operator[](int i) const { return D[i]; }
    const unsigned &operator()(int i) const { return D[i]; }

    Arr& operator=(const Arr&y) {
	if (D != y.D) memcpy(D, y.D, sizeof (unsigned) * SIZE);
	return *this;
    }

    Arr& set(int i, int v) {
	if ((v %= MOD) < 0) v += MOD;
	D[i] = v;
	return *this;
    }
    Arr& set(int i, LL v) {
	if ((v %= MOD) < 0) v += MOD;
	D[i] = v;
	return *this;
    }

    Arr& operator+=(const Arr &y) {
	for (int i=0; i<SIZE; i++)
	    if ((D[i] += y[i]) >= UMOD) D[i] -= UMOD;
	return *this;
    }
    Arr& operator-=(const Arr &y) {
	for (int i=0; i<SIZE; i++)
	    if ((D[i] -= y[i]) & HIGH) D[i] += UMOD;
	return *this;
    }
    Arr operator+(const Arr &y) const { return Arr(*this) += y; }
    Arr operator-(const Arr &y) const { return Arr(*this) -= y; }
};

struct Mat {
    unsigned D[SIZE][SIZE];
    Mat() { memset(D, 0, sizeof D); }
    Mat(const Mat &y) { *this = y; }

    unsigned (&operator[](int i))[SIZE] { return D[i]; }
    const unsigned (&operator[](int i) const)[SIZE] { return D[i]; }
    const unsigned &operator()(int r, int c) const { return D[r][c]; }

    Mat& operator=(const Mat &y) {
	if (D != y.D) memcpy(D, y.D, sizeof (unsigned) * SIZE * SIZE);
	return *this;
    }

    Mat& set(int r, int c, int v) {
	if ((v %= MOD) < 0) v += MOD;
	D[r][c] = v;
	return *this;
    }
    Mat& set(int r, int c, LL v) {
	if ((v %= MOD) < 0) v += MOD;
	D[r][c] = v;
	return *this;
    }

    static unsigned long long z[SIZE];
    Mat& operator+=(const Mat &y) {
	for (int i=0; i<SIZE; i++)
	    for (int j=0; j<SIZE; j++)
		if ((D[i][j] += y[i][j]) >= UMOD) D[i][j] -= UMOD;
	return *this;
    }
    Mat& operator-=(const Mat &y) {
    	for (int i=0; i<SIZE; i++)
	    for (int j=0; j<SIZE; j++)
		if ((D[i][j] -= y[i][j]) & HIGH) D[i][j] += UMOD;
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
			z[j] %= UMOD;
	    }
	    for (int j=0; j<SIZE; j++) {
		r[i][j] = z[j] % UMOD;
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
		if (z[i] & (1LL<<63)) z[i] %= UMOD;
	    }
	    r[i] = z[i] % UMOD;
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
    static const Mat& I() {
	static Mat I_ = Mat();
	if (I_(0, 0) == 0)
	    for (int i=0; i<SIZE; i++) I_[i][i] = 1;
	return I_;
    }
};
unsigned long long Mat::z[SIZE];

LL N; int K;
Mat mat[65][30];
Mat L[32], R[32];
unsigned long long C[65];

int main() {
    scanf("%lld%d", &N, &K);

    REP (i, K) {
	REP (j, K+1) mat[0][i].set(j, j, 1).set(i, j, 1);
    }

    C[0] = 1;

    REP (t, 64) {
	C[t+1] = min((unsigned long long)N+1u, C[t] * K);
	L[0] = R[K] = Mat::I();
	REP (i, K) {
	    L[i+1] = mat[t][i] * L[i];
	    R[K-i-1] = R[K-i] * mat[t][K-i-1];
	}
	REP (i, K) mat[t+1][i] = L[i] * R[i];
    }

    int pos = 0;
    Arr arr; arr.set(K, 1);
    for (int t=64; t--;) {
	while (C[t] <= (unsigned long long)N) {
	    arr = mat[t][pos] * arr;
	    pos++;
	    if (pos == K) pos = 0;
	    N -= C[t];
	}
    }

    LL ans = 0;
    REP (i, K+1) ans += arr[i];
    printf("%lld\n", ans % MOD);

    return 0;
}