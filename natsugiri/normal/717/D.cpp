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

const int SIZE = 128;
template <class T> struct Arr {
    T D[SIZE];
    Arr() { memset(D, 0, sizeof D); }
    T &operator[](int i) { return D[i]; }
    const T &operator[](int i) const { return D[i]; }
    Arr& operator+=(const Arr &y) {
	for (int i=0; i<SIZE; i++) D[i] += y[i];
	return *this;
    }
    Arr& operator-=(const Arr &y) {
	for (int i=0; i<SIZE; i++) D[i] -= y[i];
	return *this;
    }
    Arr operator+(const Arr &y) const { return Arr(*this) += y; }
    Arr operator-(const Arr &y) const { return Arr(*this) -= y; }
    T dot(const Arr &y) {
	T r = 0;
	for (int i=0; i<SIZE; i++) r += D[i] * y[i];
	return r;
    }
};

template <class T> struct Mat {
    T D[SIZE][SIZE];
    Mat() { memset(D, 0, sizeof D); }
    T (&operator[](int i))[SIZE] { return D[i]; }
    const T (&operator[](int i) const)[SIZE] { return D[i]; }
    Mat& operator+=(const Mat &y) {
	for (int i=0; i<SIZE; i++)
	    for (int j=0; j<SIZE; j++)
		D[i][j] += y[i][j];
	return *this;
    }
    Mat& operator-=(const Mat &y) {
    	for (int i=0; i<SIZE; i++)
	    for (int j=0; j<SIZE; j++)
		D[i][j] -= y[i][j];
	return *this;
    }
    Mat& operator*=(const Mat &y) { return *this = *this * y; }
    Mat operator+(const Mat &y) const { return Mat(*this) += y; }
    Mat operator-(const Mat &y) const { return Mat(*this) -= y; }
    Mat operator*(const Mat &y) const {
	Mat r = Mat();
	for (int i=0; i<SIZE; i++)
	    for (int k=0; k<SIZE; k++)
		for (int j=0; j<SIZE; j++)
		    r[i][j] += D[i][k] * y[k][j];
	return r;
    }
    Arr<T> operator*(const Arr<T> &y) const {
	Arr<T> r = Arr<T>();
	for (int i=0; i<SIZE; i++)
	    for (int j=0; j<SIZE; j++)
		r[i] += D[i][j] * y[j];
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
    Arr<T> powmul(unsigned long long y, Arr<T> z) const {
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

int N, X;
double P[200];
int main() {
    scanf("%d%d", &N, &X);
    REP (i, X+1) scanf("%lf", P+i);

    Mat<double> A;
    REP (i, 128) REP (j, 128) {
	A[i][j] = P[i^j];
    }

    Arr<double> x;
    x[0] = 1;
    Arr<double> y = A.powmul(N, x);

    double ans = 1.0 - y[0];
    printf("%.9f\n", ans);



    return 0;
}