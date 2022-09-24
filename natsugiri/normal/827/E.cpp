#include<complex>
#include<cmath>
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

typedef complex<double> Complex;
const double PI=acos(-1);//M_PI;
const Complex I(0,1);

// Stockham algorithm
// Hint: vector<Complex> v; fft(&v[0], v.size(), false);
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
		y[q + s * (p + p)] = a + b;
		y[q + s * (p + p + 1)] = (a - b) * wp;
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

void convolution(const Complex *Fx, const Complex *Fy, Complex *Fz, const int n) {
    for (int i=0; i<n; i++) Fz[i] = Fx[i] * Fy[i];
}

int N, M;
char S[500111];

const int SIZE = 1 << 20;
Complex X[SIZE], Y[SIZE], Z[SIZE];
bool B[500111];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);

    int half = 1;
    while (half <= N) half += half;

    REP (i, half*2) {
	X[i] = Y[i] = Z[i] = 0.0;
    }
    REP (i, N) B[i+1] = true;


    REP (i, N) {
	if (S[i] == 'V') X[i] = 1.0;
	if (S[i] == 'K') Y[half-i] = 1.0;
    }
    fft(X, half*2);
    fft(Y, half*2);
    convolution(X, Y, Z, half*2);
    fft(Z, half*2, true);

    REP (i, half*2) {
	if (Z[i].real() > 0.8) {
	    if (i < half) B[half-i] = false;
	    if (half < i) B[i-half] = false;
	}
    }

    int false_max = 0;
    VI ans;
    for (int i=N; i>0; i--) {
	if (B[i]) {
	    for (int j=i+i; j<=false_max; j+=i) if (!B[j]) {
		B[i] = false;
		break;
	    }
	} else {
	    amax(false_max, i);
	}

	if (B[i]) ans.push_back(i);
    }

    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}