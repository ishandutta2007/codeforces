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
const double EPS = 1e-8;
const double INF = 1e12;
const double PI = acos(-1);

typedef complex<double> Point;
const Point I(0, 1.0);

// abs(P a) ::= sqrt(a.x^2 + a.y^2);
// norm(P a) ::= a.x^2 + a.y^2;
// Point polar(rho, theta=0)

int sign(double x) {
    if (x < EPS) return -1;
    if (x > EPS) return 1;
    return 0;
}

namespace std {
    bool operator <(const Point &x, const Point &y) {
	return real(x)!=real(y)?real(x)<real(y):imag(x)<imag(y);
    }
}

double cross(const Point &x, const Point &y) {
    return imag(conj(x)*y);
}
double dot(const Point &x, const Point &y) {
    return real(conj(x)*y);
}
Point normal(const Point &a) { return a / abs(a); }

struct Line : public vector<Point> {
    Line(const Point &a, const Point &b) {
	push_back(a); push_back(b);
    }
    Point vector() const {
	return back() - front();
    }
};

struct Circle {
    Point p; double r;
    Circle(){}
    Circle(const Point &p, double (r)) : p(p), r(r) {}
};

typedef vector<Point> Polygon;
double area2(const Polygon &P) {
    double ans = 0;
    REP (i, P.size()) {
	int j = i+1; if (j == (int)P.size()) j = 0;
	ans += cross(P[i], P[j]);
    }
    return abs(ans);
}
int ccw(Point a, Point b, Point c) {
    b-=a; c-=a;
    if (cross(b, c) > EPS) return 1; // counter clockwise
    if (cross(b, c) < EPS) return -1; // clockwise
    if (dot(b, c) < 0) return 2; // c--a--b on line
    if (norm(b) < norm(c)) return -2; // a--b--c on line
    return 0;
}

Polygon convex_hull(vector<Point> ps) {
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    vector<Point> ch(2*n);
    for (int i=0; i<n; ch[k++] = ps[i++]) // lower -hull
	while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper -hull
	while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}

int N, M;
int X, Y, A[100011][2], C[100011][2];
vector<Point> AP, CP;
int main() {
    scanf("%d%d", &N, &M);
    scanf("%d%d", &X, &Y);
    REP (i, N) scanf("%d%d", &A[i][0], &A[i][1]);
    REP (i, M) scanf("%d%d", &C[i][0], &C[i][1]);

    AP.reserve(N);
    REP (i, N) AP.push_back(Point(A[i][0], A[i][1]));

    CP.reserve(M+10);
    REP (i, M) CP.push_back(Point(C[i][0], C[i][1]));
    CP.push_back(Point(0, 0));

    {
	int y = C[0][1];
	REP (i, M) amax(y, C[i][1]);
	CP.push_back(Point(0, y));
    }
    {
	int x = C[0][0];
	REP (i, M) amax(x, C[i][0]);
	CP.push_back(Point(x, 0));
    }
    

    sort(AP.begin(), AP.end());
    CP = convex_hull(CP);

    N = AP.size();
    M = CP.size();

    int s = 0;
    for (; s < M; s++) if (CP[s] == Point(0, 0)) break;
    s = s - 1;
    vector<Point> P;
    REP (i, M-1) {
	if (s < 0) s += M;
	P.push_back(CP[s]);
	s--;
    }
    
    bool in = true;

    s = 0;
    REP (i, N) {
	while (s < (int)P.size() && P[s].real() <= AP[i].real()) s++;
	if (s == (int)P.size()) { in = false; break; }

	// P[s-1] ---- P[s]
	if (ccw(P[s-1], AP[i], P[s]) != 1) { in = false; break; }
    }

    puts(in ? "Min" : "Max");
    // EACH (e, P) eprintf("%f %f\n", e->real(), e->imag());
    // if (aa - ca < EPS) puts("Max");
    // else puts("Min");

    return 0;
}