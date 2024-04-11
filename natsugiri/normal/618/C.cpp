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
typedef long double Double;
//typedef LL Double;
const Double EPS = 1e-8; // 0 ~~ [-EPS, EPS]
//const LL EPS = 0;
// const Double INF = 1e12;
// const Double PI = acos((Double)-1);

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
int ccw(Point a, Point b, Point c) {
    b-=a; c-=a;
    if (cross(b, c) > EPS) return 1; // counter clockwise
    if (cross(b, c) < -EPS) return -1; // clockwise
    return 0;
    // if (dot(b, c) < -EPS) return 2; // c--a--b on line
    // if (norm(b) < norm(c)) return -2; // a--b--c on line
    // return 0;
}

int N;
LL X[100111], Y[100111];

LL sq(LL x) { return x*x; }
LL dist(int i, int j) { return sq(X[i] - X[j]) + sq(Y[i] - Y[j]); }

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld", X+i, Y+i);

    int s = rand() % N;
    int k = -1;
    for (int i=0; i<N; i++) {
	if (i == s) continue;
	if (k == -1 || dist(s, k) > dist(s, i)) k = i;
    }

    Point p0(X[s], Y[s]);
    Point pk(X[k], Y[k]);

    int th = -10;
    int h = -1;
    for (int i=0; i<N; i++) {
	if (i == k || i == s) continue;
	int t = ccw(p0, pk, Point(X[i], Y[i]));
	if (t == 0) continue;

	if (h == -1) { h = i; th = t; }
	else {
	    if (t != th) continue;
	    
	    int t2 = ccw(p0, Point(X[i], Y[i]), Point(X[h], Y[h]));
	    if (t == t2) { h = i; th = t; }
	    else if (t2 == 0) {
		if (dist(s, h) > dist(s, i)) { h = i; th = t; }
	    }
	}
    }

    
    printf("%d %d %d\n", s+1, k+1, h+1);
    
    return 0;
}