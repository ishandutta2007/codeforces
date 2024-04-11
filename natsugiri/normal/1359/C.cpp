#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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

template<class T> struct Rational {
    T nu, de;

    Rational() : nu(0), de(1) {}
    Rational(const Rational &y) : nu(y.nu), de(y.de) {}
    Rational(const T &nu_, const T &de_) : nu(nu_), de(de_) { normalize(); }

    Rational &operator+=(const Rational &y) {
	nu = nu * y.de + de * y.nu; de = de * y.de; normalize();
	return *this;
    }
    Rational &operator-=(const Rational &y) {
	nu = nu * y.de - de * y.nu; de = de * y.de; normalize();
	return *this;
    }
    Rational &operator*=(const Rational &y) {
	nu *= y.nu; de *= y.de; normalize();
	return *this;
    }
    Rational &operator/=(const Rational &y) {
	nu *= y.de; de *= y.nu; normalize();
	return *this;
    }

    string to_string() const {
	return std::to_string(nu) + "/" + std::to_string(de);
    }

    friend bool operator<(const Rational &x, const Rational &y) { return x.nu * y.de < y.nu * x.de; }
    friend bool operator>(const Rational &x, const Rational &y) { return y<x; }
    friend bool operator<=(const Rational &x, const Rational &y) { return !(y<x); }
    friend bool operator>=(const Rational &x, const Rational &y) { return !(x<y); }
    friend bool operator==(const Rational &x, const Rational &y) { return x.nu == y.nu && x.de == y.de; }
    friend bool operator!=(const Rational &x, const Rational &y) { return !(x==y); }
    friend Rational operator+(Rational x, const Rational &y) { return x+=y; }
    friend Rational operator-(Rational x, const Rational &y) { return x-=y; }
    friend Rational operator*(Rational x, const Rational &y) { return x*=y; }
    friend Rational operator/(Rational x, const Rational &y) { return x/=y; }
    friend Rational operator-(Rational x) { x.nu = -x.nu; return x; }

    friend ostream& operator<<(ostream&os, const Rational&x) {
	os << x.to_string();
	return os;
    }
    friend string to_string(const Rational &x) { return x.to_string(); }

    static Rational approx_from(double x, const T &de_limit) {
	if (x == 0) { return Rational(); }
	int i, s = 1;
	if (x < 0) { s = -1; x = -x; }
	vector<T> g(2), h(2);
	g[1] = h[0] = 1;
	for (i=2; ; i++) {
	    T a = x;
	    g.push_back(a * g[i-1] + g[i-2]);
	    h.push_back(a * h[i-1] + h[i-2]);
	    if (h[i] > de_limit) break;
	    if (x == (double)a) { i++; break; }
	    x = 1 / (x - a);
	}
	return Rational(s*g[i-1], h[i-1]);
    }

    static Rational approx_from(LL nu, LL de, const T &de_limit) {
	if (nu == 0) { return Rational(); }
	int i, s = 1;
	if (de < 0) { nu = -nu; de = -de; }
	if (nu < 0) { s = -1; nu = -nu; }
	vector<T> g(2), h(2);
	g[1] = h[0] = 1;
	for (i=2; ; i++) {
	    T a = nu / de;
	    g.push_back(a * g[i-1] + g[i-2]);
	    h.push_back(a * h[i-1] + h[i-2]);
	    if (h[i] > de_limit) break;
	    if (nu % de == 0) { i++; break; }
	    LL tmp = de; de = nu - de * a; nu = tmp;
	}
	return Rational(s*g[i-1], h[i-1]);
    }

    // S := X.Y(Z);
    // pow(10, Y.size()) * (pow(10, Z.size())-1) * S == XYZ - XY;
    static Rational from_repeating_decimal(const string &X, const string &Y, const string &Z) {
	LL nu = (X.empty()? 0LL: stoll(X));
	LL de = 1;
	if (Y.size()) {
	    REP (i, Y.size()) {
		de *= 10;
		nu *= 10;
	    }
	    nu += stoll(Y);
	}
	if (Z.size()) {
	    LL ten = 1;
	    REP (i, Z.size()) ten *= 10;
	    nu = nu * (ten - 1) + stoll(Z);
	    de = de * (ten - 1);
	}
	return Rational(nu, de);
    }

    // s: X.Y(Z);
    // 123, 123.456, 1.23(45), .(123);
    static Rational from_repeating_decimal(const string &s) {
	int dot = s.find('.');
	if (dot == -1) return Rational(stoll(s), 1);
	string X = s.substr(0, dot);
	int left = s.find('(');
	string Y, Z;
	if (left == -1) {
	    Y = s.substr(dot+1);
	} else {
	    Y = s.substr(dot+1, left-dot-1);
	    Z = s.substr(left+1, (int)s.size()-left-2);
	}
	return from_repeating_decimal(X, Y, Z);
    }

    static int safe_compare(Rational a, Rational b) {
	return safe_compare(a.nu, a.de, b.nu, b.de);
    }

    static int safe_compare(T nu0, T de0, T nu1, T de1) {
	// returns nu0 / de0 <=> nu1 / de1;
	assert(de0 != 0);
	assert(de1 != 0);
	if (nu0 == 0 && nu1 == 0) return 0;
	if (de0 < 0) { nu0 = -nu0; de0 = -de0; }
	if (de1 < 0) { nu1 = -nu1; de1 = -de1; }
	if (nu0 <= 0 && 0 <= nu1) return -1;
	if (nu1 <= 0 && 0 <= nu0) return 1;
	int sgn = 1;
	if (nu0 < 0) {
	    sgn = -1;
	    nu0 = -nu0;
	    nu1 = -nu1;
	}
	while (de0 != 0 && de1 != 0) {
	    T q0 = nu0 / de0, q1 = nu1 / de1;
	    if (q0 != q1) return q0 < q1? -sgn: sgn;
	    q0 = nu0-q0*de0; nu0 = de0; de0 = q0;
	    q1 = nu1-q1*de1; nu1 = de1; de1 = q1;
	    sgn = -sgn;
	}
	if (de0 == 0 && de1 == 0) return 0;
	return de0 == 0? sgn: -sgn;
    }



private:
    inline void normalize() {
	if (nu == 0) {
	    de = 1;
	} else {
	    if (de < 0) nu = -nu, de = -de;
	    T g = gcd(nu < 0? -nu: nu, de);
	    nu /= g;
	    de /= g;
	}
    }

    static T gcd(T x, T y) {
	while (1) {
	    if (y != 0) x %= y; else return x;
	    if (x != 0) y %= x; else return y;
	}
    }
};

