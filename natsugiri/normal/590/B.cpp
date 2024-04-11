#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<complex>
using namespace std;

const double EPS = 1e-8; // 0 ~~ [-EPS, EPS]
// const LL EPS = 0;
const double INF = 1e12;
const double PI = acos(-1);

typedef double Double;
typedef complex<Double> Point;
const Point I(0, 1);

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int main() {
    double x1, y1, x2, y2;
    double v, t;
    double vx, vy, wx, wy;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    scanf("%lf%lf%lf%lf%lf%lf", &v, &t, &vx, &vy, &wx, &wy);

    Point S(x1, y1), G(x2, y2);
    Point V(vx, vy), W(wx, wy);
    double lo = 0, hi = 1e12;

    REP (_, 10000) {
	double m = (lo + hi) / 2;
	bool ok = false;
	if (m <= t) {
	    if (abs((S + V*m) - G) <= v*m) ok = true;
	} else {
	    if (abs((S + V*t) - (G - W*(m-t))) <= v*m) ok = true;
	}
	
	if (ok) hi = m;
	else lo = m;
    }
    
    printf("%.9f\n", (lo + hi) / 2);
    return 0;
}