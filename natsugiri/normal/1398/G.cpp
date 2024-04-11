#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<bitset>
#include<complex>
#include<cmath>

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

typedef complex<double> Complex;
const double PI=acos(-1);
const Complex I(0,1);

// Stockham algorithm
// Hint: vector<Complex> v; fft(v.data(), v.size(), false);
void fft(Complex *x, const int n, const bool idft=false) {
    static Complex *y = NULL; static int y_len = 0;
    if (y_len < n) {
	if (y) delete[] y;
	y_len = n;
	y = new Complex[y_len];
    }
    if (idft) {
	for (int p=0; p<n; p++) x[p] = conj(x[p]);
    }
    int nn = n, s = 1, eo = 0;
    for (; nn>1;) {
	const int m = nn / 2;
	const double theta = 2.0 * PI / nn;
	for (int p=0; p<m; p++) {
	    const Complex wp(cos(p * theta), -sin(p * theta));
	    for (int q=0; q<s; q++) {
		const Complex a = x[q + s * p];
		const Complex b = x[q + s * (p + m)];
		const Complex c = a - b;
		y[q + s * (p + p)] = a + b;
		y[q + s * (p + p + 1)] = Complex(
			c.real()*wp.real() - c.imag()*wp.imag(),
			c.real()*wp.imag() + c.imag()*wp.real());
		//y[q + s * (p + p + 1)] = (a - b) * wp;
	    }
	}
	nn = m; s += s; eo ^= 1;
	swap(x, y);
    }
    if (eo) {
	for (int q=0; q<s; q++) y[q] = x[q];
	swap(x, y);
    }
    if (idft) {
	double b = 1.0 / n;
	for (int p=0; p<n; p++) x[p] = conj(x[p]) * b;
    }
}

VI convolution(const VI &in0, const VI &in1, const long long mod) {
    // mod must be a prime;
    assert(mod <= 1000000013);
    const int SHIFT = 15;
    const int MASK = (1<<SHIFT)-1;
    int n = 1;
    while (n < (int)in0.size() + (int)in1.size() - 1) n += n;
    vector<Complex> f(n+1), g(n+1);
    REP (i, in0.size()) {
	f[i].real(in0[i] & MASK);
	f[i].imag(in0[i] >> SHIFT);
    }
    REP (i, in1.size()) {
	g[i].real(in1[i] & MASK);
	g[i].imag(in1[i] >> SHIFT);
    }
    fft(f.data(), n);
    fft(g.data(), n);
    f[n] = f[0];
    g[n] = g[0];
    for (int i=0; i<=n/2; i++) {
	double flr = (f[i].real()+f[n-i].real())/2;
	double fli = (f[i].imag()-f[n-i].imag())/2;
	double fhr = (f[i].imag()+f[n-i].imag())/2;
	double fhi = (-f[i].real()+f[n-i].real())/2;
	double glr = (g[i].real()+g[n-i].real())/2;
	double gli = (g[i].imag()-g[n-i].imag())/2;
	double ghr = (g[i].imag()+g[n-i].imag())/2;
	double ghi = (-g[i].real()+g[n-i].real())/2;
	// (flr*glr - fli*gli, flr*gli + fli*glr);
	// (flr*ghr - fli*ghi, flr*ghi + fli*ghr);
	double x0 = flr*glr - fli*gli, x1 = - flr*ghi - fli*ghr;
	double y0 = flr*gli + fli*glr, y1 = flr*ghr - fli*ghi;
	f[i] = Complex(x0 + x1, y0 + y1);
	f[n-i] = Complex(x0 - x1, - y0 + y1);
	// (fhr*glr - fhi*gli, fhr*gli + fhi*glr);
	// (fhr*ghr - fhi*ghi, fhr*ghi + fhi*ghr);
	x0 = fhr*glr - fhi*gli, x1 = - fhr*ghi - fhi*ghr;
	y0 = fhr*gli + fhi*glr, y1 = fhr*ghr - fhi*ghi;
	g[i] = Complex(x0 + x1, y0 + y1);
	g[n-i] = Complex(x0 - x1, - y0 + y1);
    }
    fft(f.data(), n, true);
    fft(g.data(), n, true);
    VI r((int)in0.size() + (int)in1.size() - 1);
    double diff = 0;
    REP (i, r.size()) {
	LL a = llround(f[i].real());
	LL b = llround(f[i].imag());
	LL c = llround(g[i].real());
	LL d = llround(g[i].imag());
	r[i] = ((((d%mod << SHIFT)+b+c)%mod << SHIFT)+a) % mod;
#ifdef LOCAL 
	amax(diff, abs(a - f[i].real()));
	amax(diff, abs(b - f[i].imag()));
	amax(diff, abs(c - g[i].real()));
	amax(diff, abs(d - g[i].imag()));
#endif
    }
    eprintf("Convolution error diff = %e\n", diff);
    return r;
}
int N;
int X, Y;
int A[200011];
int L[200011];

int Q;

const int SIZE = 200011;
struct Data {
    int l;
    int d;

    bool operator<(const Data&o) const {
	return d < o.d;
    }
} D[SIZE];

using Bits = bitset<(1<<18)>;
Bits Xs;
Bits Ds;

const int LIMIT = 1000011;
int valid[LIMIT];

constexpr LL MOD = 998244353;

void MAIN() {
    scanf("%d%d%d", &N, &X, &Y);
    REP (i, N+1) scanf("%d", A+i);

    scanf("%d", &Q);
    REP (i, Q) {
	int l;
	scanf("%d", &l);
	L[i] = l;
    }

    const int BASE = 200000;
    VI C1(1<<18), C2(1<<18);

    REP (i, N+1) {
	int a = A[i];
	C1[a] = 1;
	C2[BASE-a] = 1;
    }

    VI C3 = convolution(C1, C2, MOD);

    memset(valid, -1, sizeof valid);
    for (int i=1; i<=BASE; i++) {
	if (C3[BASE+i]) {
	    //eprintf("%d\n", i);
	    valid[2*(Y+i)] = 2*(Y+i);
	}
    }

//    for (int i=N+1; i--;) {
//	int a = A[i];
//	Ds |= Xs >> a;
//	Xs.set(a);
//    }
//
//
//    REP (i, X+1) if (Ds.test(i)) {
//	eprintf("%d\n", i);
//	valid[2*(Y+i)] = 2*(Y+i);
//    }

    for (int i=1; i<LIMIT; i++) if (valid[i] != -1) {
	for (int j=i*2; j<LIMIT; j+=i) amax(valid[j], valid[i]);
    }

    REP (i, Q) {
	L[i] = valid[L[i]];
    }
    rprintf("%d", L, L+Q);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}