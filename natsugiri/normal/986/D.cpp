#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<complex>
#include<cmath>
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

namespace UNSIGNED_BIG_INTEGER {

struct UnsignedBigInteger {
    static const int EXP;
    static const int BASE;
    static const int SQRT_BASE;
    static const char TO_STRING_FORMAT[];

    static const UnsignedBigInteger ZERO() {
	const UnsignedBigInteger zero(0);
	return zero;
    }
    static const UnsignedBigInteger ONE() {
	const UnsignedBigInteger one(1);
	return one;
    }
    static const UnsignedBigInteger TEN() {
	const UnsignedBigInteger ten(10);
	return ten;
    }


    VI d;

    UnsignedBigInteger() { }

    UnsignedBigInteger(unsigned long long v) {
	while (v) {
	    d.push_back(v % BASE);
	    v /= BASE;
	}
    }

    UnsignedBigInteger(const string &s) {
	int x, r = s.size();
	char buf[30];
	while (r) {
	    int l = max(0, r - EXP);
	    memcpy(buf, s.data() + l, r-l);
	    buf[r-l] = 0;
	    sscanf(buf, "%d", &x);
	    d.push_back(x);
	    r = l;
	}
    }

    string to_string() const {
	if (d.empty()) {
	    return string("0");
	} else {
	    string s;
	    s.reserve(EXP * (int)d.size());
	    char buf[30];
	    sprintf(buf, "%d", d.back());
	    s += buf;
	    for (int i=(int)d.size()-2; i>=0; i--) {
		sprintf(buf, TO_STRING_FORMAT, d[i]);
		s += buf;
	    }
	    return s;
	}
    }

    int cmp(const UnsignedBigInteger &y) const {
	if (d.size() != y.d.size()) {
	    return d.size() < y.d.size()? -1: 1;
	}
	if (d.empty()) {
	    return 0;
	}
	for (int i=d.size(); i--;) {
	    if (d[i] != y.d[i]) {
		return d[i] < y.d[i]? -1: 1;
	    }
	}
	return 0;
    }

    UnsignedBigInteger& operator+=(const UnsignedBigInteger &y) {
	while (d.size() < y.d.size()) d.push_back(0);
	int carry = 0;
	REP (i, y.d.size()) {
	    d[i] += y.d[i] + carry;
	    if (d[i] >= BASE) {
		carry = 1;
		d[i] -= BASE;
	    } else {
		carry = 0;
	    }
	}
	if (carry) d.push_back(carry);
	return *this;
    }

    UnsignedBigInteger& operator-=(const UnsignedBigInteger &y) {
	assert(*this >= y);
	int carry = 0;
	REP (i, y.d.size()) {
	    d[i] -= y.d[i] + carry;
	    if (d[i] < 0) {
		carry = 1;
		d[i] += BASE;
	    } else {
		carry = 0;
	    }
	}
	if (carry) d[y.d.size()] -= carry;
	while (!d.empty() && d.back() == 0) d.pop_back();
	return *this;
    }

    // O(|x||y|)
    UnsignedBigInteger small_mul(const UnsignedBigInteger &y) const;

    // O(|x+y|log|x+y|)
    UnsignedBigInteger large_mul(const UnsignedBigInteger &y) const;

    UnsignedBigInteger pow(unsigned long long y) const {
	UnsignedBigInteger s(*this), r = ONE();
	while (1) {
	    if (y&1) r = r.large_mul(s);
	    y >>= 1;
	    if (y == 0) break;
	    s = s.large_mul(s);
	}
	return r;
    }

    // log10(x) == first == second : when first == second;
    // first < log10(x) < second : otherwise;
    pair<int, int> log10() const;

    pair<int, int> log_base(int base) const;

    friend bool operator<(const UnsignedBigInteger &x, const UnsignedBigInteger &y) {
	return x.cmp(y) < 0;
    }
    friend bool operator<=(const UnsignedBigInteger &x, const UnsignedBigInteger &y) {
	return x.cmp(y) <= 0;
    }
    friend bool operator>(const UnsignedBigInteger &x, const UnsignedBigInteger &y) {
	return x.cmp(y) > 0;
    }
    friend bool operator>=(const UnsignedBigInteger &x, const UnsignedBigInteger &y) {
	return x.cmp(y) >= 0;
    }
    friend bool operator==(const UnsignedBigInteger &x, const UnsignedBigInteger &y) {
	return x.cmp(y) == 0;
    }
    friend bool operator!=(const UnsignedBigInteger &x, const UnsignedBigInteger &y) {
	return x.cmp(y) != 0;
    }

