#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<cassert>
using namespace std;
const double PI=acos(-1);

typedef long long LL;
typedef complex<double> P;
const double EPS = 1e-8;
const double INF = 1e12;
namespace std {
	bool operator < (const P &a, const P &b) {
		return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);
	}
}
double cross(const P &a, const P &b) {
	return imag(conj(a)*b);
}
double dot(const P &a, const P &b) {
	return real(conj(a)*b);
}

struct L : public vector<P> {
	L(const P &a, const P &b) {
		push_back(a); push_back(b);
	}
};
int ccw(P a, P b, P c) {
	 b-=a; c-=a;
	 if (cross(b, c) > 0) return 1;		// counter clockwise
	 if (cross(b, c) < 0) return -1;	// clockwise
	 if (dot(b, c) < 0) return 2;		// c--a--b on line
	 if (norm(b) < norm(c)) return -2;  // a--b--c on line
	 return 0;
}
bool intersectLL(const L &l, const L &m) {
	return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;
}
bool intersectLS(const L &l, const L &s) {
	return cross(l[1]-l[0], s[0]-l[0]) * cross(l[1]-l[0], s[1]-l[0]) < EPS;
}
bool intersectSS(const L &s, const L &t) {
	return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1])<=0 && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1])<=0;
}
bool intersectSP(const L &s, const P &p) {
	  return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS; // triangle inequality
}

P crosspoint(const L &l, const L &m) {
	double A = cross(l[1]-l[0], m[1]-m[0]);
	double B = cross(l[1]-l[0], l[1]-m[0]);
	if (abs(A) < EPS && abs(B) < EPS) return m[0];
	if (abs(A) < EPS) assert(false);
	return m[0]+B/A*(m[1]-m[0]);
}
double w, h, a;
int main() {
    scanf("%lf%lf%lf", &w, &h, &a);
    if (h==w && (a==0 || a==90 || a==180)) {
	printf("%.9f\n", w*h);
	return 0;
    }
    
    if (w<h) swap(w, h);
    if (a>90) a=180-a;
    P t1(w/2, h/2), t2(w/2, -h/2), s1, s2;
    s1=t1*polar(1.0, PI*a/180);
    s2=t2*polar(1.0, PI*a/180);
    if (imag(s2)>imag(t1)) {
	P v1=crosspoint(L(t1, -conj(t1)), L(s1, -s2)),
	    v2=crosspoint(L(t1, -conj(t1)), L(s2, -s1));
	printf("%.9f\n", w*h-(abs(s1-v1)+abs(s2-v2))*h);
    } else {
	P v1=crosspoint(L(t1, -conj(t1)), L(s1, -s2)),
	    v2=crosspoint(L(t1, -conj(t1)), L(s1, s2)),
	    v3=crosspoint(L(t1, t2), L(s1, s2));
	printf("%.9f\n", w*h-abs(s1-v1)*abs(s1-v2)-abs(t1-v2)*abs(t1-v3));
    }

    return 0;
}