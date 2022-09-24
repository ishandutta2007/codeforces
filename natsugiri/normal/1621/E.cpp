#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)
template<class T> struct Rational {
    T nu, de;

    Rational() : nu(0), de(1) {}
    // Rational(const Rational &y) : nu(y.nu), de(y.de) {}
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

//    string to_repeatin_decimal_string() const {
//	string ret = to_string(nu / de);
//	nu %= de;
//	if (nu) {
//	    ret.push_back('.');
//	    set<LL> se;
//	    vector<LL> w;
//	    while (1) {
//		if (se.find(nu) != se.end()) break;
//		se.insert(nu);
//		w.push_back(nu);
//		nu = nu * 10 % de;
//	    }
//	    if (nu == 0 && w.back() == nu) {
//		REP (i, (int)w.size()-1) ret.push_back(w[i]*10 / de + '0');
//	    } else {
//		REP (i, w.size()) {
//		    if (w[i] == nu) ret.push_back('(');
//		    ret.push_back(w[i]*10 / de + '0');
//		}
//		ret.push_back(')');
//	    }
//	}
//	return ret;
//    }

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

using Rat = Rational<__int128>;

int N;
int M;
LL A[100011];
VI G[100011];

LL total[100011];
Rat ave[100011];

int stay[100011];
int lshift[100011];
int rshift[100011];
int acc_stay[100011];
int acc_lshift[100011];
int acc_rshift[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%lld", A+i);

    REP (i, M) {
	G[i].clear();
	int k;
	scanf("%d", &k);
	REP (j, k) {
	    int x;
	    scanf("%d", &x);
	    G[i].push_back(x);
	}
    }

    sort(A, A+N);
    reverse(A, A+N);
    reverse(A, A+M);

    REP (i, M) {
	LL s = 0;
	EACH (e, G[i]) s += *e;
	total[i] = s;
	ave[i] = Rat(s, G[i].size());

    }

    sort(ave, ave+M);

    REP (i, M) {
	stay[i] = (ave[i] > Rat(A[i], 1));

	if (i) lshift[i] = (ave[i] > Rat(A[i-1], 1));
	rshift[i] = (ave[i] > Rat(A[i+1], 1));
    }

    REP (i, M) {
	acc_stay[i+1] = acc_stay[i] + stay[i];
	acc_lshift[i+1] = acc_lshift[i] + lshift[i];
	acc_rshift[i+1] = acc_rshift[i] + rshift[i];
    }

    string ans;
    REP (i, M) {
	Rat cur(total[i], G[i].size());
	int from = lower_bound(ave, ave+M, cur) - ave;
	assert(ave[from] == cur);

	EACH (e, G[i]) {
	    Rat nxt(total[i] - *e, G[i].size() - 1u);

	    int to = lower_bound(ave, ave+M, nxt) - ave;

	    bool yes = true;
	    if (from < to) {
		// [0, from) [from] [from+1, to) [to, M);
		// [0, from) [from+1, to) [] [to, M);
		if (acc_stay[from]) yes = false;
		if (acc_lshift[to] - acc_lshift[from+1]) yes = false;
		if (nxt > Rat(A[to-1], 1)) yes = false;
		if (acc_stay[M] - acc_stay[to]) yes = false;
	    } else {
		// [0, to) [to, from) [from] [from+1, M);
		// [0, to) [] [to, from) [from+1, M);
		if (acc_stay[to]) yes = false;
		if (nxt > Rat(A[to], 1)) yes = false;
		if (acc_rshift[from] - acc_rshift[to]) yes = false;
		if (acc_stay[M] - acc_stay[from+1]) yes = false;
	    }

	    ans.push_back(yes? '1': '0');
	}
    }
    puts(ans.c_str());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}