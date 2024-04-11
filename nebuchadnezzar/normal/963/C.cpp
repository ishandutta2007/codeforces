#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

struct big_integer {
private:
    std::vector<uint32_t> number;
    void normalize();
    void negate();
    
public:
    big_integer();
    big_integer(int num);
    big_integer(ll num);
    big_integer(uint32_t num);
    big_integer(std::vector<uint32_t> const& _number);
    explicit big_integer(std::string const& s);

    ~big_integer();
    
    big_integer(big_integer const& other);

    void print() const;

    bool get_sign() const;

    size_t size() const;
    
    uint32_t operator[](size_t pos) const;

    big_integer& operator=(big_integer const& other);

    big_integer& operator+=(big_integer const& rhs);
    big_integer& operator-=(big_integer const& rhs);
    big_integer& operator*=(big_integer const& rhs);
    big_integer& operator/=(big_integer const& rhs);
    big_integer& operator%=(big_integer const& rhs);

    big_integer& operator&=(big_integer const& rhs);
    big_integer& operator|=(big_integer const& rhs);
    big_integer& operator^=(big_integer const& rhs);

    big_integer& operator<<=(int rhs);
    big_integer& operator>>=(int rhs);

    big_integer operator+() const;
    big_integer operator-() const;
    big_integer operator~() const;

    big_integer& operator++();
    big_integer operator++(int);
    big_integer& operator--();
    big_integer operator--(int);

    friend bool operator==(big_integer const& a, big_integer const& b);
    friend bool operator!=(big_integer const& a, big_integer const& b);
    friend bool operator<(big_integer const& a, big_integer const& b);
    friend bool operator>(big_integer const& a, big_integer const& b);
    friend bool operator<=(big_integer const& a, big_integer const& b);
    friend bool operator>=(big_integer const& a, big_integer const& b);

    friend std::string to_string(big_integer const& a);
};

bool operator==(big_integer const& num1, big_integer const& num2);
bool operator!=(big_integer const& a, big_integer const& b);
bool operator<(big_integer const& num1, big_integer const& num2);
bool operator>(big_integer const& num1, big_integer const& num2);
bool operator<=(big_integer const& num1, big_integer const& num2);
bool operator>=(big_integer const& num1, big_integer const& num2);

big_integer operator+(big_integer num1, big_integer const& num2);
big_integer operator-(big_integer num1, big_integer const& num2);
big_integer operator*(big_integer a, big_integer const& b);
big_integer operator/(big_integer a, big_integer const& b);
big_integer operator%(big_integer a, big_integer const& b);

big_integer operator&(big_integer num1, big_integer const& num2);
big_integer operator|(big_integer num1, big_integer const& num2);
big_integer operator^(big_integer num1, big_integer const& num2);

big_integer operator<<(big_integer a, int b);
big_integer operator>>(big_integer a, int b);

std::string to_string(big_integer const& a);
std::ostream& operator<<(std::ostream& s, big_integer const& a);

const big_integer TEN(10), ZERO(0);
const uint64_t MASK = (((uint64_t) 1 << 32) - 1);

void big_integer::normalize() {
    //assert(number.back() == 0 || number.back() == MASK);
    while (number.size() > 1 && number[number.size() - 2] == number.back()) {
        number.pop_back();
    }
}

void big_integer::negate() {
    for (auto& num: number) {
        num = ~num;
    }
    operator+=(big_integer(1));
}

big_integer::big_integer() {
    number = {0};
}

big_integer::big_integer(int num) {
    number = {(uint32_t) num};
    if (num > 0) {
        number.push_back(0);
    }
    if (num < 0) {
        number.push_back((uint32_t) -1);
    }
    normalize();
}

big_integer::big_integer(ll num) {
    number = {(uint32_t) num, (uint32_t) (num >> 32)};
    if (num > 0) {
        number.push_back(0);
    }
    if (num < 0) {
        number.push_back((uint32_t) -1);
    }
    normalize();
}

big_integer::big_integer(uint32_t num) {
    number = {num, 0};
}

big_integer::big_integer(std::vector<uint32_t> const& _number) {
    number = _number;
    while (number.size() > 1 && number[number.size() - 2] == number.back()) {
        number.pop_back();
    }
}