using Rat = Rational<LL>;

LL H, C, T;

bool ok(LL k) {
    return k*H+H+k*C >= T * (2*k+1);
}

void MAIN() {
    scanf("%lld%lld%lld", &H, &C, &T);

    Rat a(H, 1);
    LL ans = 1;
    Rat t(T, 1);
    a -= t;
    if (a.nu < 0) a = -a;

    auto update = [&](const LL num) {
	Rat b;
	if (num % 2 == 0) {
	    b = Rat(H+C, 2);
	} else {
	    int k = num / 2;
	    b = Rat(H*k + H + C*k, num);
	}
	b -= t;
	if (b.nu < 0) b = -b;
	int cmp = Rat::safe_compare(a, b);

	if (cmp > 0 || (cmp == 0 && ans > num)) {
	    ans = num;
	    a = b;
	}
    };

    update(2);
    
    if (H+C < T*2) {
	LL lo = 1, hi = 2;
	while (ok(hi)) {
	    lo = hi;
	    hi += hi;
	}
	while (hi - lo > 1) {
	    LL mid = (lo + hi) / 2;
	    (ok(mid)? lo: hi) = mid;
	}
	// eprintf("%lld %d %f\n", lo, ok(lo), (H*lo+H+C*lo+0.0) / (2.0*lo+1.0));
	// eprintf("%lld %d %f\n", hi, ok(hi), (H*hi+H+C*hi+0.0) / (2.0*hi+1.0));
	update(lo*2+1);
	update(hi*2+1);
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}