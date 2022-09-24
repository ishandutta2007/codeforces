#include<cmath>
#include<complex>
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
const double PI=acos(-1);
const Complex I(0,1);

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


int N;
int X;
int A[200011];

const int BASE = 1<<18;
const int SIZE = BASE+BASE;
Complex S[SIZE], T[SIZE];
LL ans[200011];
const int MAGIC = 1000;

void MAIN() {
    scanf("%d%d", &N, &X);
    REP (i, N) {
	scanf("%d", A+i);
    }

    int cnt = 1;
    VI v;
    REP (i, N) {
	if (A[i] < X) {
	    v.push_back(cnt);
	    cnt = 1;
	} else {
	    cnt++;
	}
    }
    v.push_back(cnt);
//    rprintf("%d", v.begin(), v.end());

    REP (i, v.size()) {
	ans[0] += (LL)v[i] * (v[i]-1) / 2;
    }

    // O(N^2 / MAGIC);
    REP (i, v.size()) if (v[i] > MAGIC) {
	REP (j, v.size()) if (i != j) {
	    ans[abs(i-j)] += (LL)v[i] * v[j];
	}
	v[i] = 0;
    }

    REP (i, v.size()) {
	S[i] = Complex(v[i], 0);
	T[BASE-i] = Complex(v[i], 0);
    }

    fft(S, SIZE);
    fft(T, SIZE);
    REP (i, SIZE) S[i] *= T[i];
    fft(S, SIZE, true);
    for (int i=1; i<=N; i++) {
	ans[i] += S[BASE-i].real()+0.5;
    }

    rprintf("%lld", ans, ans+N+1);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}