big_integer::big_integer(std::string const& s) {
    number = {0};
    big_integer tp(1);
    bool sign = 0;
    if (s[0] == '-') {
        sign = 1;
    }
    
    for (size_t i = s.size() - 1; ~i; --i) {
        if ('0' <= s[i] && s[i] <= '9') {
            operator+=(tp * big_integer(s[i] - '0'));
            tp *= TEN;
        }
    }

    if (sign) {
        negate();
    }
}

big_integer::~big_integer() {
}

big_integer::big_integer(big_integer const& other) {
    number = other.number;
}

void big_integer::print() const {
    for (auto num: number) {
        std::cerr << num << " ";
    }
    std::cerr << std::endl;
}

bool big_integer::get_sign() const {
    return number.back();
}

size_t big_integer::size() const {
    return number.size();
}

uint32_t big_integer::operator[](size_t pos) const {
    //assert(number.size());
    return number[std::min(pos, number.size() - 1)];
}

big_integer& big_integer::operator=(big_integer const& other) {
    number = other.number;
    return *this;
}

big_integer& big_integer::operator+=(big_integer const& rhs) {
    std::vector<uint32_t> v;
    size_t c = 0;
    uint64_t now = 0;
    while (c <= size() || c <= rhs.size()) {
        now += operator[](c);
        now += rhs[c];
        v.push_back(now & MASK);
        now >>= 32;
        ++c;
    }
    number = v;
    normalize();
    return *this;
}

big_integer& big_integer::operator-=(big_integer const& rhs) {
    std::vector<uint32_t> v;
    size_t c = 0;
    uint64_t now = 0;
    while (c <= size() || c <= rhs.size()) {
        now += rhs[c];
        v.push_back(operator[](c) - now);
        if (operator[](c) >= now) {
            now = 0;
        } else {
            now = 1;
        }
        ++c;
    }
    number = v;
    normalize();
    return *this;
}

big_integer& big_integer::operator*=(big_integer const& rhs) {
    bool sign = get_sign() ^ rhs.get_sign();
    big_integer a = *this;
    if (a.get_sign() == 1) {
        a.negate();
    }
    big_integer b = rhs;
    if (b.get_sign() == 1) {
        b.negate();
    }

    std::vector<std::pair<uint64_t, uint64_t>> v(size() + rhs.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < b.size(); ++j) {
            uint64_t tmp = (uint64_t) a[i] * b[j];
            v[i + j].first += tmp & (((uint64_t) 1 << 32 ) - 1);
            if (i + j + 1 < v.size()) {
                v[i + j + 1].second += tmp >> 32;
            }
        }
    }
    number = std::vector<uint32_t>();
    uint64_t now = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        now += v[i].first;
        now += v[i].second;
        number.push_back(now & MASK);
        now >>= 32;
    }
    normalize();
    if (sign) {
        negate();
    }
    return *this;
}