    friend UnsignedBigInteger operator+(UnsignedBigInteger x, const UnsignedBigInteger &y) {
	return x += y;
    }
    friend UnsignedBigInteger operator-(UnsignedBigInteger x, const UnsignedBigInteger &y) {
	return x -= y;
    }
    friend string to_string(const UnsignedBigInteger &x) {
	return x.to_string();
    }

};

const int UnsignedBigInteger::EXP = 8;
const int UnsignedBigInteger::BASE = 1e8; // 10^EXP;
const int UnsignedBigInteger::SQRT_BASE = 1e4;
const char UnsignedBigInteger::TO_STRING_FORMAT[] = "%08d";

UnsignedBigInteger UnsignedBigInteger::small_mul(const UnsignedBigInteger &y) const {
    if (d.empty() || y.d.empty()) return ZERO();
    int len = d.size() + y.d.size() + 1u;
    vector<LL> t(len);
    REP (i, d.size()) {
	LL carry = 0;
	REP (j, y.d.size()) {
	    t[i+j] += (LL)d[i] * y.d[j] + carry;
	    carry = t[i+j] / BASE;
	    t[i+j] -= carry * BASE;
	}
	for (int j=y.d.size(); carry; j++) {
	    t[i+j] += carry;
	    carry = t[i+j] / BASE;
	    t[i+j] -= carry * BASE;
	}
    }
    while (!t.empty() && t.back() == 0) t.pop_back();
    UnsignedBigInteger z;
    z.d.resize(t.size());
    REP (i, t.size()) z.d[i] = t[i];
    return z;
}


const double PI = acos(-1);

typedef complex<double> Complex;
void dft(Complex *a, int n, bool idft=false) {
    const Complex I(0, -1);
    double theta = (idft ? -2*PI/n : 2*PI/n);
    for (int m=n; m>=2; m>>=1) {
	int mh=m>>1;
	for (int i=0; i<mh; i++) {
	    Complex w=exp(i*theta*I);
	    for (int j=i; j<n; j+=m) {
		int k = j+mh;
		Complex x = a[j]-a[k];
		a[j] += a[k];
		a[k] = w*x;
	    }
	}
	theta *= 2;
    }
    for (int i=0, j=1; j<n-1; j++) {
	for (int k=n/2; k>(i^=k); k/=2);
	if (j<i) swap(a[i], a[j]);
    }
    if (idft) for (int i=0; i<n; i++) a[i] /= n;
}

UnsignedBigInteger UnsignedBigInteger::large_mul(const UnsignedBigInteger &y) const {
    if (d.empty() || y.d.empty()) return ZERO();
    int len = d.size() + y.d.size() + 1;
    int pow2 = 1, k = 0;
    while (pow2 < len) {
	pow2 += pow2;
	k++;
    }
    pow2 += pow2; k++;

    vector<Complex> s(pow2), t(pow2);
    REP (i, d.size()) {
	s[i*2  ].real(d[i] % SQRT_BASE);
	s[i*2+1].real(d[i] / SQRT_BASE);
    }
    REP (i, y.d.size()) {
	s[i*2  ].imag(y.d[i] % SQRT_BASE);
	s[i*2+1].imag(y.d[i] / SQRT_BASE);
    }
    dft(s.data(), pow2);
    REP (i, pow2) {
	int j = pow2-i;
	if (i==0) j = 0;
	double xr = (s[i].real()+s[j].real())/2;
	double xi = (s[i].imag()-s[j].imag())/2;
	double yr = (s[i].imag()+s[j].imag())/2;
	double yi = (-s[i].real()+s[j].real())/2;
	t[i].real(xr*yr-xi*yi);
	t[i].imag(xr*yi+xi*yr);
    }
    dft(t.data(), pow2, true);
    LL carry = 0;
    vector<LL> u(pow2);
    REP (i, pow2) {
	carry += (LL)(t[i].real() + 0.5);
	u[i] = carry % SQRT_BASE;
	carry /= SQRT_BASE;
    }
    UnsignedBigInteger z;
    z.d.resize(len, 0);
    REP (i, len) {
	z.d[i] = u[i*2+1]*SQRT_BASE + u[i*2];
    }
    while (!z.d.empty() && z.d.back() == 0) z.d.pop_back();
    return z;
}

pair<int, int> UnsignedBigInteger::log10() const {
    if (d.empty()) return make_pair(-1, -1);
    if (cmp(ONE()) == 0) return make_pair(0, 0);
    int c = cmp(TEN());
    if (c < 0) return make_pair(0, 1);
    if (c == 0) return make_pair(1, 1);
    int len = ((int)d.size()-1) * EXP;
    int h = d.back(), t = 1;
    while (h>=10) {
	len++;
	h /= 10;
	t *= 10;
    }
    if (d.back() == t && count(d.begin(), d.end()-1, 0) == (int)d.size()-1) {
	return make_pair(len, len);
    } else {
	return make_pair(len, len+1);
    }
}

pair<int, int> UnsignedBigInteger::log_base(int base) const {
    assert(2 <= base);
    pair<int, int> p = log10();
    if (base == 10 || p.second <= 0) return p;
    int u = p.first / std::log10(base);
    UnsignedBigInteger tmp = UnsignedBigInteger(base).pow(u);
    int c = cmp(tmp);
    while (c > 0) {
	tmp = tmp.small_mul(UnsignedBigInteger(base));
	u++;
	c = cmp(tmp);
    }
    if (c == 0) return make_pair(u, u);
    else return make_pair(u-1, u);
}

}; // namespace;

typedef UNSIGNED_BIG_INTEGER::UnsignedBigInteger UnsignedBigInteger;

string S;

void MAIN() {
    cin >> S;
    int ans;
    if (S == "1") {
	ans = 1;
    } else if (S == "2") {
	ans = 2;
    } else {
	UnsignedBigInteger u(S);
	pair<int, int> p = u.log_base(3);
	if (p.first == p.second) {
	    ans = 3 * p.first;
	} else {
	    UnsignedBigInteger x = UnsignedBigInteger(3).pow(p.first-1);
	    UnsignedBigInteger y = x.small_mul(3);
	    if ((x+y).cmp(u) >= 0) {
		// 4 * 3^(f-1);
		ans = 3 * p.first + 1;
	    } else if ((y+y).cmp(u) >= 0) {
		// 2 * 3^f;
		ans = 3 * p.first + 2;
	    } else {
		// 3^(f+1);
		ans = 3 * p.first + 3;
	    }
	}
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}