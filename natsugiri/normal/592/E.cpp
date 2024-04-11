#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<complex>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

typedef long long Double;
typedef complex<Double> Point;
const Point I(0, 1);
const Double EPS = 0;

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

struct CMP_ARG {
    bool operator()(const Point &x, const Point &y) const {
	return sign(cross(x, y)) == 1;
    }
} cmp_arg;
bool cmp_arg_2(const Point &x, const Point &y) {
    if(x.imag() == 0 && x.real() == 0) while(1);
    if(y.imag() == 0 && y.real() == 0) while(1);

    return arg(complex<double>(x.real(), x.imag())) <
	arg(complex<double>(y.real(), y.imag()));
}

int N;
LL C_sub, D_sub;
LL R[400011], W[400011];

vector<Point> U, D;
LL pos, neg;

int main() {
    
    scanf("%d%lld%lld", &N, &C_sub, &D_sub);
    assert(N <= 345678);
    REP (i, N) {
	scanf("%lld%lld", R+i, W+i);
	R[i] -= C_sub;
	W[i] -= D_sub;
    }

    {
	vector<Point> v;
	REP (i, N) v.push_back(Point(R[i], W[i]));
	EACH (e, v) assert(abs(e->real()) + abs(e->imag()) > 0LL);
	
	sort(v.begin(), v.end(), cmp_arg);
	cerr << v.back() << endl;
    }

    
    REP (i, N) {
	if (W[i] > 0) U.push_back(Point(R[i], W[i]));
	else if (W[i] < 0) D.push_back(Point(R[i], W[i]));
	else if (R[i] > 0) pos++;
	else neg++;
    }

    sort(U.begin(), U.end(), cmp_arg);
    sort(D.begin(), D.end(), cmp_arg);

    LL ans = 0;
    for (LL i=0, lo=0, hi=0; i<(int)U.size(); i++) {
	while (hi < (int)D.size() && cross(U[i], D[hi]) >= 0) hi++;
	while (lo < (int)D.size() && cross(U[i], D[lo]) > 0) lo++;

	ans += lo * ((LL)D.size() - hi);
	ans += neg * ((LL)D.size() - hi);
	ans += lo * pos;
    }
    for (LL i=0, lo=0, hi=0; i<(int)D.size(); i++) {
	while (hi < (int)U.size() && cross(D[i], U[hi]) >= 0) hi++;
	while (lo < (int)U.size() && cross(D[i], U[lo]) > 0) lo++;

	ans += lo * ((LL)U.size() - hi);
    }

    // REP (k, N) REP (j, N) REP (i, min(j, k)) {
    // 	if (i != j && j != k && k != i &&
    // 	    R[i] * W[j] > R[j] * W[i] &&
    // 	    R[j] * W[k] > R[k] * W[j] &&
    // 	    R[k] * W[i] > R[i] * W[k]) {
    // 	    printf("%d %d %d\n", i+1, j+1, k+1);
    // 	    Point I(R[i], W[i]), J(R[j], W[j]), K(R[k], W[k]);
    // 	    cerr << I << " " << J << " " << K << endl;
    // 	    cerr << cross(I, J) << " " << cross(J, K) << " " << cross(K, I) << endl;
    // 	}
    // }

    printf("%lld\n", ans);
    return 0;
}