big_integer& big_integer::operator/=(big_integer const& rhs) {
    bool sign = get_sign() ^ rhs.get_sign();
    if (get_sign() == 1) {
        negate();
    }
    big_integer b = rhs;
    if (b.get_sign() == 1) {
        b.negate();
    }
    
    if (*this < b) {
        number = {0};
        return *this;
    }

    std::vector<uint32_t> v(size() - b.size() + 2);
    for (size_t i = size() - b.size(); ~i; --i) {
        uint64_t l = 0, r = (uint64_t) 1 << 32;
        while (r - l > 1) {
            uint32_t mid = l + (r - l) / 2;
            
            uint64_t now = 0;
            bool flag = true;
            for (size_t j = 0; j < b.size(); ++j) {
                now += (uint64_t) b[j] * mid;
                if ((now & MASK) != number[i + j]) {
                    flag = (number[i + j] > (now & MASK));
                }
                now >>= 32;
            }

            if (flag) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        uint64_t now = 0, nowd = 0;
        for (size_t j = 0; j < b.size(); ++j) {
            now += (uint64_t) b[j] * l;
            nowd += now & MASK;
            now >>= 32;
            if (nowd <= number[i + j]) {
                number[i + j] -= nowd;
                nowd = 0;
            } else {
                number[i + j] -= nowd;
                nowd = 1;
            }
        }
        v[i] = l;
    }

    number = v;
    normalize();
    if (sign) {
        negate();
    }
    return *this;
}

big_integer& big_integer::operator%=(big_integer const& rhs) {
    bool sign = get_sign();
    if (get_sign() == 1) {
        negate();
    }
    big_integer b = rhs;
    if (b.get_sign() == 1) {
        b.negate();
    }
    
    if (*this < b) {
        return *this;
    }

    for (size_t i = size() - b.size(); ~i; --i) {
        uint64_t l = 0, r = (uint64_t) 1 << 32;
        while (r - l > 1) {
            uint32_t mid = l + (r - l) / 2;
            
            uint64_t now = 0;
            bool flag = true;
            for (size_t j = 0; j < b.size(); ++j) {
                now += (uint64_t) b[j] * mid;
                //prod[j] = now & MASK;
                if ((now & MASK) != number[i + j]) {
                    flag = (number[i + j] > (now & MASK));
                }
                now >>= 32;
            }

            if (flag) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        uint64_t now = 0, nowd = 0;
        for (size_t j = 0; j < b.size(); ++j) {
            now += (uint64_t) b[j] * l;
            nowd += now & MASK;
            now >>= 32;
            if (nowd <= number[i + j]) {
                number[i + j] -= nowd;
                nowd = 0;
            } else {
                number[i + j] -= nowd;
                nowd = 1;
            }
        }
    }

    normalize();
    if (sign) {
        negate();
    }
    return *this;
}

big_integer& big_integer::operator&=(big_integer const& rhs) {
    std::vector<uint32_t> v;
    size_t c = 0;
    while (c <= size() || c <= rhs.size()) {
        v.push_back(operator[](c) & rhs[c]);
        ++c;
    }
    number = v;
    normalize();
    return *this;
}

big_integer& big_integer::operator|=(big_integer const& rhs) {
    std::vector<uint32_t> v;
    size_t c = 0;
    while (c <= size() || c <= rhs.size()) {
        v.push_back(operator[](c) | rhs[c]);
        ++c;
    }
    number = v;
    normalize();
    return *this;
}

big_integer& big_integer::operator^=(big_integer const& rhs) {
    std::vector<uint32_t> v;
    size_t c = 0;
    while (c <= size() || c <= rhs.size()) {
        v.push_back(operator[](c) ^ rhs[c]);
        ++c;
    }
    number = v;
    normalize();
    return *this;
}

big_integer& big_integer::operator<<=(int rhs) {
    int d = rhs % 32;
    int tot = rhs / 32;
    std::vector<uint32_t> v;
    for (int i = 0; i < tot; ++i) {
        v.push_back(0);
    }
    size_t c = 0;
    uint32_t prev = 0;
    while (c <= size()) {
        uint32_t tmp = (operator[](c) << d) | prev;
        v.push_back(tmp);
        prev = operator[](c) >> (32 - d);
        ++c;
    }
    number = v;
    normalize();
    return *this;
}

big_integer& big_integer::operator>>=(int rhs) {
    int d = rhs % 32;
    int tot = rhs / 32;
    std::vector<uint32_t> v;
    size_t c = tot;
    do {
        uint32_t tmp = (operator[](c) >> d) | (operator[](c + 1) << (32 - d));
        v.push_back(tmp);
        ++c;
    } while (c <= size() + 1);
    number = v;
    normalize();
    return *this;
}

big_integer big_integer::operator+() const {
    big_integer ret = *this;
    return ret;
}

big_integer big_integer::operator-() const {
    big_integer ret = *this;
    ret.negate();
    return ret;
}

big_integer big_integer::operator~() const {
    std::vector<uint32_t> v;
    for (size_t i = 0; i < size(); ++i) {
        v.push_back(~number[i]);
    }
    return big_integer(v);
}

big_integer& big_integer::operator++() {
    operator+=(big_integer(1));
    return *this;
}

big_integer big_integer::operator++(int) {
    big_integer ret = *this;
    operator+=(big_integer(1));
    return ret;
}

big_integer& big_integer::operator--() {
    operator-=(big_integer(1));
    return *this;
}

big_integer big_integer::operator--(int) {
    big_integer ret = *this;
    operator-=(big_integer(1));
    return ret;
}



bool operator==(big_integer const& a, big_integer const& b) {
    return a.number == b.number;
}

bool operator!=(big_integer const& a, big_integer const& b) {
    return a.number != b.number;
}

bool operator<(big_integer const& a, big_integer const& b) {
    if (a.get_sign() != b.get_sign()) {
        return a.get_sign() > b.get_sign();
    }
    
    if (a.number.size() != b.number.size()) {
        return a.number.size() < b.number.size();
    }

    for (size_t i = a.number.size() - 1; ~i; --i) {
        if (a.number[i] != b.number[i]) {
            return a.number[i] < b.number[i];
        }
    }
    return false;
}

bool operator>(big_integer const& a, big_integer const& b) {
    return !(a == b || a < b);
}

bool operator<=(big_integer const& a, big_integer const& b) {
    return a == b || a < b;
}

bool operator>=(big_integer const& a, big_integer const& b) {
    return a == b || a > b;
}

big_integer operator+(big_integer a, big_integer const& b) {
    return a += b;
}

big_integer operator-(big_integer a, big_integer const& b) {
    return a -= b;
}

big_integer operator*(big_integer a, big_integer const& b) {
    return a *= b;
}

big_integer operator/(big_integer a, big_integer const& b) {
    return a /= b;
}

big_integer operator%(big_integer a, big_integer const& b) {
    return a %= b;
}

big_integer operator&(big_integer a, big_integer const& b) {
    return a &= b;
}

big_integer operator|(big_integer a, big_integer const& b) {
    return a |= b;
}

big_integer operator^(big_integer a, big_integer const& b) {
    return a ^= b;
}

big_integer operator<<(big_integer a, int b) {
    return a <<= b;
}
big_integer operator>>(big_integer a, int b) {
    return a >>= b;
}

std::string to_string(big_integer const& a) {
    big_integer tmp = a;
    std::string ret = "";
    bool sign = 0;
    if (tmp < ZERO) {
        tmp = -tmp;
        sign = 1;
    }
    while (tmp > ZERO) {
        big_integer dig = tmp % TEN;
        ret += '0' + dig[0];
        tmp /= TEN;
    }
    if (ret.size() == 0) {
        ret = "0";
    }
    if (sign) {
        ret += '-';
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

std::ostream& operator<<(std::ostream& s, big_integer const& a) {
    s << to_string(a);
    return s;
}

big_integer gcd(big_integer a, big_integer b) {
	while (b != ZERO) {
		a %= b;
		swap(a, b);
	}
	return a;
}


void solve() {
	/*
	for (int i = 0; i < 100; ++i) {
		ll tmp = rnd(0, INFL);
		assert(stoll(to_string(big_integer(tmp))) == tmp);
	}
	*/

	int n;
	cin >> n;
	map<ll, ll> have_h, have_w;
	map<ll, vector<ll>> diffs;
	vector<tuple<ll, ll, ll>> inp;
	ll sumc = 0;
	map<pll, ll> have;
	for (int i = 0; i < n; ++i) {
		ll w, h, c;
		cin >> w >> h >> c;
		have[{w, h}] = c;
		have_w[w] += c;
		have_h[h] += c;
		inp.push_back({w, h, c});
		sumc += c;
	}

	if ((ll) szof(have_h) * (ll) szof(have_w) > n) {
		cout << "0\n";
		return;
	}


	big_integer tmppq;
	for (auto p1 : have_w) {
		for (auto p2 : have_h) {
			if (!have.count({p1.ff, p2.ff}) || big_integer(p1.ss) * big_integer(p2.ss) % big_integer(have[{p1.ff, p2.ff}]) != ZERO) {
				cout << "0\n";
				return;
			}

			tmppq = gcd(big_integer(p1.ss) * big_integer(p2.ss) / big_integer(have[{p1.ff, p2.ff}]), tmppq);
		}
	}

	ll tmp = 0;
	for (auto p : have_h) {
		tmp = __gcd(tmp, p.ss);
	}

	ll tmpq = 0;
	for (auto p : have_w) {
		tmpq = __gcd(tmpq, p.ss);
	}

	int ans = 0;
	for (ll p = 1; p * p <= tmp; ++p) {
		if (tmp % p == 0) {
			if (sumc % p == 0) {
				ll q = sumc / p;
				if (tmpq % q == 0 && tmppq % (big_integer(p) * big_integer(q)) == ZERO) {
					++ans;
				}
			}

			if (p * p != tmp) {
				ll np = tmp / p;
				if (sumc % np == 0) {
					ll q = sumc / np;
					if (tmpq % q == 0 && tmppq % (big_integer(np) * big_integer(q)) == ZERO) {
						++ans;
					}
				}
			}
		}
	}

	cout << ans << "\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}