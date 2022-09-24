#include<complex>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }
typedef double Double;
const Double EPS = 1e-8; // 0 ~~ [-EPS, EPS]
// const LL EPS = 0;
const Double INF = 1e12;
const Double PI = acos((Double)-1);

typedef complex<Double> Point;
const Point I(0, 1);

// abs(P a) ::= sqrt(a.x^2 + a.y^2);
// norm(P a) ::= a.x^2 + a.y^2;
// Point polar(rho, theta=0)

int sign(Double x) {
    if (x < -EPS) return -1;
    if (EPS < x) return 1;
    return 0;
}

namespace std {
    bool operator<(const Point &x, const Point &y) {
	return real(x) != real(y)? real(x) < real(y): imag(x) < imag(y);
    }
}

Double cross(const Point &x, const Point &y) {
    return imag(conj(x)*y);
}
Double dot(const Point &x, const Point &y) {
    return real(conj(x)*y);
}
Point normal(const Point &a) { return a / abs(a); }

const int MAX = 1<<20;

// Point data[MAX];
// bool lazy[MAX];
// Point lazy_add[MAX], lazy_mul[MAX];
// typedef Point T;


// ADD: for i in [x, y): d[i] += v;
// MUL: for i in [x, y): d[i] *= v;
// RET: d[i]
template<class T> struct AddMul {
    int N, M;
    vector<T> a, m;
    vector<bool> lazy;
    AddMul(int N_=1): N(N_), M(2<<__lg(max(1, N))), a(2*M, 0), m(2*M, 1), lazy(2*M) {
    }
    
    void force(int k) {
	if (k < M && lazy[k]) {
	    REP (i, 2) {
		m[k*2+i] *= m[k];
		a[k*2+i] *= m[k];
		a[k*2+i] += a[k];
		lazy[k*2+i] = true;
	    }
	    m[k] = 1;
	    a[k] = 0;
	    lazy[k] = false;
	}
    }
    void add(int x, int y, const T &v) { add(x, y, 1, 0, M, v); }
    void add(int x, int y, int k, int l, int r, const T &v) {
	force(k);
	if (x <= l && r <= y) {
	    lazy[k] = true;
	    a[k] += v;
	} else if (x < r && l < y) {
	    add(x, y, k*2, l, (l+r)/2, v); add(x, y, k*2+1, (l+r)/2, r, v);
	}
    }
    void mul(int x, int y, const T &v) { mul(x, y, 1, 0, M, v); }
    void mul(int x, int y, int k, int l, int r, const T &v) {
	force(k);
	if (x <= l && r <= y) {
	    lazy[k] = true;
	    a[k] *= v;
	    m[k] *= v;
	} else if (x < r && l < y) {
	    mul(x, y, k*2, l, (l+r)/2, v); mul(x, y, k*2+1, (l+r)/2, r, v);
	}
    }
    T get(int x) {
	x += M;
	//T ret = data[x];
	T ret(0, 0);
	for (; x; x>>=1) {
	    ret = ret * m[x] + a[x];
	}
	return ret;
    }
};



int N, M;

int main() {
    scanf("%d%d", &N, &M);

    AddMul<Point> X(N+10);
    REP (i, N+1) X.add(i, i+1, Point(i, 0));
    
    REP ($, M) {
	// REP (i, N+1) cerr << X.get(i) << " "; cerr << endl;

	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);

	Point r = X.get(y-1);
	Point b = X.get(y);
	if (x == 1) {
	    Point v = normal(b-r) * (Double)z;
	    X.add(y, N+1, v);
	} else {
	    X.add(y, N+1, -r);
	    Point p = polar(1.0, -PI * (Double)z / 180.0);
	    // cerr << "mul" << p << endl;
	    X.mul(y, N+1, p);
	    X.add(y, N+1, r);
	}

	Point ans = X.get(N);
	printf("%.9f %.9f\n", ans.real(), ans.imag());
    }
    return 0;
}